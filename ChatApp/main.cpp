#include "widget.h"
#include <QApplication>
#include"drawer.h"
#include"qdlglogin.h"
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    //Drawer drawer;
    //drawer.resize(230,700);
    //drawer.show();

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec); //解决汉字乱码问题
    QDlgLogin *dlgLogin=new QDlgLogin; //创建对话框
    int x=dlgLogin->exec();
    if(x==100)
    {
        Drawer drawer;
        drawer.resize(230,700);
        drawer.show();
        return a.exec();
    }
    else if(x==1)
    {
        Widget *chatWidget1=new Widget(0,"用户1");
        chatWidget1->setWindowTitle("用户1");
        chatWidget1->setWindowIcon(QPixmap(":/images/wy.jpg"));
        chatWidget1->show();
        return a.exec();
    }
    else if(x==2)
    {
        Widget *chatWidget1=new Widget(0,"用户2");
        chatWidget1->setWindowTitle("用户2");
        chatWidget1->setWindowIcon(QPixmap(":/images/ymrl.jpg"));
        chatWidget1->show();
        return a.exec();
    }
    else if(x==3)
    {
        Widget *chatWidget1=new Widget(0,"用户3");
        chatWidget1->setWindowTitle("用户3");
        chatWidget1->setWindowIcon(QPixmap(":/images/qq.jpg"));
        chatWidget1->show();
        return a.exec();
    }
    else if(x==4)
    {
        Widget *chatWidget1=new Widget(0,"用户4");
        chatWidget1->setWindowTitle("用户4");
        chatWidget1->setWindowIcon(QPixmap(":/images/Cherry.jpg"));
        chatWidget1->show();
        return a.exec();
    }


}
