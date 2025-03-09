#include "signup.h"
#include "ui_signup.h"

signUp::signUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);


}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_btn_checkSignUp_clicked()
{
    QString name=ui->line_username->text();
    QString name1=ui->line_password->text();
    QString name2=ui->line_password2->text();
    bool flag=true;
    if(!QString::compare(name,"")){
        flag=false;
        QMessageBox::information(this,"错误","用户名为空");
    }
    if(!QString::compare(name1,"")){
        flag=false;
        QMessageBox::information(this,"错误","密码为空");
    }
    if(flag)
    {
        if(!QString::compare(name1,name2)){
            emit sendSignUpMessage();
            ui->line_password->clear();
            ui->line_password2->clear();
            ui->line_username->clear();
        }
        else{
            QMessageBox::information(this,"错误","两次输入密码不同");
        }
    }
}

QString signUp::getUsername(){
    return ui->line_username->text();
}

QString signUp::getPassword(){
    return ui->line_password->text();
}
