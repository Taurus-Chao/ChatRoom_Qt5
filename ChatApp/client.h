#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include<QHostAddress>
#include<QFile>
#include<QTime>

class QTcpSocket;

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

    void setHostAddr(QHostAddress addr);
    void setFileName(QString name);//获取文件保存路径

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::Client *ui;

    QTcpSocket *tClnt;//客户端套接字类
    quint16 blockSize;
    QHostAddress hostAddr;//服务器ip地址
    qint16 tPort;

    qint64 totalBytes;
    qint64 bytesReceived;
    qint64 fileNameSize;
    QString fileName;
    QFile *locFile;//待接收文件
    QByteArray inBlock;//缓存一次接收的数据

    QTime time;
private slots:

    void newConn();//连接到服务器
    void readMsg();//读取文件数据
    void displayErr(QAbstractSocket::SocketError);//显示错误信息
    void on_cCancleBtn_clicked();
    void on_cCloseBtn_clicked();
};

#endif // CLIENT_H
