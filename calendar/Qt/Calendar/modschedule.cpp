#include "modschedule.h"
#include "ui_modschedule.h"

modSchedule::modSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modSchedule)
{
    ui->setupUi(this);
    ui->le_classification->setText("默认");
    ui->det_aT->setDateTime(QDateTime::currentDateTime());
    ui->dte_sT->setDateTime(QDateTime::currentDateTime());
    ui->cb_priority->setCurrentIndex(1);
}

modSchedule::~modSchedule()
{
    delete ui;
}

void modSchedule::on_pushButton_2_clicked()
{
    ui->le_classification->setText("默认");
    ui->det_aT->setDateTime(QDateTime::currentDateTime());
    ui->dte_sT->setDateTime(QDateTime::currentDateTime());
    ui->le_id->clear();
    ui->le_taskname->clear();
    ui->cb_priority->setCurrentIndex(1);
    this->close();
}

void modSchedule::on_le_id_editingFinished()
{
    if(!QString::compare(ui->le_id->text(),"")){
        clear();
    }
    else{
        emit finishEditId();
    }

}

int modSchedule::getID(){
    string a =qstr2str(ui->le_id->text());
    return stoi(a);
}

void modSchedule::editTaskname(string task){
    QString taskname=str2qstr(task);
    ui->le_taskname->setText(taskname);
}

void modSchedule::editClassification(string classifi){
    QString classification=str2qstr(classifi);
    ui->le_classification->setText(classification);
}

void modSchedule::editPriority(int prio){
    ui->cb_priority->setCurrentIndex(prio-1);
}

void modSchedule::editAT(time_t aT){
    QDateTime alertTime= QDateTime::fromTime_t(aT);
    ui->det_aT->setDateTime(alertTime);
}

void modSchedule::editST(time_t sT){
    QDateTime startTime =QDateTime::fromTime_t(sT);
    ui->dte_sT->setDateTime(startTime);
}


void modSchedule::clear(){
    ui->le_classification->setText("默认");
    ui->det_aT->setDateTime(QDateTime::currentDateTime());
    ui->dte_sT->setDateTime(QDateTime::currentDateTime());
    ui->le_taskname->clear();
    ui->cb_priority->setCurrentIndex(1);
}

string modSchedule::getTaskname(){
    QString Qtaskname=ui->le_taskname->text();
    return qstr2str(Qtaskname);
}

string modSchedule::getClassfication(){
    QString Qtaskname=ui->le_classification->text();
    return qstr2str(Qtaskname);
}

time_t modSchedule::getAlertTime(){
    QDateTime QAlertTime =ui->det_aT->dateTime();
    return QAlertTime.toTime_t();
}

time_t modSchedule::getStartTime(){
    QDateTime QStartTime =ui->dte_sT->dateTime();
    return QStartTime.toTime_t();
}

int modSchedule::getPriority(){
    return (ui->cb_priority->currentIndex()+1);
}


void modSchedule::on_btn_checkMod_clicked()
{
    bool flag=true;
    QDateTime QAlertTime =ui->det_aT->dateTime();
    QDateTime QStartTime =ui->dte_sT->dateTime();
    QDateTime QPresentTime =QDateTime::currentDateTime();
    if(QAlertTime>QStartTime){
        if(QMessageBox::No==QMessageBox::question(NULL,"warning","提醒时间大于开始时间，是否修改日程")){
            flag=false;
        }
    }
    if(QPresentTime>QStartTime){
        if(QMessageBox::No==QMessageBox::question(NULL,"warning","开始时间早于当前时间，是否修改日程")){
            flag=false;
        }
    }
    if(flag){
        emit sendClickMod();
    }
}
