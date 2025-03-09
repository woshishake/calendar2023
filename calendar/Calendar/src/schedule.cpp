#include "schedule.h"
using namespace std;

// 构造函数
scheduleList::scheduleList(char *user)
{
    // 初始化姓名&任务数量
    strcpy(username, user);
    cout << "succesfully create schedualList for user " << username << endl;
    taskNumber = 1;
    strcpy(scheduleFile, username);
    strcat(scheduleFile, "_tasks");
    cout << "尝试载入日程： " << scheduleFile << endl;
}

// 添加任务
void scheduleList::addTask(char *name, int y1, int m1, int d1, int h1, int mi1, int y2, int m2, int d2, int h2, int mi2, int prio, char *cla, int number, bool flag)
{
    // 赋值缺省id
    bool isInsert = !number;
    if (!number)
    {
        number = taskNumber;
    }
    // 创建日程
    schedule tmp(name, y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2, number, prio, cla);
    long int a = getLongIntTime(y2, m2, d2, h2, mi2);
    long int b = getLongIntTime(y1, m1, d1, h1, mi1);
    // 插入+判断是否插入成功
    pair<map<long int, schedule>::iterator, bool> InsertPair1;
    pair<map<long int, int>::iterator, bool> InsertPair2;
    InsertPair1 = taskList.insert(pair<long int, schedule>(a, tmp)); // 日程列表
    int taskNumberAlert = 0;
    for (auto it : taskList)
    {
        if (b == getLongIntTime(it.second.alertTime))
        {
            taskNumberAlert++;
        }
    }
    alertList.erase(b);
    InsertPair2 = alertList.insert(pair<long int, int>(b, taskNumberAlert)); // 提醒列表
    if (InsertPair1.second)
        if (flag)
            cout << "成功添加日程： " << name << endl;
    if (InsertPair2.second)
        if (flag)
            cout << "成功将日程: " << name << "加入提醒列表" << endl;
    if (isInsert)
    {
        cout << "分配id: " << taskNumber << endl;
        taskNumber++;
    }
}

// 遍历任务
void scheduleList::displayTask()
{
    // 列表为空
    cout << endl;
    if (taskList.empty())
    {
        cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t"
             << "优先级" << endl;
        cout << "列表为空" << endl;
        cout << endl;
        return;
    }
    // 列表非空
    long int min = taskList.begin()->first;
    long int max = taskList.rbegin()->first;
    displayTask(min, max, false);
    // cout << taskList.begin()->first << " " << taskList.rbegin()->first << endl;
    return;
}

// 按日程遍历
void scheduleList::displayTask(long int min, long int max, bool flagTime, bool flagHead, bool flagTail)
{

    // cout<<min<<" "<<max<<endl;

    // 打印时间说明
    if (flagTime)
    {
        struct tm minTime = getTmTime(min);
        struct tm maxTime = getTmTime(max);
        cout << "查看 ";
        printTime(&minTime);
        if (min != max)
        {
            cout << " 至 ";
            printTime(&maxTime);
        }
        cout << " 的日程: " << endl;
    }
    // 打印表头
    if (flagHead)
    {
        cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t" << std::left << std::setw(15)
             << "优先级" << endl;
    }
    // 遍历
    bool flag = false;
    for (auto it : taskList)
    {
        if ((it.first >= min) && (it.first <= max))
        {
            flag = true;
            cout << it.second.id << "\t" << std::left << std::setw(15) << it.second.taskname << "\t";

            printTime(it.second.alertTime);
            cout << "\t\t";
            printTime(it.second.startTime);
            cout << "\t\t\t" << std::left << std::setw(15) << it.second.classification << "\t";
            if (sizeof(it.second.classification) < 9)
            {
                cout << "\t" << endl;
            }
            switch (it.second.priority)
            {
            case 1:
                cout << "低" << endl;
                break;

            case 2:
                cout << "中" << endl;
                break;

            case 3:
                cout << "高" << endl;
                break;
            }
        }
    }
    // 无符合条件日程，输出 无
    if (!flag)
    {
        cout << "无" << endl;
    }
    // 打印末尾空白段
    if (flagTail)
        cout << endl;
    return;
}

