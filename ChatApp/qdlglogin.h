#ifndef QDLGLOGIN_H
#define QDLGLOGIN_H

#include <QDialog>

namespace Ui {
class QDlgLogin;
}

class QDlgLogin : public QDialog
{
    Q_OBJECT

private:
    bool    m_moving=false;//表示窗口是否在鼠标操作下移动
    QPoint  m_lastPos;  //上一次的鼠标位置
    QString m_user="root"; //初始化用户名
    QString m_pswd="0000";//初始化密码，未加密的
    QString m_user1="user1"; //初始化用户名
    QString m_pswd1="12345";//初始化密码，未加密的
    QString m_user2="user2"; //初始化用户名
    QString m_pswd2="12345";//初始化密码，未加密的
    QString m_user3="user3"; //初始化用户名
    QString m_pswd3="12345";//初始化密码，未加密的
    QString m_user4="user4"; //初始化用户名
    QString m_pswd4="12345";//初始化密码，未加密的
    int m_tryCount=0; //试错次数
    void    readSettings(); //读取设置,从注册表
    void    writeSettings(QString usernamelogin,QString userpwd);//写入设置，从注册表
    QString encrypt(const QString& str);//字符串加密
protected:
//用于鼠标拖动窗口的鼠标事件操作
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
public:
    explicit QDlgLogin(QWidget *parent = 0);
    ~QDlgLogin();
private slots:
    void on_btnOK_clicked(); //OK按键

private:
    Ui::QDlgLogin *ui;
};

#endif // QDLGLOGIN_H
