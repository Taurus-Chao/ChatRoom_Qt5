#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<qdlglogin.h>
#include<QTextCharFormat>

class Server;
class QUdpSocket;

namespace Ui {
class Widget;
}

enum MsgType{Msg,UsrEnter,UsrLeft,FileName,Refuse};//五种消息类型
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString usrname="null");
    ~Widget();
protected:
    void usrEnter(QString usrname,QString ipaddr);//处理新用户加入
    void usrLeft(QString usrname,QString time);//处理用户离开
    void sndMsg(MsgType type,QString srvaddr="");//广播UDP消息
    void hasPendingFile(QString usrname,QString srvaddr,QString clntaddr,QString filename);//收到文件名UDP消息时判断是否接收该文件

    QString getIP();//获取IP地址
    QString getUsr();//获取用户名
    QString getMsg();//获取聊天信息

    bool saveFile(const QString& filename);//保存聊天记录
    void closeEvent(QCloseEvent *event);

private slots:
    void on_sendBtn_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString uName;
    QString fileName;
    Server *srv;
    QColor color;
    
private slots:
    void processPendingDatagrams();//接受UDP消息
    void on_exitBtn_clicked();
    void getFileName(QString);//获取服务器类sndFileName()信号发来的文件名
    void on_sendTBtn_clicked();
    void on_fontCbx_currentFontChanged(const QFont &f);
    void on_sizeCbx_currentIndexChanged(const QString &arg1);
    void on_boldTBtn_clicked(bool checked);
    void on_italicTBtn_clicked(bool checked);
    void on_underlineTBtn_clicked(bool checked);
    void on_colorTBtn_clicked();
    void curFmtChanged(const QTextCharFormat &fmt);

    void on_saveTBtn_clicked();
    void on_clearTBtn_clicked();
};

#endif // WIDGET_H