int scheduleList::displayTaskRid(bool flag)
{
    if(flag)cout << endl;
    // 列表为空
    if (taskList.empty())
    {
        if(flag)
        {
            cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t"
             << "优先级" << endl;
            cout << "列表为空" << endl;
            cout << endl;
        }
        return -1;
    }
    // 列表非空
    long int min = taskList.begin()->first;
    long int max = taskList.rbegin()->first;
    if(flag)displayTask(min, max, false);
    // cout << taskList.begin()->first << " " << taskList.rbegin()->first << endl;
    int x=-1;
    for (auto it : taskList)
    {
    if(x< it.second.id)x= it.second.id;
    }
    return x;
}

// 按id查找
long int scheduleList::findTaskById(int number, bool Flag,bool Qflag)
{
    bool flag = false; // 判断是否存在
    long int result = 0;
    // 打印查找信息
    if (Flag&&Qflag)
    {
        cout << "查看id为 " << number << " 的日程" << endl;
    }
    // 遍历
    for (auto it : taskList)
    {
        if (it.second.id == number)
        {
            if (!Flag)
            {
                return it.first;
            }
            displayTask(it.first, it.first, false,Qflag,Qflag);
            result = it.first;
            flag = true;
        }
    }
    if (!flag&&Qflag)
    {
        cout << "错误：日程不存在！\n"
             << endl;
        return 0;
    }
    return result;
}

// 按开始时间查找
void scheduleList::findTaskByStartTime(long int Time)
{
    if (isUniqueTime(Time)) // 判断不存在
    {
        struct tm time = getTmTime(Time);
        cout << "查看 ";
        printTime(&time);
        cout << " 的日程: " << endl;
        cout << "错误：日程不存在！" << endl;
        cout << endl;
        return;
    }
    displayTask(Time, Time); // 打印信息
    return;
}

// 按名字查找
void scheduleList::findTaskByName(char *name)
{
    bool flag = false;      // 是否查找到日程
    bool flagMulti = false; // 是否需要多行打印（多行需要第一行输出表头，中间行不输出空行，最后一行输出空行）
    cout << "查看名称为 " << name << " 的日程" << endl;
    // 遍历查找
    for (auto it : taskList)
    {
        if (!strcmp(it.second.taskname, name))
        {
            displayTask(it.first, it.first, false, !flagMulti, false);
            flag = true;
            flagMulti = true;
        }
    }
    if (!flag)
    {
        cout << "错误：日程不存在！\n"
             << endl;
    }
    if (flag)
        cout << endl;
    return;
}

// 按分类查找
void scheduleList::findTaskByClass(char *classification)
{
    bool flag = false;      // 是否查找到日程
    bool flagMulti = false; // 是否需要多行打印（多行需要第一行输出表头，中间行不输出空行，最后一行输出空行）
    cout << "查看分类为 " << classification << " 的日程" << endl;
    // 遍历查找
    for (auto it : taskList)
    {
        if (!strcmp(it.second.classification, classification))
        {
            displayTask(it.first, it.first, false, !flagMulti, false);
            flag = true;
            flagMulti = true;
        }
    }
    if (!flag)
    {
        cout << "错误：日程不存在！\n"
             << endl;
    }
    if (flag)
        cout << endl;
    return;
}

// 按照优先级查找
bool scheduleList::findTaskByPriority(int prio,bool Qflag)
{
    bool flag = false;      // 是否查找到日程
    bool flagMulti = false; // 是否需要多行打印（多行需要第一行输出表头，中间行不输出空行，最后一行输出空行）
    if(Qflag){cout << "查看优先级为 " ;
    switch (prio)
    {
    case 1:
        cout << "低";
        break;
    case 2:
        cout << "中";
        break;
    case 3:
        cout << "高";
        break;
    }
    cout << " 的日程" << endl;}
    // 遍历查找
    for (auto it : taskList)
    {
        if (it.second.priority==prio)
        {
            displayTask(it.first, it.first, false, false, false);
            flag = true;
            flagMulti = true;
        }
    }
    if (!flag&&Qflag)
    {
        cout << "错误：日程不存在！\n"
             << endl;
    }
    if (flag&&Qflag)
        cout << endl;
    return flag;
}

