#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class signUp;
}

class signUp : public QWidget
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = 0);
    QString getUsername();
    QString getPassword();
    ~signUp();
signals:
    void sendSignUpMessage();
private slots:
    void on_btn_checkSignUp_clicked();

private:
    Ui::signUp *ui;

};

#endif // SIGNUP_H
