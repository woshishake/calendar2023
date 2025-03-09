#include "addschedule.h"
#include "ui_addschedule.h"

addSchedule::addSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addSchedule)
{
    ui->setupUi(this);
    ui->le_classification->setText("默认");
    ui->cb_priority->setCurrentIndex(1);
    ui->det_aT->setDateTime(QDateTime::currentDateTime());
    ui->dte_sT->setDateTime(QDateTime::currentDateTime());
}

addSchedule::~addSchedule()
{
    delete ui;
}

void addSchedule::on_pushButton_2_clicked()
{
    ui->le_classification->setText("默认");
    ui->le_taskname->clear();
    ui->cb_priority->setCurrentIndex(1);
    ui->det_aT->setDateTime(QDateTime::currentDateTime());
    ui->dte_sT->setDateTime(QDateTime::currentDateTime());
    this->close();
}

void addSchedule::on_pushButton_clicked()
{
    bool flag=true;
    QDateTime QAlertTime =ui->det_aT->dateTime();
    QDateTime QStartTime =ui->dte_sT->dateTime();
    QDateTime QPresentTime =QDateTime::currentDateTime();
    if(QAlertTime>QStartTime){
        if(QMessageBox::No==QMessageBox::question(NULL,"warning","提醒时间大于开始时间，是否添加日程")){
            flag=false;
        }
    }
    if(QPresentTime>QStartTime){
        if(QMessageBox::No==QMessageBox::question(NULL,"warning","开始时间早于当前时间，是否添加日程")){
            flag=false;
        }
    }
    if(flag){
        emit sendClickAdd();
    }

}

string addSchedule::getTaskname(){
    QString Qtaskname=ui->le_taskname->text();
    return qstr2str(Qtaskname);
}

string addSchedule::getClassfication(){
    QString Qtaskname=ui->le_classification->text();
    return qstr2str(Qtaskname);
}

time_t addSchedule::getAlertTime(){
    QDateTime QAlertTime =ui->det_aT->dateTime();
    return QAlertTime.toTime_t();
}

time_t addSchedule::getStartTime(){
    QDateTime QStartTime =ui->dte_sT->dateTime();
    return QStartTime.toTime_t();
}

int addSchedule::getPriority(){
    return (ui->cb_priority->currentIndex()+1);
}
