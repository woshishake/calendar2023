/********************************************************************************
** Form generated from reading UI file 'delschedule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELSCHEDULE_H
#define UI_DELSCHEDULE_H

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

class Ui_delSchedule
{
public:
    QLabel *label_5;
    QLabel *label;
    QLineEdit *le_delID;
    QPushButton *btn_checkDel;
    QPushButton *pushButton_2;

    void setupUi(QWidget *delSchedule)
    {
        if (delSchedule->objectName().isEmpty())
            delSchedule->setObjectName(QStringLiteral("delSchedule"));
        delSchedule->resize(400, 214);
        delSchedule->setMinimumSize(QSize(400, 214));
        delSchedule->setMaximumSize(QSize(400, 214));
        delSchedule->setStyleSheet(QLatin1String("background-color: rgb(102, 153, 153);\n"
""));
        label_5 = new QLabel(delSchedule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 10, 140, 50));
        label_5->setMaximumSize(QSize(140, 50));
        QFont font;
        font.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        label = new QLabel(delSchedule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 80, 30));
        label->setMaximumSize(QSize(80, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_delID = new QLineEdit(delSchedule);
        le_delID->setObjectName(QStringLiteral("le_delID"));
        le_delID->setGeometry(QRect(130, 70, 230, 30));
        le_delID->setMaximumSize(QSize(230, 30));
        le_delID->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        btn_checkDel = new QPushButton(delSchedule);
        btn_checkDel->setObjectName(QStringLiteral("btn_checkDel"));
        btn_checkDel->setGeometry(QRect(250, 120, 111, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font2.setPointSize(14);
        btn_checkDel->setFont(font2);
        btn_checkDel->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));
        pushButton_2 = new QPushButton(delSchedule);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 160, 111, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));

        retranslateUi(delSchedule);

        QMetaObject::connectSlotsByName(delSchedule);
    } // setupUi

    void retranslateUi(QWidget *delSchedule)
    {
        delSchedule->setWindowTitle(QApplication::translate("delSchedule", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("delSchedule", "\346\227\245\347\250\213\345\210\240\351\231\244", Q_NULLPTR));
        label->setText(QApplication::translate("delSchedule", "\346\227\245\347\250\213id", Q_NULLPTR));
        le_delID->setPlaceholderText(QApplication::translate("delSchedule", "\350\257\267\350\276\223\345\205\245\345\210\240\351\231\244\346\227\245\347\250\213id", Q_NULLPTR));
        btn_checkDel->setText(QApplication::translate("delSchedule", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("delSchedule", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class delSchedule: public Ui_delSchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELSCHEDULE_H
