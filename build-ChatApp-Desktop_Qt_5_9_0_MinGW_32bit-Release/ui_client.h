/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

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

class Ui_Client
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *cStatusLbl;
    QPushButton *cCancleBtn;
    QPushButton *cCloseBtn;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(400, 300);
        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 54, 12));
        progressBar = new QProgressBar(Client);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(180, 70, 118, 23));
        progressBar->setValue(24);
        cStatusLbl = new QLabel(Client);
        cStatusLbl->setObjectName(QStringLiteral("cStatusLbl"));
        cStatusLbl->setGeometry(QRect(60, 150, 111, 16));
        cCancleBtn = new QPushButton(Client);
        cCancleBtn->setObjectName(QStringLiteral("cCancleBtn"));
        cCancleBtn->setGeometry(QRect(90, 210, 75, 23));
        cCloseBtn = new QPushButton(Client);
        cCloseBtn->setObjectName(QStringLiteral("cCloseBtn"));
        cCloseBtn->setGeometry(QRect(220, 210, 75, 23));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "\345\267\262\345\256\214\346\210\220", Q_NULLPTR));
        cStatusLbl->setText(QApplication::translate("Client", "\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266...", Q_NULLPTR));
        cCancleBtn->setText(QApplication::translate("Client", "\345\217\226\346\266\210", Q_NULLPTR));
        cCloseBtn->setText(QApplication::translate("Client", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
