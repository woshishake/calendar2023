#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QWidget>
#include <string>
#include <time.h>
#include <QMessageBox>
#include "qstrans.h"
using namespace std;
namespace Ui {
class addSchedule;
}

class addSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit addSchedule(QWidget *parent = 0);
    string getTaskname();
    time_t getAlertTime();
    time_t getStartTime();
    string getClassfication();
    int getPriority();
    ~addSchedule();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void sendClickAdd();
private:
    Ui::addSchedule *ui;
};

#endif // ADDSCHEDULE_H
