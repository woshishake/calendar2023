/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_user;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QWidget *widget_3;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QPushButton *btn_mod;
    QPushButton *pushButton_2;
    QWidget *widget_4;
    QTableWidget *tableWidget;
    QWidget *widget_6;
    QPushButton *btn_check;
    QComboBox *comboBox;
    QLineEdit *line_taskname;
    QLineEdit *line_classification;
    QLabel *label_4;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QDateTimeEdit *time1;
    QWidget *widget_8;
    QDateTimeEdit *time2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("QWidget#centralWidget{background-color:#336666;};"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 100));
        widget->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(60, 16777215));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));

        gridLayout->addWidget(pushButton, 0, 3, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 40));
        label_3->setMaximumSize(QSize(40, 40));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/\350\233\231\350\233\231.jpg);"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/\350\233\231\350\233\231.jpg")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_user = new QLabel(widget_2);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setMinimumSize(QSize(130, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font1.setPointSize(12);
        label_user->setFont(font1);

        gridLayout->addWidget(label_user, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(314, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(150, 16777215));
        widget_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        btn_add = new QPushButton(widget_3);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setGeometry(QRect(20, 10, 130, 40));
        btn_add->setMaximumSize(QSize(130, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("AniMe Matrix - MB_EN"));
        font3.setPointSize(14);
        btn_add->setFont(font3);
        btn_add->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));
        btn_del = new QPushButton(widget_3);
        btn_del->setObjectName(QStringLiteral("btn_del"));
        btn_del->setGeometry(QRect(20, 60, 130, 40));
        btn_del->setMaximumSize(QSize(130, 40));
        btn_del->setFont(font3);
        btn_del->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));
        btn_mod = new QPushButton(widget_3);
        btn_mod->setObjectName(QStringLiteral("btn_mod"));
        btn_mod->setGeometry(QRect(20, 110, 130, 40));
        btn_mod->setMaximumSize(QSize(130, 40));
        btn_mod->setFont(font3);
        btn_mod->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(46, 330, 75, 23));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(102, 153, 153);"));

        gridLayout_3->addWidget(widget_3, 0, 0, 1, 1);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral(""));
        tableWidget = new QTableWidget(widget_4);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font4);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 0, 801, 401));

        gridLayout_3->addWidget(widget_4, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_5, 2, 0, 1, 1);

        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMaximumSize(QSize(16777215, 40));
        btn_check = new QPushButton(widget_6);
        btn_check->setObjectName(QStringLiteral("btn_check"));
        btn_check->setGeometry(QRect(890, 8, 75, 25));
        btn_check->setMaximumSize(QSize(75, 25));
        comboBox = new QComboBox(widget_6);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(830, 10, 50, 20));
        comboBox->setMaximumSize(QSize(50, 20));
        line_taskname = new QLineEdit(widget_6);
        line_taskname->setObjectName(QStringLiteral("line_taskname"));
        line_taskname->setGeometry(QRect(40, 11, 120, 20));
        line_taskname->setMaximumSize(QSize(120, 20));
        line_classification = new QLineEdit(widget_6);
        line_classification->setObjectName(QStringLiteral("line_classification"));
        line_classification->setGeometry(QRect(720, 10, 100, 20));
        line_classification->setMaximumSize(QSize(100, 20));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 9, 71, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(270, 0, 210, 40));
        widget_7->setMaximumSize(QSize(16777215, 40));
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        time1 = new QDateTimeEdit(widget_7);
        time1->setObjectName(QStringLiteral("time1"));
        time1->setMinimumSize(QSize(0, 22));
        time1->setCalendarPopup(true);

        gridLayout_5->addWidget(time1, 0, 1, 1, 1);

        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(480, 0, 211, 40));
        widget_8->setMaximumSize(QSize(16777215, 40));
        time2 = new QDateTimeEdit(widget_8);
        time2->setObjectName(QStringLiteral("time2"));
        time2->setGeometry(QRect(10, 10, 194, 22));
        time2->setCalendarPopup(true);

        gridLayout_4->addWidget(widget_6, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "\350\277\231\346\230\257\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215: ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label_3->setText(QString());
        label_user->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        btn_add->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        btn_del->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        btn_mod->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\344\273\273\345\212\241\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\217\220\351\206\222\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\344\274\230\345\205\210\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\345\210\206\347\261\273", Q_NULLPTR));
        btn_check->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\200\346\234\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\216", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\255", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\253\230", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        line_taskname->setToolTip(QApplication::translate("MainWindow", "\346\227\245\347\250\213\345\220\215\347\247\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        line_taskname->setPlaceholderText(QApplication::translate("MainWindow", "\344\273\273\345\212\241\345\220\215\347\247\260", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        line_classification->setToolTip(QApplication::translate("MainWindow", "\345\210\206\347\261\273", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        line_classification->setPlaceholderText(QApplication::translate("MainWindow", "\345\210\206\347\261\273", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
