#include "delschedule.h"
#include "ui_delschedule.h"

delSchedule::delSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delSchedule)
{
    ui->setupUi(this);

}

delSchedule::~delSchedule()
{
    delete ui;
}

void delSchedule::on_pushButton_2_clicked()
{
    ui->le_delID->clear();
    this->close();
}

void delSchedule::on_btn_checkDel_clicked()
{
    emit sendClickDel();
}

int delSchedule::getID(){
    string a =qstr2str(ui->le_delID->text());
    return stoi(a);
}

