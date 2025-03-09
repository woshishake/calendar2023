#include "pagelogin.h"
#include "ui_pagelogin.h"
#include<iostream>

PageLogin::PageLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageLogin),userList()
{
    ui->setupUi(this);

    auto SignUpFunc=[&](){
        QString QUsername=signUpPage.getUsername();
        QString QPassword=signUpPage.getPassword();
        string username=qstr2str(QUsername);
        if(!userList.checkUser(username)){
            string password=qstr2str(QPassword);
            string pWord=md5(password);
            userList.addUser(username,pWord);
            QMessageBox::information(&signUpPage,"提示","成功注册用户");
            loginUser=username;
            scheduleList tmp(username);
            tmp.saveFile();
            userList.saveUserFile();
            signUpPage.close();
        }
        else{
            QMessageBox::information(&signUpPage,"错误","存在相同用户");
        }
     };
    connect(&signUpPage,&signUp::sendSignUpMessage,this,SignUpFunc);
}

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::on_btn_login_clicked()
{
    QString QUsername=ui->line_username->text();
    QString QPassword=ui->line_password->text();
    string username=qstr2str(QUsername);
    //失败提示
    if(!userList.checkUser(username)){
        QMessageBox::information(this,"错误","用户不存在");
    }
    else{
        string password=qstr2str(QPassword);
        string pWord=md5(password);
        if(userList.checkPassword(username,pWord)){
            //成功进入主界面
            QMessageBox::information(this,"提示","登陆成功");
            loginUser=username;
            emit sendLoginSuccess();
        }
        else{
            QMessageBox::information(this,"错误","密码错误");
        }
    }

}

string PageLogin::getUser(){
    return loginUser;
}

void PageLogin::on_pushButton_2_clicked()
{
    //退出
    exit(0);
}

void PageLogin::on_btn_create_clicked()
{
    signUpPage.show();
}
