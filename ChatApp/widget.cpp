#include "widget.h"
#include "ui_widget.h"
#include<QUdpSocket>
#include<QHostInfo>
#include<QMessageBox>
#include<QScrollBar>
#include<QDateTime>
#include<QNetworkInterface>
#include<QProcess>
#include"qdlglogin.h"
#include<drawer.h>
#include<QTextCodec>
#include"server.h"
#include"client.h"
#include<QFileDialog>
#include<QColorDialog>
Widget::Widget(QWidget *parent,QString usrname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->boldTBtn->setIcon(QPixmap(":/images/bold.png"));
    ui->italicTBtn->setIcon(QPixmap(":/images/italic.png"));
    ui->underlineTBtn->setIcon(QPixmap(":/images/under.png"));
    ui->colorTBtn->setIcon(QPixmap(":/images/color.png"));
    ui->sendTBtn->setIcon(QPixmap(":/images/send.png"));
    ui->saveTBtn->setIcon(QPixmap(":/images/save.png"));
    ui->clearTBtn->setIcon(QPixmap(":/images/clear.png"));

    //每次点击抽屉头像时创建widget，创建绑定一个udpsocket
    uName=usrname;
    udpSocket=new QUdpSocket(this);

    port=23232;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));//数据来的时候交给槽函数处理
    sndMsg(UsrEnter);//UDP向所有用户广播发送UsrEnter类型消息
    this->setAttribute(Qt::WA_DeleteOnClose);

    srv=new Server(this);
    connect(srv,SIGNAL(sndFileName(QString)),this,SLOT(getFileName(QString)));
    connect(ui->msgTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(curFmtChanged(QTextCharFormat)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sndMsg(MsgType type, QString srvaddr)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);//数据流out到data中，只写
    QString address=getIP();//获得本机IP地址
    out<<type<<getUsr();
    //根据不同类型的消息不同处理之后再发送
    switch(type)
    {
    case Msg:
        if(ui->msgTextEdit->toPlainText()=="")
        {
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out<<address<<getMsg();//向发送的数据写入本机IP地址和用户输入文本
        ui->msgBrowser->verticalScrollBar()->setValue(ui->msgBrowser->verticalScrollBar()->maximum());
        break;

    case UsrEnter:
        out<<address;
        break;

    case UsrLeft:
        break;

    case FileName://发送文件名
    {
        int row=ui->usrTblWidget->currentRow();
        QString clntaddr=ui->usrTblWidget->item(row,1)->text();
        out<<address<<clntaddr<<fileName;
        break;
    }

    case Refuse://拒绝接收
        out<<srvaddr;
        break;
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);//向局域网的广播地址指定端口23232发送数据报
}

void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int msgType;
        in>>msgType;//in读取的顺序对应着out写入的顺序
        QString usrName,ipAddr,msg;
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        switch (msgType) {
        case Msg:
            in>>usrName>>ipAddr>>msg;
            ui->msgBrowser->setTextColor(Qt::blue);
            ui->msgBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->msgBrowser->append("["+usrName+"]"+time);
            ui->msgBrowser->append(msg);
            break;

        case UsrEnter:
            in>>usrName>>ipAddr;
            usrEnter(usrName,ipAddr);
            break;

        case UsrLeft:
            in>>usrName;
            usrLeft(usrName,time);
            break;

        case FileName:
        {
            in>>usrName>>ipAddr;
            QString clntAddr,fileName;
            in>>clntAddr>>fileName;
            hasPendingFile(usrName,ipAddr,clntAddr,fileName);//客户端收到文件名UDP后，由用户判断是否接收
            break;
        }

        case Refuse:
        {
            in>>usrName;
            QString srvAddr;
            in>>srvAddr;
            QString ipAddr=getIP();
            if(ipAddr==srvAddr)//接收到拒绝信息时，要先看自己是不是发送端，若是再执行refuse
            {
                srv->refused();
            }
            break;
        }
        }
    }
}

void Widget::usrEnter(QString usrname, QString ipaddr)
{
    bool isEmpty=ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).isEmpty();//在table中寻找是否已有用户信息，没有则添加
    if(isEmpty){
        QTableWidgetItem *usr =new QTableWidgetItem(usrname);
        QTableWidgetItem *ip=new QTableWidgetItem(ipaddr);

        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,usr);
        ui->usrTblWidget->setItem(0,1,ip);
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->setCurrentFont(QFont("Times New Roman",10));
        ui->msgBrowser->append(tr("%1 在线！").arg(usrname));
        ui->usrNumLbl->setText(tr("在线人数：%1").arg(ui->usrTblWidget->rowCount()));

        sndMsg(UsrEnter);//必须告知新加进来的用户自己也在线，否则新用户无法显示已经在线的用户
    }
}

