/********************************************************************************
** Form generated from reading UI file 'modschedule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODSCHEDULE_H
#define UI_MODSCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modSchedule
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_id;
    QLabel *label_3;
    QLineEdit *le_taskname;
    QLabel *label_4;
    QDateTimeEdit *det_aT;
    QLabel *label_5;
    QDateTimeEdit *dte_sT;
    QLabel *label_6;
    QComboBox *cb_priority;
    QLabel *label_7;
    QLineEdit *le_classification;
    QPushButton *btn_checkMod;
    QPushButton *pushButton_2;

    void setupUi(QWidget *modSchedule)
    {
        if (modSchedule->objectName().isEmpty())
            modSchedule->setObjectName(QStringLiteral("modSchedule"));
        modSchedule->resize(400, 482);
        modSchedule->setMaximumSize(QSize(400, 482));
        modSchedule->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));
        label = new QLabel(modSchedule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 140, 47));
        label->setMaximumSize(QSize(140, 50));
        QFont font;
        font.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(modSchedule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 80, 30));
        label_2->setMaximumSize(QSize(80, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_id = new QLineEdit(modSchedule);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(140, 70, 230, 30));
        le_id->setMaximumSize(QSize(230, 30));
        le_id->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(modSchedule);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 80, 30));
        label_3->setMaximumSize(QSize(80, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_taskname = new QLineEdit(modSchedule);
        le_taskname->setObjectName(QStringLiteral("le_taskname"));
        le_taskname->setGeometry(QRect(140, 123, 230, 30));
        le_taskname->setMaximumSize(QSize(230, 30));
        le_taskname->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(modSchedule);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 179, 80, 30));
        label_4->setMaximumSize(QSize(80, 30));
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        det_aT = new QDateTimeEdit(modSchedule);
        det_aT->setObjectName(QStringLiteral("det_aT"));
        det_aT->setGeometry(QRect(140, 180, 230, 30));
        det_aT->setMaximumSize(QSize(230, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(12);
        det_aT->setFont(font3);
        det_aT->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        det_aT->setDateTime(QDateTime(QDate(2004, 1, 1), QTime(0, 0, 0)));
        det_aT->setCalendarPopup(true);
        label_5 = new QLabel(modSchedule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 228, 80, 30));
        label_5->setMaximumSize(QSize(80, 30));
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dte_sT = new QDateTimeEdit(modSchedule);
        dte_sT->setObjectName(QStringLiteral("dte_sT"));
        dte_sT->setGeometry(QRect(140, 230, 230, 30));
        dte_sT->setMaximumSize(QSize(230, 30));
        dte_sT->setFont(font3);
        dte_sT->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        dte_sT->setCalendarPopup(true);
        label_6 = new QLabel(modSchedule);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 280, 80, 30));
        label_6->setMaximumSize(QSize(80, 30));
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_priority = new QComboBox(modSchedule);
        cb_priority->setObjectName(QStringLiteral("cb_priority"));
        cb_priority->setGeometry(QRect(140, 282, 69, 30));
        QFont font4;
        font4.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font4.setPointSize(12);
        cb_priority->setFont(font4);
        cb_priority->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(modSchedule);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 330, 80, 30));
        label_7->setMaximumSize(QSize(80, 30));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_classification = new QLineEdit(modSchedule);
        le_classification->setObjectName(QStringLiteral("le_classification"));
        le_classification->setGeometry(QRect(140, 333, 230, 30));
        le_classification->setMaximumSize(QSize(230, 30));
        le_classification->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_classification->setReadOnly(false);
        btn_checkMod = new QPushButton(modSchedule);
        btn_checkMod->setObjectName(QStringLiteral("btn_checkMod"));
        btn_checkMod->setGeometry(QRect(70, 400, 111, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font5.setPointSize(14);
        btn_checkMod->setFont(font5);
        btn_checkMod->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));
        pushButton_2 = new QPushButton(modSchedule);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 400, 111, 31));
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));

        retranslateUi(modSchedule);

        QMetaObject::connectSlotsByName(modSchedule);
    } // setupUi

    void retranslateUi(QWidget *modSchedule)
    {
        modSchedule->setWindowTitle(QApplication::translate("modSchedule", "\344\277\256\346\224\271\346\227\245\347\250\213", Q_NULLPTR));
        label->setText(QApplication::translate("modSchedule", "\346\227\245\347\250\213\344\277\256\346\224\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("modSchedule", "id ", Q_NULLPTR));
        le_id->setPlaceholderText(QApplication::translate("modSchedule", "\350\257\267\350\276\223\345\205\245id", Q_NULLPTR));
        label_3->setText(QApplication::translate("modSchedule", "\346\227\245\347\250\213\345\220\215\347\247\260", Q_NULLPTR));
        le_taskname->setPlaceholderText(QApplication::translate("modSchedule", "\344\273\273\345\212\241\344\270\215\345\255\230\345\234\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("modSchedule", "\346\217\220\351\206\222\346\227\266\351\227\264", Q_NULLPTR));
        label_5->setText(QApplication::translate("modSchedule", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("modSchedule", "\344\274\230\345\205\210\347\272\247", Q_NULLPTR));
        cb_priority->clear();
        cb_priority->insertItems(0, QStringList()
         << QApplication::translate("modSchedule", "\344\275\216", Q_NULLPTR)
         << QApplication::translate("modSchedule", "\344\270\255", Q_NULLPTR)
         << QApplication::translate("modSchedule", "\351\253\230", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("modSchedule", "\345\210\206\347\261\273", Q_NULLPTR));
        le_classification->setPlaceholderText(QApplication::translate("modSchedule", "\344\273\273\345\212\241\344\270\215\345\255\230\345\234\250", Q_NULLPTR));
        btn_checkMod->setText(QApplication::translate("modSchedule", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("modSchedule", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modSchedule: public Ui_modSchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODSCHEDULE_H
