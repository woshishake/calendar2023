#ifndef DELSCHEDULE_H
#define DELSCHEDULE_H

#include <QWidget>
#include <qstrans.h>

namespace Ui {
class delSchedule;
}

class delSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit delSchedule(QWidget *parent = 0);
    int getID();
    ~delSchedule();

private slots:
    void on_pushButton_2_clicked();
    void on_btn_checkDel_clicked();

signals:
    void sendClickDel();
private:
    Ui::delSchedule *ui;
};

#endif // DELSCHEDULE_H