void Widget::usrLeft(QString usrname, QString time)
{
    //从列表中删除离开用户信息
    int rowNum=ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).first()->row();
    ui->usrTblWidget->removeRow(rowNum);
    ui->msgBrowser->setTextColor(Qt::gray);
    ui->msgBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->msgBrowser->append(tr("%1 于 %2 离开！").arg(usrname).arg(time));
    ui->usrNumLbl->setText(tr("在线人数： %1").arg(ui->usrTblWidget->rowCount()));
}

QString Widget::getIP()
{
    QList<QHostAddress>list=QNetworkInterface::allAddresses();
    foreach(QHostAddress addr,list){
        if(addr.protocol()==QAbstractSocket::IPv4Protocol)
            return addr.toString();
    }
    return 0;
}

QString Widget::getUsr()
{
    return uName;
}

QString Widget::getMsg()
{
    QString msg=ui->msgTextEdit->toHtml();

    ui->msgTextEdit->clear();
    ui->msgTextEdit->setFocus();
    return msg;
}

void Widget::on_sendBtn_clicked()
{
    sndMsg(Msg);
}

void Widget::on_exitBtn_clicked()
{
    //sndMsg(UsrLeft);
    this->close();
}

void Widget::getFileName(QString name)
{
    fileName=name;
    sndMsg(FileName);//在主界面类Widget中用UDP广播发送文件名
}


void Widget::on_sendTBtn_clicked()
{
    if(ui->usrTblWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0,tr("选择用户"),tr("请先选择目标用户！"),QMessageBox::Ok);
        return;
    }
    srv->show();
    srv->initSrv();
}

void Widget::hasPendingFile(QString usrname, QString srvaddr, QString clntaddr, QString filename)
{
    QString ipAddr=getIP();
    if(ipAddr==clntaddr)//只有地址匹配了才弹出接收对话框&&usrname!=uName
    {
        int btn=QMessageBox::information(this,tr("接受文件"),tr("来自%1(%2)的文件:%3,是否接收?").arg(usrname).arg(srvaddr).arg(filename),QMessageBox::Yes,QMessageBox::No);
        if(btn==QMessageBox::Yes){
            QString name=QFileDialog::getSaveFileName(0,tr("保存文件"),filename);
            if(!name.isEmpty())
            {
                Client *clnt=new Client(this);
                clnt->setFileName(name);
                clnt->setHostAddr(QHostAddress(srvaddr));
                clnt->show();
            }
        }else{
            sndMsg(Refuse,srvaddr);
        }
    }
}

//字体附加功能
void Widget::on_fontCbx_currentFontChanged(const QFont &f)
{
    ui->msgTextEdit->setCurrentFont(f);
    ui->msgTextEdit->setFocus();
}

void Widget::on_sizeCbx_currentIndexChanged(const QString &arg1)
{
    ui->msgTextEdit->setFontPointSize(arg1.toDouble());
    ui->msgTextEdit->setFocus();
}

void Widget::on_boldTBtn_clicked(bool checked)
{
    if(checked)
        ui->msgTextEdit->setFontWeight(QFont::Bold);
    else
        ui->msgTextEdit->setFontWeight(QFont::Normal);
    ui->msgTextEdit->setFocus();
}

void Widget::on_italicTBtn_clicked(bool checked)
{
    ui->msgTextEdit->setFontItalic(checked);
    ui->msgTextEdit->setFocus();
}

void Widget::on_underlineTBtn_clicked(bool checked)
{
    ui->msgTextEdit->setFontUnderline(checked);
    ui->msgTextEdit->setFocus();
}


void Widget::on_colorTBtn_clicked()
{
    color=QColorDialog::getColor(color,this);
    if(color.isValid()){
        ui->msgTextEdit->setTextColor(color);
        ui->msgTextEdit->setFocus();
    }
}

void Widget::curFmtChanged(const QTextCharFormat &fmt)
{
    ui->fontCbx->setCurrentFont(fmt.font());
    if(fmt.fontPointSize()<8){
        ui->sizeCbx->setCurrentIndex(4);
    }else{
        ui->sizeCbx->setCurrentIndex(ui->sizeCbx->findText(QString::number(fmt.fontPointSize())));
    }
    ui->boldTBtn->setChecked(fmt.font().bold());
    ui->italicTBtn->setChecked(fmt.font().italic());
    ui->underlineTBtn->setChecked(fmt.font().underline());
    color=fmt.foreground().color();
}

void Widget::on_saveTBtn_clicked()
{
    if(ui->msgBrowser->document()->isEmpty()){
        QMessageBox::warning(0,tr("警告"),tr("聊天记录为空，无法保存！"),QMessageBox::Ok);
    }else{
        QString fname=QFileDialog::getSaveFileName(this,tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;所有文件(*.*)"));
        if(!fname.isEmpty())
            saveFile(fname);
    }
}

bool Widget::saveFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1:\n%2").arg(filename).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->msgBrowser->toPlainText();

    return true;
}
void Widget::on_clearTBtn_clicked()
{
    ui->msgBrowser->clear();
}

void Widget::closeEvent(QCloseEvent *event)
{
    sndMsg(UsrLeft);
    QWidget::closeEvent(event);
}