// 按提醒时间查找
void scheduleList::findTaskByAlertTime(long int time)
{
    {
        bool flag = false;      // 是否查找到日程
        bool flagMulti = false; // 是否需要多行打印（多行需要第一行输出表头，中间行不输出空行，最后一行输出空行）
        // 打印信息
        cout << "提醒时间为 ";
        struct tm tmp = getTmTime(time);
        printTime(&tmp);
        cout << " 的日程" << endl;
        // 遍历查找
        for (auto it : taskList)
        {
            if (time == getLongIntTime(it.second.alertTime))
            {
                displayTask(it.first, it.first, false, !flagMulti, false);
                flag = true;
                flagMulti = true;
            }
        }
        if (!flag)
        {
            cout << "错误：日程不存在！\n"
                 << endl;
        }
        if (flag)
            cout << endl;
        return;
    }
}

// 查看是否存在开始时间为time的日程
bool scheduleList::isUniqueTime(long int time)
{
    bool flag = true;
    for (auto it : taskList)
    {
        if (it.first == time)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

// 删除日程
void scheduleList::deleteTask(int number)
{
    cout << "删除id为 " << number << " 的日程" << endl;
    // 查找是否存在，输出错误信息
    long int time = findTaskById(number, false);
    bool isDeleted = false;
    if (time) // 日程不存在time=0
    {
        deleteAlert(time);
        isDeleted = taskList.erase(time); // 成功删除返回1
    }
    if (isDeleted)
    {
        cout << "删除成功" << endl;
        cout << endl;
    }
    return;
}

// 获取下一个提醒时间
long int scheduleList::nextAlert()
{
    return alertList.begin()->first;
}

// 打印提醒列表及对应日程数量
void scheduleList::displayAlert()
{
    cout << "提醒时间表： " << endl;
    bool flag = false;
    for (auto it : alertList)
    {
        struct tm tmp = getTmTime(it.first);
        printTime(&tmp);
        cout << " 共" << it.second << " 个日程";
        cout << endl;
        flag = true;
    }
    if (!flag)
    {
        cout << "无日程" << endl;
    }
    cout << endl;
    return;
}

// 按开始时间删除提醒时间列表
void scheduleList::deleteAlert(long int startTime)
{
    if (!isUniqueTime(startTime))
    {
        // displayAlert();
        long int alertTime = getLongIntTime(taskList.find(startTime)->second.alertTime); // 查找开始时间查找提醒时间
        // 若提醒时间对应任务>1，则任务数-1重新存入，否则直接删除
        map<long int, int>::iterator iter;
        iter = alertList.find(alertTime);
        if (iter != alertList.end())
        {
            int taskNumberAlert = alertList.find(alertTime)->second;
            taskNumberAlert--;
            alertList.erase(alertTime);
            if (taskNumberAlert)
            {
                alertList.insert(pair<long int, int>(alertTime, taskNumberAlert));
            }
        }
        // displayAlert();
    }
    return;
}

void scheduleList::deleteAlertByAT(long int alertTime)
{
    alertList.erase(alertTime);
    return;
}

// 保存文件
void scheduleList::saveFile()
{
    char filename[45] = "./file/task/";
    strcat(filename, username);
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        cout << "错误：创建/保存文件失败，无法创建/打开文件" << endl
             << endl;
        return;
    }
    long int alertTime; // 时间按照longint储存
    for (auto it : taskList)
    {
        alertTime = getLongIntTime(it.second.alertTime);
        fprintf(fp, "%d %s %ld %ld %s %d\n", it.second.id, it.second.taskname, alertTime, it.first, it.second.classification, it.second.priority);
    }
    cout << "成功保存 " << username << "的日程" << endl
         << endl;
    fclose(fp);
    return;
}

// 读取文件
void scheduleList::loadFile(bool flag)
{
    char filename[45] = "./file/task/";
    strcat(filename, username);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        cout << "错误：读取文件失败，无法打开文件" << endl;
        return;
    }
    char taskname[31];
    long int alertTime, startTime;
    int y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2;
    int id;
    int priority;
    char classification[22];
    // 循环读取
    while (!feof(fp))
    {
        int pout = fscanf(fp, "%d %s %ld %ld %s %d\n", &id, taskname, &alertTime, &startTime, classification, &priority);
        if (pout == EOF)
        {
            if (flag)
                cout << "成功读取空白文档" << endl;
            break;
        }
        else if (pout != 6) // pout为scanf正确读取内容数量
        {
            cout << "错误：文件无法正确读取" << endl;
            return;
        }
        y1 = (long int)alertTime / (long int)(100000000) + 1900;
        m1 = ((long int)alertTime / 1000000) % 100 + 1;
        d1 = ((long int)alertTime / 10000) % 100;
        h1 = ((long int)alertTime / 100) % 100;
        mi1 = (long int)alertTime % 100;
        y2 = (long int)startTime / (long int)(100000000) + 1900;
        m2 = ((long int)startTime / 1000000) % 100 + 1;
        d2 = ((long int)startTime / 10000) % 100;
        h2 = ((long int)startTime / 100) % 100;
        mi2 = (long int)startTime % 100;
        // 时间格式化
        addTask(taskname, y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2, priority, classification, id, flag);
        if (id >= taskNumber)
        {
            taskNumber = id + 1;
        } // 刷新taskNumber，
    }
    fclose(fp);
    return;
}

