#ifndef MODSCHEDULE_H
#define MODSCHEDULE_H

#include <QWidget>
#include <string>
#include "qstrans.h"
#include <QMessageBox>
using namespace std;

namespace Ui {
class modSchedule;
}

class modSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit modSchedule(QWidget *parent = 0);
    int getID();
    void editTaskname(string task);
    void editClassification(string classifi);
    void editAT(time_t aT);
    void editST(time_t sT);
    void editPriority(int prio);
    void clear();
    string getTaskname();
    time_t getAlertTime();
    time_t getStartTime();
    string getClassfication();
    int getPriority();
    ~modSchedule();

private slots:
    void on_pushButton_2_clicked();

    void on_le_id_editingFinished();
    void on_btn_checkMod_clicked();

signals:
    void finishEditId();
    void sendClickMod();
private:
    Ui::modSchedule *ui;
};

#endif // MODSCHEDULE_H
