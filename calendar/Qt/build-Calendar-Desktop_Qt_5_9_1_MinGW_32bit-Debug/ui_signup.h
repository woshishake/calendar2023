/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signUp
{
public:
    QWidget *widget;
    QLabel *label;
    QLineEdit *line_username;
    QLabel *label_2;
    QLineEdit *line_password;
    QLabel *label_3;
    QLineEdit *line_password2;
    QPushButton *btn_checkSignUp;
    QLabel *label_4;

    void setupUi(QWidget *signUp)
    {
        if (signUp->objectName().isEmpty())
            signUp->setObjectName(QStringLiteral("signUp"));
        signUp->resize(300, 400);
        signUp->setMaximumSize(QSize(300, 450));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        signUp->setWindowIcon(icon);
        widget = new QWidget(signUp);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 281, 181));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 80, 30));
        label->setMinimumSize(QSize(80, 30));
        label->setMaximumSize(QSize(80, 30));
        QFont font;
        font.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_username = new QLineEdit(widget);
        line_username->setObjectName(QStringLiteral("line_username"));
        line_username->setGeometry(QRect(110, 10, 150, 30));
        line_username->setMaximumSize(QSize(150, 30));
        line_username->setMaxLength(21);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 80, 30));
        label_2->setMinimumSize(QSize(80, 30));
        label_2->setMaximumSize(QSize(80, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_password = new QLineEdit(widget);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setGeometry(QRect(110, 60, 150, 30));
        line_password->setMaximumSize(QSize(150, 30));
        line_password->setMaxLength(11);
        line_password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 80, 30));
        label_3->setMaximumSize(QSize(80, 30));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_password2 = new QLineEdit(widget);
        line_password2->setObjectName(QStringLiteral("line_password2"));
        line_password2->setGeometry(QRect(110, 110, 150, 30));
        line_password2->setMaximumSize(QSize(150, 30));
        line_password2->setMaxLength(11);
        line_password2->setEchoMode(QLineEdit::Password);
        btn_checkSignUp = new QPushButton(signUp);
        btn_checkSignUp->setObjectName(QStringLiteral("btn_checkSignUp"));
        btn_checkSignUp->setGeometry(QRect(170, 320, 101, 41));
        btn_checkSignUp->setFont(font);
        label_4 = new QLabel(signUp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 20, 161, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font1.setPointSize(20);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(signUp);

        QMetaObject::connectSlotsByName(signUp);
    } // setupUi

    void retranslateUi(QWidget *signUp)
    {
        signUp->setWindowTitle(QApplication::translate("signUp", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("signUp", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        line_username->setPlaceholderText(QApplication::translate("signUp", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("signUp", "\345\257\206\347\240\201", Q_NULLPTR));
        line_password->setPlaceholderText(QApplication::translate("signUp", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("signUp", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        line_password2->setPlaceholderText(QApplication::translate("signUp", "\345\206\215\346\254\241\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        btn_checkSignUp->setText(QApplication::translate("signUp", "\347\241\256\350\256\244", Q_NULLPTR));
        label_4->setText(QApplication::translate("signUp", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signUp: public Ui_signUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
