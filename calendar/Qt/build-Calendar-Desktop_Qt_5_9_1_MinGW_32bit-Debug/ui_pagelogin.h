/********************************************************************************
** Form generated from reading UI file 'pagelogin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGELOGIN_H
#define UI_PAGELOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageLogin
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_username;
    QLineEdit *line_username;
    QLabel *label_3;
    QLineEdit *line_password;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *btn_create;
    QPushButton *btn_login;

    void setupUi(QWidget *PageLogin)
    {
        if (PageLogin->objectName().isEmpty())
            PageLogin->setObjectName(QStringLiteral("PageLogin"));
        PageLogin->resize(400, 250);
        PageLogin->setMaximumSize(QSize(400, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        PageLogin->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(PageLogin);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(PageLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(PageLogin);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_username = new QLabel(widget_2);
        label_username->setObjectName(QStringLiteral("label_username"));
        QFont font1;
        font1.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font1.setPointSize(14);
        label_username->setFont(font1);

        gridLayout_2->addWidget(label_username, 0, 0, 1, 1);

        line_username = new QLineEdit(widget_2);
        line_username->setObjectName(QStringLiteral("line_username"));
        line_username->setMaxLength(21);

        gridLayout_2->addWidget(line_username, 0, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        line_password = new QLineEdit(widget_2);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setMaxLength(8);
        line_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(line_password, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(PageLogin);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 35));
        QFont font2;
        font2.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font2.setPointSize(12);
        pushButton_2->setFont(font2);

        gridLayout->addWidget(pushButton_2, 0, 4, 1, 1);

        btn_create = new QPushButton(widget);
        btn_create->setObjectName(QStringLiteral("btn_create"));
        btn_create->setMinimumSize(QSize(0, 35));
        btn_create->setFont(font2);

        gridLayout->addWidget(btn_create, 0, 2, 1, 1);

        btn_login = new QPushButton(widget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setMinimumSize(QSize(0, 35));
        btn_login->setFont(font2);

        gridLayout->addWidget(btn_login, 0, 3, 1, 1);


        gridLayout_3->addWidget(widget, 2, 0, 1, 1);


        retranslateUi(PageLogin);

        QMetaObject::connectSlotsByName(PageLogin);
    } // setupUi

    void retranslateUi(QWidget *PageLogin)
    {
        PageLogin->setWindowTitle(QApplication::translate("PageLogin", "\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        PageLogin->setToolTip(QApplication::translate("PageLogin", "\350\277\231\346\230\257\347\231\273\345\275\225\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("PageLogin", "\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_username->setText(QApplication::translate("PageLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        line_username->setPlaceholderText(QApplication::translate("PageLogin", "\350\257\267\350\276\223\345\205\24521\344\275\215\344\273\245\345\206\205\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("PageLogin", "\345\257\206\347\240\201", Q_NULLPTR));
        line_password->setPlaceholderText(QApplication::translate("PageLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PageLogin", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_create->setText(QApplication::translate("PageLogin", "\346\263\250\345\206\214", Q_NULLPTR));
        btn_login->setText(QApplication::translate("PageLogin", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PageLogin: public Ui_PageLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGELOGIN_H