//--------------------------------------------------------------------------------------------

// 一系列时间转换

// 时间转换 存入info
void getTime(tm *&info, int year, int month, int day, int hour, int minutes)
{
    // time_t rawtime;
    // struct tm *tmp;
    // time(&rawtime);
    // tmp=localtime(&rawtime);
    struct tm tmp;
    memset(info, 0, sizeof(tmp));
    info->tm_year = year - 1900;
    info->tm_mon = month - 1;
    info->tm_mday = day;
    info->tm_hour = hour;
    info->tm_min = minutes;
    return;
}

long int getLongIntTime(int y2, int m2, int d2, int h2, int mi2)
{
    long int b = (long int)mi2 + (long int)h2 * 100 + (long int)d2 * 10000 + (long int)(m2 - 1) * 1000000 + (long int)(y2 - 1900) * (long int)(100000000);
    return b;
}

long int getLongIntTime(tm *info)
{
    long int b = (long int)(info->tm_min) + (long int)(info->tm_hour * 100) + (long int)(info->tm_mday * 10000) + (long int)(info->tm_mon * 1000000) + ((long int)(info->tm_year) * (long int)(100000000));
    return b;
}

tm getTmTime(long int longIntTime)
{
    struct tm tmp;
    memset(&tmp, 0, sizeof(tmp)); // tmp初始化
    tmp.tm_year = (long int)longIntTime / (long int)(100000000);
    tmp.tm_mon = ((long int)longIntTime / 1000000) % 100;
    tmp.tm_mday = ((long int)longIntTime / 10000) % 100;
    tmp.tm_hour = ((long int)longIntTime / 100) % 100;
    tmp.tm_min = (long int)longIntTime % 100;
    return tmp;
}

bool compareTime(tm *time1, tm *time2)
{
    // 将tm转换为time_t格式（距离1970年的秒数）进行比较
    bool flag = false;
    time_t T1, T2;
    T1 = mktime(time1);
    T2 = mktime(time2);
    return T1 > T2;
}

void printTime(tm *info)
{
    const char *weekday[] = {"周日", "周一", "周二", "周三", "周四", "周五", "周六"};
    char buf[36] = {0};
    strftime(buf, 36, "%Y-%m-%d %H:%M", info);
    mktime(info); // 获取星期信息

    printf("|%s %s|", buf, weekday[info->tm_wday]); // 自定义格式化输出
}