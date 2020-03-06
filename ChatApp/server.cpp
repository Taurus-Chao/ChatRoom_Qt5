#include "server.h"
#include "ui_server.h"
#include<QFile>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    setFixedSize(400,207);
    tPort=5555;
    tSrv=new QTcpServer(this);
    connect(tSrv,SIGNAL(newConnection()),this,SLOT(sndMsg()));
    initSrv();
}

Server::~Server()
{
    delete ui;
}

void Server::initSrv()
{
    payloadSize=64*1024;
    totalBytes=0;
    bytesWritten=0;
    bytesTobeWrite=0;
    
    ui->sStatusLbl->setText(tr("请选择要传送的文件"));
    ui->progressBar->reset();
    ui->sOpenBtn->setEnabled(true);
    ui->sSendBtn->setEnabled(false);
    
    tSrv->close();
}

void Server::sndMsg()
{
    //只在连接建立成功时执行一次。该函数建立客户端读取反馈信号与udpClntProgress槽的关联，确定好文件大小，并首先向客户端发送一个文件头结构（包含文件名和大小），收到反馈后剩余文件内容的继续发送将在udpClntProgress进行。
    ui->sSendBtn->setEnabled(false);
    clntConn=tSrv->nextPendingConnection();//获得一个tcp连接,clntConn是对方客户端的socket
    connect(clntConn,SIGNAL(bytesWritten(qint64)),this,SLOT(udpClntProgress(qint64)));
    ui->sStatusLbl->setText(tr("开始传输文件 %1 ！").arg(theFileName));
    
    locFile=new QFile(fileName);
    if(!locFile->open((QFile::ReadOnly)))
    {
        QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1：\n%2").arg(fileName).arg(locFile->errorString()));
        return;
    }
    totalBytes=locFile->size();//获取文件大小
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);//将发送缓冲区封装在流变量中，方便用<<操作
    sendOut.setVersion(QDataStream::Qt_4_7);
    time.start(); //统计传输所用时间
    QString curFile=fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);//仅保留文件名到curfile变量
    sendOut<<qint64(0)<<qint64(0)<<curFile;//构造一个临时文件头，完成实际需发送的字节数的记录
    totalBytes+=outBlock.size();
    sendOut.device()->seek(0);//将读写操作指向从头开始
    sendOut<<totalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));//填写实际总长度和文件长度
    bytesTobeWrite=totalBytes-clntConn->write(outBlock);//将文件头发出，同时修改待发送字节数
    outBlock.resize(0);

}

void Server::udpClntProgress(qint64 numBytes)
{
    qApp->processEvents();//在传输大文件时界面不会冻结
    bytesWritten+=(int)numBytes;
    if(bytesTobeWrite>0){
        outBlock=locFile->read(qMin(bytesTobeWrite,payloadSize));//每次读入缓冲区的大小是两者最小值
        bytesTobeWrite-=(int)clntConn->write(outBlock);
        outBlock.resize(0);
    }
    else{
        locFile->close();
    }
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesWritten);
    
    float useTime=time.elapsed();
    double speed=bytesWritten/useTime;
    ui->sStatusLbl->setText(tr("已发送%1MB（%2MB/s）\n共%3MB 已用时：%4秒\n 估计剩余时间：%5秒")
                            .arg(bytesWritten/(1024*1024))
                            .arg(speed*1000/(1024*1024),0,'f',2)
                            .arg(totalBytes/(1024*1024))
                            .arg(useTime/1000,0,'f',0)
                            .arg(totalBytes/speed/1000-useTime/1000,0,'f',0));
    if(bytesWritten==totalBytes){//关闭顺序为：文档->socket
        locFile->close();
        tSrv->close();
        ui->sStatusLbl->setText(tr("传送文件%1成功").arg(theFileName));
    }

}

void Server::on_sOpenBtn_clicked()
{
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        theFileName=fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
        ui->sStatusLbl->setText(tr("要传送的文件为：%1").arg(theFileName));
        ui->sSendBtn->setEnabled(true);
        ui->sOpenBtn->setEnabled(false);
    }
}

void Server::on_sSendBtn_clicked()
{
    ui->sStatusLbl->setText(tr("等待对方接受......"));
    emit sndFileName(theFileName);//发射信号给Widget类，让其通过sndMsg槽函数发送UDP广播文件名给用户
    if(!tSrv->listen(QHostAddress::Any,tPort))//开始监听，收到连接请求后进入sndMsg槽函数建立客户端socket，并向缓冲区写数据。结束后关闭连接
    {
        qDebug()<<tSrv->errorString();
        close();
        return;
    }
}

void Server::on_sCloseBtn_clicked()
{
    if(tSrv->isListening())
    {
        tSrv->close();
        if(locFile->isOpen())
            locFile->close();
        clntConn->abort();
    }
    close();
}

void Server::closeEvent(QCloseEvent *)
{
    on_sCloseBtn_clicked();
}

void Server::refused()
{
    tSrv->close();
    ui->sStatusLbl->setText(tr("对方拒绝接收！"));
}
