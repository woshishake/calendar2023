#ifndef _SCHEDULE_H
#define _SCHEDULE_H
#include <iostream>
#include <time.h>
#include <cstring>
#include <map>
#include <utility>
#include <iomanip>
using namespace std;

/*
注意类和schedule中的数组储存长度，其中一个英文字符一个字节，一个utf-8三字节计算，即“阿巴阿巴”算为 const char[13]
*/

/*
使用三种储存时间结构的方式：
1.tm结构体，
2.longInt类型，具体形式为yyymmddhhmm，yyy为距离1900年年数，dd为月数-1，其余正常表达，例如 2023-6-30 1：08 转换为12305300108
3.正常五个整数表示 例如：year 2023 month 6 day 30 hour 1 minutes 8
*/

//-------------------------------------------------------------------------------------------------------------------
//关于时间处理的函数

//方式三（正常时间）转换为方式一（tm结构体）
//注意事项 info必须为已经分配内存的指针
void getTime(tm *&info, int year, int month, int day, int hour, int minutes);

//方式三（正常时间）转方式二（long int)
//返回转换后longint
long int getLongIntTime(int y2, int m2, int d2, int h2, int mi2);

//方式一转方式二
//返回转换后longint
long int getLongIntTime(tm *info);

//方式二转方式一
//返回tm结构体
tm getTmTime(long int longIntTime);

//比较两个tm结构体时间大小，time1>time2则返回true
bool compareTime(tm *time1, tm *time2);

//打印tm结构体储存的时间信息
void printTime(tm *info);

//----------------------------------------------------------------------------------------------------------------------------

class scheduleList
{
private:
    // 单个日程结构体
    struct schedule
    {
        char taskname[31]; // 储存的taskname中不能含有空格
        struct tm *alertTime;
        struct tm *startTime;
        int priority; // 用数字1-3描述优先级，3为最高，1为最低
        int id;
        char classification[22];

        schedule(char *name, int y1, int m1, int d1, int h1, int mi1, int y2, int m2, int d2, int h2, int mi2, int number, int prio, char *cla) : priority(prio)
        {
            strcpy(taskname, name);
            strcpy(classification, cla);
            alertTime = new tm;
            startTime = new tm;
            getTime(alertTime, y1, m1, d1, h1, mi1);
            getTime(startTime, y2, m2, d2, h2, mi2);
            id = number;
        }
        //在析构函数中再次delete *tm会导致多次释放相同内存报错
        // ~schedule(){
        //     delete alertTime;
        //     delete startTime;
        // } 
    };
    char username[22];//储存用户信息
    char scheduleFile[40];//文件名称
    map<long int, schedule> taskList;//任务列表  储存的pair内容为：<开始时间，对应日程结构体>
    map<long int, int> alertList;//提醒时间列表  储存的pair内容为： <提醒时间，提醒时间对应任务数量>
    int taskNumber;//任务数

public:

    //构造函数，用用户名创建日程列表
    scheduleList(char *user);

    //增加日程
    //参数：name任务名称 y1-mi1分别为提醒时间的年月日时分， y2-mi2为开始时间， prio为优先级，cla为分类， number为id（用户增加文件时作为缺省值，load文件时用于载入id）
    void addTask(char *name, int y1, int m1, int d1, int h1, int mi1, int y2, int m2, int d2, int h2, int mi2, int prio = 2, char *cla = "默认", int number = 0,bool flag=true);
    //根据id删除日程以及对应提醒时间
    void deleteTask(int number);

    //查找函数
    //根据id查找，返回值为id对应任务longint类型 开始时间 ， Flag=true时，开启文字显示及错误提醒，并且打印查找到的日程 Flag=faslse，只返回longint，无任何打印信息
    long int findTaskById(int number, bool Flag=true,bool Qflag=true);
    //根据开始时间查找，并且打印查找到的日程
    void findTaskByStartTime(long int Time);
    //通过名字查找，并且打印查找到的日程
    void findTaskByName(char *name);
    //通过提醒时间查找
    void findTaskByAlertTime(long int Time);
    //根据优先级查找，并打印查到的日程
    bool findTaskByPriority(int prio,bool Qflag);
    //根据分类查找，并打印查到的日程
    void findTaskByClass(char *classification);
    
    //遍历输出所有日程（以开始时间升序）
    void displayTask();
    //遍历输出制定日期 min-max之间的日程
    //参数：flagTime:输出提醒“查看min至max的日程”； flagHead：输出表头； flagTail： 末尾增加空行
    void displayTask(long int min, long int max, bool flagTime = true, bool flagHead = true, bool flagTail = true);
    //查看是否存在开始时间为time的日程，若存在，返回false
    bool isUniqueTime(long int time);

    //返回下一个提醒时间
    long int nextAlert();
    //输出提醒时间列表及对应日程数量
    void displayAlert();
    //删除提醒时间
    void deleteAlertByAT(long int alertTime);
    //按开始时间删除提醒时间
    void deleteAlert(long int startTime);

    //保存文件
    void saveFile();
    //加载文件,flag=true时打印加载信息;
    void loadFile(bool flag=true);

    int displayTaskRid(bool flag);
};

//--------------------------------------------------------------------------------------------------------------

#endif // !_SCHEDULE_H
