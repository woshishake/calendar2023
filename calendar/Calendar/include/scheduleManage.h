#ifndef _SCHEDULEMANAGE_H
#define _SCHEDULEMANAGE_H

#include"schedule.h"
#include<unistd.h>
#include<thread>
#include<mutex>
using namespace std;

//判断时间是否存在
bool isCorrectTime(int year,int month,int day,int hour,int minutes);

//判断字符数组是否均为整数
bool isInterger(char* input);



class scheduleManage{
    private:
        scheduleList s_list;
    public:
        scheduleManage(char *user);
        //（run）创建日程
        void createSchedule();
        //（命令行）添加日程
        void m_addTask(char *name, int y1, int m1, int d1, int h1, int mi1, int y2, int m2, int d2, int h2, int mi2,  int prio, char *cla);
        //（命令行）展示日程
        void m_display(long int min,long int max);
        //提醒函数
        void alert();
        //(run)日程管理
        void menu();
        //（run/命令行）删除日程
        void deleteSchedule(int id=0,bool flag=0);
        //（run）查找/打印日程
        void displaySchedule();

        //被displaySchedule调用的各种具体显示函数;
        void displayScheduleAll();
        void displayScheduleBytime();
        void displayScheduleByprio();
        void displayScheduleByname();
        void displayScheduleByid();
        void displayScheduleByclass();

};




#endif // !_SCHEDULEMANAGE_H
