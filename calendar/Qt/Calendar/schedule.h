#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <time.h>
#include <cstring>
#include <map>
#include <utility>
#include <iomanip>
#include<string>
#include <QMessageBox>
#include <QString>
#include "qstrans.h"
#include <QTableWidget>
#include <QDateTime>
using namespace std;

class scheduleList{
private:
    struct schedule
    {
        string username;
        string taskname; // 储存的taskname中不能含有空格
        time_t alertTime;
        time_t startTime;
        int priority; // 用数字1-3描述优先级，3为最高，1为最低
        int id;
        string classification;


        schedule(string name,time_t aT,time_t sT, int number, int prio, string cla) : priority(prio)
        {
            taskname=name;
            classification=cla;
            alertTime = aT;
            startTime = sT;
            id = number;
        }
    };
    string username;
    int taskNumber;
    map<long int,schedule> taskList;
public:
    scheduleList(string username);
    void loadFile();
    void saveFile();
    void addTask(string name,time_t aT,time_t sT,int prio,string cla,int number=0);
    bool isUniqueTime(long int time);
    void delTask(int id,bool flag=true);
    bool isExistId(int id);
    void getInfo(int id,string &task,time_t &sT,time_t &aT,int &prio,string &classifi);
    time_t getStartTime(int id);
    void addStatic(QTableWidget *&table,QString Qtaskname,QString Qclassifi,int priority,time_t time1,time_t time2);

};

#endif // SCHEDULE_H
