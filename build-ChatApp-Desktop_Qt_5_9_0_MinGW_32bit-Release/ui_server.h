/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *label_3;
    QPushButton *sOpenBtn;
    QPushButton *sSendBtn;
    QProgressBar *progressBar;
    QLabel *sStatusLbl;
    QPushButton *sCloseBtn;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(400, 300);
        label_3 = new QLabel(Server);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 30, 131, 31));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        sOpenBtn = new QPushButton(Server);
        sOpenBtn->setObjectName(QStringLiteral("sOpenBtn"));
        sOpenBtn->setGeometry(QRect(250, 40, 75, 23));
        sSendBtn = new QPushButton(Server);
        sSendBtn->setObjectName(QStringLiteral("sSendBtn"));
        sSendBtn->setGeometry(QRect(50, 90, 75, 23));
        progressBar = new QProgressBar(Server);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(190, 90, 191, 23));
        progressBar->setValue(0);
        sStatusLbl = new QLabel(Server);
        sStatusLbl->setObjectName(QStringLiteral("sStatusLbl"));
        sStatusLbl->setGeometry(QRect(40, 140, 141, 16));
        QFont font1;
        font1.setPointSize(10);
        sStatusLbl->setFont(font1);
        sCloseBtn = new QPushButton(Server);
        sCloseBtn->setObjectName(QStringLiteral("sCloseBtn"));
        sCloseBtn->setGeometry(QRect(250, 160, 75, 23));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "\345\217\221\351\200\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("Server", "\351\200\211\346\213\251\346\226\207\344\273\266\343\200\201\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        sOpenBtn->setText(QApplication::translate("Server", "\346\211\223\345\274\200...", Q_NULLPTR));
        sSendBtn->setText(QApplication::translate("Server", "\345\217\221\351\200\201", Q_NULLPTR));
        sStatusLbl->setText(QApplication::translate("Server", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266\357\274\201", Q_NULLPTR));
        sCloseBtn->setText(QApplication::translate("Server", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
