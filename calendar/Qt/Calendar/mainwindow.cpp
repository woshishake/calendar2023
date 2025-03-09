#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
    QDate date1(1900,1,1);
    QDate date2(2038,1,1);
    ui->time1->setDate(date1);
    ui->time2->setDate(date2);
    m_dlgLogin.show();
    QString QUsername;
    string username;
    auto f= [&](){
      this->show();
        username=m_dlgLogin.getUser();
        QUsername=str2qstr(username);
        m_dlgLogin.close();
        ui->label_user->setText(QUsername);
    };

    auto f2=[&](){
        QUsername=ui->label_user->text();
        string username2=qstr2str(QUsername);
        scheduleList sh(username2);
        sh.loadFile();
        string taskname=addPage.getTaskname();
        string classification=addPage.getClassfication();
        time_t aT=addPage.getAlertTime();
        time_t sT=addPage.getStartTime();
        int prio=addPage.getPriority();
        if(sh.isUniqueTime(sT)){
            sh.addTask(taskname,aT,sT,prio,classification);
        }
        else{
            QMessageBox::critical(NULL,"错误","存在相同开始时间日程");
        }
        sh.saveFile();
    };

    auto f3=[&](){
        QUsername=ui->label_user->text();
        string username2=qstr2str(QUsername);
        scheduleList sh(username2);
        sh.loadFile();
        int id=delPage.getID();
        sh.delTask(id);
        sh.saveFile();
    };

    auto f4=[&](){
        QUsername=ui->label_user->text();
        string username2=qstr2str(QUsername);
        scheduleList sh(username2);
        sh.loadFile();
        int id=modPage.getID();
        bool flag=sh.isExistId(id);
        if(flag){
            string task,classifi;
            time_t aT,sT;
            int prio;
            sh.getInfo(id,task,sT,aT,prio,classifi);
            modPage.editTaskname(task);
            modPage.editClassification(classifi);
            modPage.editAT(aT);
            modPage.editST(sT);
            modPage.editPriority(prio);
        }
        else{
            modPage.clear();
        }
        sh.saveFile();
    };

    auto f5=[&](){
        QUsername=ui->label_user->text();
        string username2=qstr2str(QUsername);
        scheduleList sh(username2);
        sh.loadFile();
        int id=modPage.getID();
        bool flag=sh.isExistId(id);
        if(flag){
            string taskname=modPage.getTaskname();
            string classification=modPage.getClassfication();
            time_t aT=modPage.getAlertTime();
            time_t sT=modPage.getStartTime();
            int prio=modPage.getPriority();
            if((sh.isUniqueTime(sT))||(sT==sh.getStartTime(id))){
                sh.delTask(id,false);
                sh.addTask(taskname,aT,sT,prio,classification,id);
                QMessageBox::information(NULL,"提示","成功修改日程");
            }
            else{
                QMessageBox::critical(NULL,"错误","存在相同开始时间日程");
            }
        }
        else{
            QMessageBox::critical(NULL,"错误","日程id不存在");
        }
        sh.saveFile();
    };

    connect(&m_dlgLogin,&PageLogin::sendLoginSuccess,this,f);
    connect(&addPage,&addSchedule::sendClickAdd,this,f2);
    connect(&delPage,&delSchedule::sendClickDel,this,f3);
    connect(&modPage,&modSchedule::finishEditId,this,f4);
    connect(&modPage,&modSchedule::sendClickMod,this,f5);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_btn_add_clicked()
{
    addPage.show();
}

void MainWindow::on_btn_mod_clicked()
{
    modPage.show();
}

void MainWindow::on_btn_del_clicked()
{
    delPage.show();
}

void MainWindow::on_btn_check_clicked()
{
    QString Qtaskname=ui->line_taskname->text();
    QString Qclassifi=ui->line_classification->text();
    int prio=ui->comboBox->currentIndex();
    QDateTime QTime1=ui->time1->dateTime();
    QDateTime QTime2=ui->time2->dateTime();
    time_t time_1 =QTime1.toTime_t();
    time_t time_2 =QTime2.toTime_t();

    QDate date1(1900,1,1);
    QDate date2(2038,1,1);
    ui->time1->setDate(date1);
    ui->time2->setDate(date2);
    ui->line_classification->clear();
    ui->line_taskname->clear();
    ui->comboBox->setCurrentIndex(0);
    QString QUsername=ui->label_user->text();
    string username2=qstr2str(QUsername);
    scheduleList sh(username2);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    sh.loadFile();
    sh.addStatic(ui->tableWidget,Qtaskname,Qclassifi,prio,time_1,time_2);

}



void MainWindow::on_pushButton_2_clicked()
{
    QString QUsername=ui->label_user->text();
    string username2=qstr2str(QUsername);
    user userList;
    userList.deleteUser(username2);
    userList.saveUserFile();
    QMessageBox::information(NULL,"提示","注销成功");
    this->close();
    exit(0);
}
