/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *msgBrowser;
    QTextEdit *msgTextEdit;
    QTableWidget *usrTblWidget;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *sendTBtn;
    QToolButton *saveTBtn;
    QToolButton *clearTBtn;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *usrNumLbl;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(730, 450);
        Widget->setMinimumSize(QSize(730, 450));
        Widget->setMaximumSize(QSize(730, 450));
        msgBrowser = new QTextBrowser(Widget);
        msgBrowser->setObjectName(QStringLiteral("msgBrowser"));
        msgBrowser->setGeometry(QRect(10, 10, 441, 261));
        msgTextEdit = new QTextEdit(Widget);
        msgTextEdit->setObjectName(QStringLiteral("msgTextEdit"));
        msgTextEdit->setGeometry(QRect(10, 320, 441, 71));
        usrTblWidget = new QTableWidget(Widget);
        if (usrTblWidget->columnCount() < 2)
            usrTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usrTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usrTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        usrTblWidget->setObjectName(QStringLiteral("usrTblWidget"));
        usrTblWidget->setGeometry(QRect(460, 10, 261, 381));
        usrTblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        usrTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        usrTblWidget->setShowGrid(false);
        fontCbx = new QFontComboBox(Widget);
        fontCbx->setObjectName(QStringLiteral("fontCbx"));
        fontCbx->setGeometry(QRect(10, 280, 81, 22));
        sizeCbx = new QComboBox(Widget);
        sizeCbx->setObjectName(QStringLiteral("sizeCbx"));
        sizeCbx->setGeometry(QRect(100, 280, 69, 22));
        boldTBtn = new QToolButton(Widget);
        boldTBtn->setObjectName(QStringLiteral("boldTBtn"));
        boldTBtn->setGeometry(QRect(180, 280, 33, 32));
        boldTBtn->setIconSize(QSize(26, 26));
        boldTBtn->setCheckable(true);
        boldTBtn->setChecked(false);
        italicTBtn = new QToolButton(Widget);
        italicTBtn->setObjectName(QStringLiteral("italicTBtn"));
        italicTBtn->setGeometry(QRect(220, 280, 33, 32));
        italicTBtn->setIconSize(QSize(26, 26));
        italicTBtn->setCheckable(true);
        underlineTBtn = new QToolButton(Widget);
        underlineTBtn->setObjectName(QStringLiteral("underlineTBtn"));
        underlineTBtn->setGeometry(QRect(260, 280, 33, 32));
        underlineTBtn->setIconSize(QSize(26, 26));
        underlineTBtn->setCheckable(true);
        colorTBtn = new QToolButton(Widget);
        colorTBtn->setObjectName(QStringLiteral("colorTBtn"));
        colorTBtn->setGeometry(QRect(300, 280, 33, 32));
        colorTBtn->setIconSize(QSize(26, 26));
        sendTBtn = new QToolButton(Widget);
        sendTBtn->setObjectName(QStringLiteral("sendTBtn"));
        sendTBtn->setGeometry(QRect(340, 280, 33, 32));
        sendTBtn->setIconSize(QSize(26, 26));
        saveTBtn = new QToolButton(Widget);
        saveTBtn->setObjectName(QStringLiteral("saveTBtn"));
        saveTBtn->setGeometry(QRect(380, 280, 33, 32));
        saveTBtn->setIconSize(QSize(26, 26));
        clearTBtn = new QToolButton(Widget);
        clearTBtn->setObjectName(QStringLiteral("clearTBtn"));
        clearTBtn->setGeometry(QRect(420, 280, 33, 32));
        clearTBtn->setIconSize(QSize(26, 26));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 390, 711, 61));
        QFont font;
        font.setKerning(true);
        groupBox->setFont(font);
        groupBox->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendBtn = new QPushButton(groupBox);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer_2 = new QSpacerItem(156, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        usrNumLbl = new QLabel(groupBox);
        usrNumLbl->setObjectName(QStringLiteral("usrNumLbl"));

        horizontalLayout->addWidget(usrNumLbl);

        horizontalSpacer_3 = new QSpacerItem(156, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exitBtn = new QPushButton(groupBox);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);


        retranslateUi(Widget);
        QObject::connect(Widget, SIGNAL(destroyed(QObject*)), exitBtn, SLOT(click()));

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = usrTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = usrTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", Q_NULLPTR));
        sizeCbx->clear();
        sizeCbx->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "9", Q_NULLPTR)
         << QApplication::translate("Widget", "10", Q_NULLPTR)
         << QApplication::translate("Widget", "11", Q_NULLPTR)
         << QApplication::translate("Widget", "12", Q_NULLPTR)
         << QApplication::translate("Widget", "13", Q_NULLPTR)
         << QApplication::translate("Widget", "14", Q_NULLPTR)
         << QApplication::translate("Widget", "15", Q_NULLPTR)
         << QApplication::translate("Widget", "16", Q_NULLPTR)
         << QApplication::translate("Widget", "17", Q_NULLPTR)
         << QApplication::translate("Widget", "18", Q_NULLPTR)
         << QApplication::translate("Widget", "19", Q_NULLPTR)
         << QApplication::translate("Widget", "20", Q_NULLPTR)
         << QApplication::translate("Widget", "21", Q_NULLPTR)
         << QApplication::translate("Widget", "22", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        boldTBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        boldTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        italicTBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        italicTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        underlineTBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        underlineTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colorTBtn->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\351\242\234\350\211\262\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colorTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sendTBtn->setToolTip(QApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sendTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveTBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        clearTBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clearTBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
        groupBox->setTitle(QString());
        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        usrNumLbl->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
