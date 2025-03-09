#ifndef PAGELOGIN_H
#define PAGELOGIN_H

#include <QWidget>
#include "signup.h"
#include "user.h"
#include "qstrans.h"
#include "schedule.h"

namespace Ui {
class PageLogin;
}

class PageLogin : public QWidget
{
    Q_OBJECT

public:
    explicit PageLogin(QWidget *parent = 0);
    string getUser();
    ~PageLogin();

private slots:
    void on_btn_login_clicked();
    void on_pushButton_2_clicked();
    void on_btn_create_clicked();

signals:
    void sendLoginSuccess();

private:
    Ui::PageLogin *ui;
    signUp signUpPage;
    user userList;
    string loginUser;
};

#endif // PAGELOGIN_H
