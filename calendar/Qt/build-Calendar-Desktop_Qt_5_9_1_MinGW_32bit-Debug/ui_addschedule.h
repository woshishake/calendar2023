/********************************************************************************
** Form generated from reading UI file 'addschedule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCHEDULE_H
#define UI_ADDSCHEDULE_H

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

class Ui_addSchedule
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_taskname;
    QComboBox *cb_priority;
    QLineEdit *le_classification;
    QDateTimeEdit *det_aT;
    QDateTimeEdit *dte_sT;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *addSchedule)
    {
        if (addSchedule->objectName().isEmpty())
            addSchedule->setObjectName(QStringLiteral("addSchedule"));
        addSchedule->resize(400, 482);
        addSchedule->setMinimumSize(QSize(400, 482));
        addSchedule->setMaximumSize(QSize(400, 482));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addSchedule->setWindowIcon(icon);
        addSchedule->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));
        label = new QLabel(addSchedule);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 80, 30));
        label->setMaximumSize(QSize(80, 30));
        QFont font;
        font.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(addSchedule);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 120, 80, 30));
        label_2->setMaximumSize(QSize(80, 30));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(addSchedule);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 170, 80, 30));
        label_3->setMaximumSize(QSize(80, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(addSchedule);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 220, 80, 30));
        label_4->setMaximumSize(QSize(80, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(addSchedule);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 10, 140, 50));
        label_5->setMaximumSize(QSize(140, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        le_taskname = new QLineEdit(addSchedule);
        le_taskname->setObjectName(QStringLiteral("le_taskname"));
        le_taskname->setGeometry(QRect(130, 70, 230, 30));
        le_taskname->setMaximumSize(QSize(230, 30));
        le_taskname->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        cb_priority = new QComboBox(addSchedule);
        cb_priority->setObjectName(QStringLiteral("cb_priority"));
        cb_priority->setGeometry(QRect(130, 222, 69, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font2.setPointSize(12);
        cb_priority->setFont(font2);
        cb_priority->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_classification = new QLineEdit(addSchedule);
        le_classification->setObjectName(QStringLiteral("le_classification"));
        le_classification->setGeometry(QRect(130, 272, 230, 30));
        le_classification->setMaximumSize(QSize(230, 30));
        le_classification->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_classification->setReadOnly(false);
        det_aT = new QDateTimeEdit(addSchedule);
        det_aT->setObjectName(QStringLiteral("det_aT"));
        det_aT->setGeometry(QRect(130, 123, 230, 30));
        det_aT->setMaximumSize(QSize(230, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(12);
        det_aT->setFont(font3);
        det_aT->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        det_aT->setDateTime(QDateTime(QDate(2004, 1, 1), QTime(0, 0, 0)));
        det_aT->setCalendarPopup(true);
        dte_sT = new QDateTimeEdit(addSchedule);
        dte_sT->setObjectName(QStringLiteral("dte_sT"));
        dte_sT->setGeometry(QRect(130, 172, 230, 30));
        dte_sT->setMaximumSize(QSize(230, 30));
        dte_sT->setFont(font3);
        dte_sT->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        dte_sT->setCalendarPopup(true);
        label_6 = new QLabel(addSchedule);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 270, 80, 30));
        label_6->setMaximumSize(QSize(80, 30));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(addSchedule);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(234, 342, 111, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font4.setPointSize(14);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));
        pushButton_2 = new QPushButton(addSchedule);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(234, 392, 111, 31));
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 153);"));

        retranslateUi(addSchedule);

        QMetaObject::connectSlotsByName(addSchedule);
    } // setupUi

    void retranslateUi(QWidget *addSchedule)
    {
        addSchedule->setWindowTitle(QApplication::translate("addSchedule", "\346\267\273\345\212\240\346\227\245\347\250\213", Q_NULLPTR));
        label->setText(QApplication::translate("addSchedule", "\346\227\245\347\250\213\345\220\215\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("addSchedule", "\346\217\220\351\206\222\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("addSchedule", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_4->setText(QApplication::translate("addSchedule", "\344\274\230\345\205\210\347\272\247", Q_NULLPTR));
        label_5->setText(QApplication::translate("addSchedule", "\346\227\245\347\250\213\345\210\233\345\273\272", Q_NULLPTR));
        le_taskname->setPlaceholderText(QApplication::translate("addSchedule", "\350\257\267\350\276\223\345\205\245\346\227\245\347\250\213\345\220\215\347\247\260", Q_NULLPTR));
        cb_priority->clear();
        cb_priority->insertItems(0, QStringList()
         << QApplication::translate("addSchedule", "\344\275\216", Q_NULLPTR)
         << QApplication::translate("addSchedule", "\344\270\255", Q_NULLPTR)
         << QApplication::translate("addSchedule", "\351\253\230", Q_NULLPTR)
        );
        le_classification->setPlaceholderText(QApplication::translate("addSchedule", "\350\257\267\350\276\223\345\205\245\345\210\206\347\261\273", Q_NULLPTR));
        label_6->setText(QApplication::translate("addSchedule", "\345\210\206\347\261\273", Q_NULLPTR));
        pushButton->setText(QApplication::translate("addSchedule", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("addSchedule", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addSchedule: public Ui_addSchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCHEDULE_H
