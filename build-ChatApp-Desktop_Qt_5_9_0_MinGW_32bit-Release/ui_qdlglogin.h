/********************************************************************************
** Form generated from reading UI file 'qdlglogin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDLGLOGIN_H
#define UI_QDLGLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QDlgLogin
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *editUser;
    QLabel *label_3;
    QLineEdit *editPSWD;
    QCheckBox *chkBoxSave;
    QPushButton *btnOK;
    QPushButton *btnCancle;

    void setupUi(QDialog *QDlgLogin)
    {
        if (QDlgLogin->objectName().isEmpty())
            QDlgLogin->setObjectName(QStringLiteral("QDlgLogin"));
        QDlgLogin->resize(709, 455);
        verticalLayout = new QVBoxLayout(QDlgLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(QDlgLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("images/timg.jpg")));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(QDlgLogin);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        editUser = new QLineEdit(groupBox);
        editUser->setObjectName(QStringLiteral("editUser"));

        horizontalLayout->addWidget(editUser);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        editPSWD = new QLineEdit(groupBox);
        editPSWD->setObjectName(QStringLiteral("editPSWD"));

        horizontalLayout->addWidget(editPSWD);

        chkBoxSave = new QCheckBox(groupBox);
        chkBoxSave->setObjectName(QStringLiteral("chkBoxSave"));

        horizontalLayout->addWidget(chkBoxSave);

        btnOK = new QPushButton(groupBox);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancle = new QPushButton(groupBox);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));

        horizontalLayout->addWidget(btnCancle);


        verticalLayout->addWidget(groupBox);


        retranslateUi(QDlgLogin);
        QObject::connect(btnCancle, SIGNAL(clicked()), QDlgLogin, SLOT(close()));

        QMetaObject::connectSlotsByName(QDlgLogin);
    } // setupUi

    void retranslateUi(QDialog *QDlgLogin)
    {
        QDlgLogin->setWindowTitle(QApplication::translate("QDlgLogin", "Dialog", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("QDlgLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("QDlgLogin", "\345\257\206\347\240\201", Q_NULLPTR));
        chkBoxSave->setText(QApplication::translate("QDlgLogin", "\344\277\235\345\255\230\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        btnOK->setText(QApplication::translate("QDlgLogin", "\347\241\256\345\256\232", Q_NULLPTR));
        btnCancle->setText(QApplication::translate("QDlgLogin", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDlgLogin: public Ui_QDlgLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDLGLOGIN_H
