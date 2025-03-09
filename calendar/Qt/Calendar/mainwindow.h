#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pagelogin.h"
#include "addschedule.h"
#include "modschedule.h"
#include "delschedule.h"
#include "schedule.h"

void getTime(tm *&info, int year, int month, int day, int hour, int minutes);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_btn_add_clicked();

    void on_btn_mod_clicked();

    void on_btn_del_clicked();

    void on_btn_check_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    PageLogin m_dlgLogin;
    addSchedule addPage;
    modSchedule modPage;
    delSchedule delPage;
};


#endif // MAINWINDOW_H
