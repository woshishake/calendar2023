#include "scheduleManage.h"

using namespace std;

mutex mtx;//全局锁

//构造函数
scheduleManage::scheduleManage(char *user) : s_list(user)
{
    char filename[45] = "./file/task/";
    strcat(filename, user);
    FILE *fp = fopen(filename, "a+");//如果没有文件，创建文件
    if (fp == NULL)
    {
        cout << "错误：创建/打开文件失败，无法创建/打开文件" << endl
             << endl;
        return;
    }
    fclose(fp);
    s_list.loadFile();//加载日程列表
    cout << endl;
    // s_list.displayTask();
}

//（run）创建日程
void scheduleManage::createSchedule()
{

    cout << "请输入日程信息,输入格式：[任务名称] [提醒时间] [开始时间]，时间格式为:yyyy-mm-dd hh:mm,如果需要退出请输入quit" << endl;
    //变量初始化
    char *taskname = new char[100];
    char *priority = new char();
    char *classification = new char[100];
    char quit[5] = "quit";
    char classfi[22] = "默认";//分类初始为“默认”
    int y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2;
    int prio = 2;//优先级初始赋值为2
    int pout;
    long int sT, aT, pT;
    bool flag = true;
    char clear;
    //循环读取日程直到日程读取正确
    while (flag)
    {
        scanf("%s", taskname);//读取任务名称
        //读取为quit则退出添加日程
        if (!strcmp(taskname, quit))
        {
            delete[] taskname;
            delete priority;
            delete[] classification;
            return;
        }
        //判断任务名称长度是否过长
        if (strlen(taskname) > 30)
        {
            cout << "任务名称过长，任务名称应为小于等于30个英文字符或小于等于10个中文字符，其中3个英文字符等于1个中文字符" << endl
                 << endl;
            //清除输入缓冲区
            while ((clear = getchar()) != '\n')
            {
            }
            cout << "请重新输入日程信息" << endl;
            continue;
        }
        //格式化读取日期
        pout = scanf("%d-%d-%d %d:%d %d-%d-%d %d:%d", &y1, &m1, &d1, &h1, &mi1, &y2, &m2, &d2, &h2, &mi2);//scanf返回值为正确读取个数
        while ((clear = getchar()) != '\n'){}
        //scanf未正确读取（输入格式有误）
        if (pout != 10)
        {
            cout << "日期格式错误" << endl
                 << endl;
            while ((clear = getchar()) != '\n')
            {
            }
            cout << "请重新输入日程信息" << endl;
            continue;
        }
        //时间格式的转换
        aT = getLongIntTime(y1, m1, d1, h1, mi1);
        sT = getLongIntTime(y2, m2, d2, h2, mi2);
        //当前时间的获取
        time_t preTime;
        struct tm *presentTime;
        time(&preTime);
        presentTime = localtime(&preTime);
        pT = getLongIntTime(presentTime);
        char Flag;
        //判断提醒时间是否存在
        if (!isCorrectTime(y1, m1, d1, h1, mi1))
        {
            cout << "提醒时间不存在" << endl
                 << endl;
            while ((clear = getchar()) != '\n')
            {
            }
            cout << "请重新输入日程信息" << endl;
            continue;
        }
        //判断开始时间是否存在
        if (!isCorrectTime(y2, m2, d2, h2, mi2))
        {
            cout << "开始时间不存在" << endl
                 << endl;
            while ((clear = getchar()) != '\n')
            {
            }
            cout << "请重新输入日程信息" << endl;
            continue;
        }
        //判断是否有相同开始时间日程
        if (!s_list.isUniqueTime(sT))
        {
            cout << "已存在相同开始时间日程，日程添加失败" << endl;
            while ((clear = getchar()) != '\n')
            {
            }
            continue;
        }
        //判断开始时间是否小于当前时间
        if (sT < pT)
        {
            cout << "日程开始时间小于当前时间，是否确定添加日程，输入y/n: ";
            cin >> Flag;
            while ((Flag != 'n') && (Flag != 'y'))
            {
                cout << "请输入y/n" << endl;
                cin >> Flag;
            }
            if (Flag == 'n')
            {
                while ((clear = getchar()) != '\n')
                {
                }
                cout << "请重新输入日程信息" << endl;
                continue;
            }
        }
        //判断提醒时间大于开始时间
        if (aT > sT)
        {
            cout << "日程提醒时间大于开始时间，是否确定添加日程，输入y/n: ";
            cin >> Flag;
            while ((Flag != 'n') && (Flag != 'y'))
            {
                cout << "请输入y/n" << endl;
                cin >> Flag;
            }
            if (Flag == 'n')
            {
                while ((clear = getchar()) != '\n')
                {
                }
                cout << "请重新输入日程信息" << endl;
                continue;
            }
        }
        //以上判断没问题，未被continue，则跳出循环
        flag = false;
    }

    //输入优先级
    cout << "是否改变日程优先级，输入n则默认为中，输入‘高’(h)’中‘(m)’低‘(l)改变优先级" << endl;
    bool flag2 = true;
    while (flag2)
    {
        cin >> priority;
        if (!strcmp(priority, quit))//是否为quit
        {
            delete[] taskname;
            delete priority;
            delete[] classification;
            return;
        }
        //n，低中高的判断
        if (!strcmp(priority, "n"))
        {
            break;
        }
        if ((!strcmp(priority, "高"))||(!strcmp(priority, "h")))
        {
            prio = 3;
            flag2 = false;
        }
        if ((!strcmp(priority, "低"))||(!strcmp(priority, "l")))
        {
            prio = 1;
            flag2 = false;
        }
        if ((!strcmp(priority, "中"))||(!strcmp(priority, "m")))
        {
            flag2 = false;
        }
        else
        {
            //输入内容不为n/低中高，则flag2=true
            if (flag2)
                cout << "请重新输入优先级（n/高(h)/中(m)/低(l)），或者输入quit取消创建日程" << endl;
        }
    }

    //输入日程分类
    cout << "是否改变日程分类，输入n则为默认，输入不多于7个中文字符/21个英文字符设置新分类名,输入quit取消创建日程" << endl;
    bool flag3 = true;
    while (flag3)
    {
        cin >> classification;
        if (!strcmp(classification, quit))//判断quit
        {
            delete[] taskname;
            delete priority;
            delete[] classification;
            return;
        }
        //判读分类长度是否过长
        if (strlen(classification) > 22)
        {
            cout << "分类名称过长，应为小于等于21个英文字符或小于等于7个中文字符，其中3个英文字符等于1个中文字符" << endl;
            while ((clear = getchar()) != '\n')
            {
            }
            cout << "请重新输入分类" << endl;
            continue;
        }
        flag3 = false;
    }
    //copy分类
    if(strcmp(classification,"n")!=NULL) strcpy(classfi, classification);

    //传入已处理好的参数
    s_list.addTask(taskname, y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2, prio, classfi);
    //保存日程文件
    s_list.saveFile();
    delete[] taskname;
    delete priority;
    delete[] classification;

    cout << endl;

    return;
}

//（命令行）添加日程
void scheduleManage::m_addTask(char *name, int y1, int m1, int d1, int h1, int mi1, int y2, int m2, int d2, int h2, int mi2, int prio, char *cla)
{
    bool isReturn = false;//是否返回，如果参数有错则isReturn为true
    //判断日程名称长度
    if (strlen(name) > 30)
    {
        cout << "任务名称过长，任务名称应为小于等于30个英文字符或小于等于10个中文字符，其中3个英文字符等于1个中文字符" << endl;
        isReturn = true;
    }
    //判断提醒时间和开始时间是否存在
    if (!isCorrectTime(y1, m1, d1, h1, mi1))
    {
        cout << "提醒时间不存在" << endl;
        isReturn = true;
    }
    if (!isCorrectTime(y2, m2, d2, h2, mi2))
    {
        cout << "开始时间不存在" << endl;
    }

    if (strlen(cla) > 22)
    {
        cout << "分类名称过长，应为小于等于21个英文字符或小于等于7个中文字符，其中3个英文字符等于1个中文字符" << endl;
        isReturn = true;
    }

    if (isReturn)
    {
        cout << "请重新添加日程" << endl;
        return;
    }

    long int sT, aT, pT;
    aT = getLongIntTime(y1, m1, d1, h1, mi1);
    sT = getLongIntTime(y2, m2, d2, h2, mi2);
    //获取系统时间
    time_t preTime;
    struct tm *presentTime;
    time(&preTime);
    presentTime = localtime(&preTime);
    localtime_r(&preTime, presentTime);
    pT = getLongIntTime(presentTime);

    if (!s_list.isUniqueTime(sT))
    {
        cout << "存在相同开始时间日程，日程添加失败" << endl;
        return;
    }
    if (sT < pT)
    {
        cout << "提示：日程开始时间小于当前时间" << endl;
    }
    if (aT > sT)
    {
        cout << "提示：日程提醒时间大于开始时间" << endl;
    }

    s_list.addTask(name, y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2, prio, cla);
    s_list.saveFile();
    return;
}

void scheduleManage::m_display(long int min, long int max)
{
    s_list.displayTask(min, max);
}

void scheduleManage::alert()
{
    bool flag = true;
    bool isAlert=false;
    while (true)
    {
        mtx.lock();
        // s_list.loadFile(false);
        isAlert=false;
        // cout<<"检查日程提醒: "<<endl;
        time_t preTime;
        time(&preTime);
        struct tm presentTime;
        localtime_r(&preTime, &presentTime);
        // cout<<presentTime.tm_hour<<":"<<presentTime.tm_min<<endl;
        long int pT, aT = 0;
        pT = getLongIntTime(&presentTime);
        aT = s_list.nextAlert();
        // cout<<aT<<endl;
        while ((aT < pT)&& (flag) )//
        {
            if(aT==0){break;}
            // s_list.displayAlert();
            s_list.deleteAlertByAT(aT);
            aT = s_list.nextAlert();
        }
        flag = false;
        while ((aT < pT) && (!flag)&&(aT!=0))
        {
            cout << "过期日程提醒： " << endl;
            // s_list.displayAlert();
            s_list.findTaskByAlertTime(aT);
            s_list.deleteAlertByAT(aT);
            aT = s_list.nextAlert();
            // cout<<aT<<endl;
        }

        if (pT == aT)
        {
            cout << "有当前日程提醒： ";
            isAlert=true;
            s_list.findTaskByAlertTime(aT);
            s_list.deleteAlertByAT(aT);
            aT = s_list.nextAlert();
        }
        // else{
        //     cout<<"无"<<endl;
        // }
        mtx.unlock();
        if(isAlert){
            sleep(60);
        }
        else{
            sleep(5);
        }
        
    }
}

void scheduleManage::deleteSchedule(int id, bool flag)

{
    char clear, confirm;
    int point;
    if (flag)
    {
        if (s_list.findTaskById(id))
        {
            s_list.deleteTask(id);
        }
        else
        {
            cout << "删除失败" << endl;
        }
    }
    else
        while (1)
        {
            cout << "输入将要删除日程的id：（输入0可退出程序）\n";
            point = scanf("%d", &id);
            while ((clear = getchar()) != '\n')
            {
            }
            if (point != 1)
            {
                cout << "id输入错误，id应为整数；（输入0可退出程序）\n";
                // while ((clear = getchar()) != '\n')
                // {
                // }
            }
            else
            {
                if (id == 0)
                    return; // 检测用户输入为0，退出
                if (s_list.findTaskById(id))
                {
                    cout << "是否确认删除目标任务（y/n）:\n";
                    // while ((confirm = getchar()) != '\n')
                    // {
                    // }
                    confirm = getchar();
                    confirm = tolower(confirm);
                    if (confirm == 'y')
                    {
                        s_list.deleteTask(id);
                        while ((confirm = getchar()) != '\n')
                        {
                        }
                        break;
                    }
                    if (confirm == 'n')
                    {
                        cout << "删除操作取消\n请重新输入";
                    }
                    while ((confirm = getchar()) != '\n')
                    {
                    }
                }

                cout << "请重新";
            }
        }

    s_list.saveFile();
}

void scheduleManage::menu()
{
    char command[40];
    bool flag = true;
    bool isCorrectCommand = false;
    cout << "请输入addtask/deletetask/displaytask/quit等命令." << endl;
    while (flag)
    {
        cin >> command;
        isCorrectCommand = false;
        if (!strcasecmp(command, "quit"))
        {
            isCorrectCommand = true;
            flag = false;
        }
        if (!strcasecmp(command, "addTask"))
        {
            isCorrectCommand = true;
            mtx.lock();
            createSchedule();
            mtx.unlock();
        }
        if (!strcasecmp(command, "deleteTask"))
        {
            isCorrectCommand = true;
            mtx.lock();
            deleteSchedule();
            mtx.unlock();
        }
        if (!strcasecmp(command, "displayTask"))
        {
            isCorrectCommand = true;
            mtx.lock();
            displaySchedule();
            mtx.unlock();
        }
        if (!isCorrectCommand)
        {
            cout << "无法识别的指令！请重新输入" << endl;
            cout<<endl;
        }
        if (flag)
            cout << "请输入menu指令：addtask/deletetask/displaytask/quit" << endl;
    }
}

void scheduleManage::displaySchedule()
{
    string choice;
    int ch;
    bool flag=1;
    char clear;
 while (1)
    {
        cout<<"----------------------------------------------"<<endl;
        cout << "选择显示方式：\n";
        cout<<"----------------------------------------------"<<endl;
             cout<< "输入all，可选择不同排序显示全部任务\n"
             << "输入prio，可选择按优先级搜索任务\n"
             << "输入class，可选择按分类搜索任务\n"
             << "输入id，可选择按id搜索任务\n"
             << "输入name，可选择通过名称搜索任务\n"
             << "输入time，可选择按时间搜索任务\n"
             << "输入quit，可选择退出程序：\n";
        cout<<"----------------------------------------------"<<endl;
     cin>>choice;
    //  cout<<choice;
     while ((clear = getchar()) != '\n'){}
     if(strcasecmp(choice.c_str(),"all")==0) 
        displayScheduleAll();
     else if(strcasecmp(choice.c_str(),"prio")==0) 
     displayScheduleByprio();
     else if(strcasecmp(choice.c_str(),"id")==0) 
        displayScheduleByid();
     else if(strcasecmp(choice.c_str(),"name")==0)
      displayScheduleByname();
     else if(strcasecmp(choice.c_str(),"time")==0)
     displayScheduleBytime();
     else if(strcasecmp(choice.c_str(),"class")==0) 
     displayScheduleByclass();
     else if(strcasecmp(choice.c_str(),"quit")==0) return;
     else {cout << "错误输入,请重新";continue;}
}
}

void scheduleManage::displayScheduleByprio()
{
   int choic, point;
   char clear;
   int x=-1;
   while(1)
   {
                cout<<"----------------------------------------------"<<endl;
               cout << "按优先级搜索任务：\n";
               cout<<"----------------------------------------------"<<endl;
                cout    << "输入1，可选择显示高优先级全部任务\n"
                    << "输入2，可选择显示中优先级全部任务\n"
                    << "输入3，可选择显示低优先级全部任务\n"
                    << "输入0，可选择退出程序：\n";
                    cout<<"----------------------------------------------"<<endl;
                    point = scanf("%d", &choic);
        while ((clear = getchar()) != '\n') {}
        if (point != 1)
        {
            cout << "选项输入错误，选项应为整数;\n";
            continue;
        }
        else
        {
            if(choic){cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t"
             << "优先级" << endl;}
            switch (choic)
            {
            case 3:
                s_list.findTaskByPriority(3,true);
                break;
            case 2:
               s_list.findTaskByPriority(2,true);
                break;
            case 1:
                s_list.findTaskByPriority(1,true);
                break;
            case 0:
                return;
            default:
                cout << "错误,请重新";
            }
   }
   }
}

void scheduleManage::displayScheduleByid()
{
   int  point;
   char clear;
   int id=-1;
   cout<<"----------------------------------------------"<<endl;
   cout << "按id搜索任务";
   cout<<"----------------------------------------------"<<endl;
   while(1)
   {
               cout << "输入将要搜索日程的id：(输入0退出程序)\n";
               cout<<"----------------------------------------------"<<endl;
                    point = scanf("%d", &id);
        while ((clear = getchar()) != '\n') {}
        if (point != 1)
        {
            cout << "id输入错误，id应为整数;\n";
            continue;
        }
        else
        {
                if (id == 0)
                    return; // 检测用户输入为0，退出
                if(s_list.findTaskById(id));
                else cout << "错误,请重新";
            }
   }
   }

void scheduleManage::displayScheduleByname()
{
   char *namechar;
   string name;
   char clear;
   cout<<"----------------------------------------------"<<endl;
   cout << "按任务名称搜索任务";
   cout<<"----------------------------------------------"<<endl;
   while(1)
   {
            cout << "输入将要搜索日程的名称：(输入quit退出程序)\n";
            cout<<"----------------------------------------------"<<endl;
            cin>>name;
         namechar=new char[name.length()+1];
         strcpy(namechar,name.data());
         while ((clear = getchar()) != '\n') {}
         if(strcasecmp(namechar,"quit")==0) 
        {
            delete [] namechar;
            return;
        }
          s_list.findTaskByName(namechar);
          delete [] namechar;
   }
   }

void scheduleManage::displayScheduleAll()
{
   int choic, point;
   char clear;
   int x=-1;
   bool flag=false;
   while(1)
   {
                cout<<"----------------------------------------------"<<endl;
               cout << "选择全部任务的显示方式：\n";
               cout<<"----------------------------------------------"<<endl;
                cout<< "输入1，可选择显示按优先级全部任务\n"
                    << "输入2，可选择按id显示全部任务\n"
                    << "输入3，可选择按时间显示全部任务\n"
                    << "输入0，可选择退出程序：\n";
                cout<<"----------------------------------------------"<<endl;
                    point = scanf("%d", &choic);
        while ((clear = getchar()) != '\n') {}
        if (point != 1)
        {
            cout << "选项输入错误，选项应为整数;\n";
            continue;
        }
        else
        {
            switch (choic)
            {
            case 3:
                s_list.displayTask();
                break;
            case 2:
            cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t"
             << "优先级" << endl;
                x=s_list.displayTaskRid(false);
                if(x==-1)cout<<"日程为空"<<endl;
                for(int i=1;i<=x;i++)s_list.findTaskById(i,1,0);
                break;
            case 1:
             cout << "id\t" << std::left << std::setw(15) << "日程名称\t\t"
             << "提醒时间\t\t\t"
             << "开始时间\t\t\t"
             << "分类\t\t"
             << "优先级" << endl;
                flag=true;
                for(int i=1;i<=3;i++)
                if(s_list.findTaskByPriority(i,false))flag=false;
                if(flag)cout<<"日程为空"<<endl;
                break;
            case 0:
                return;
            default:
                cout << "错误,请重新";
            }
   }
   }
}

void scheduleManage::displayScheduleByclass()
{
   char *classes;
   string cla;
   char clear;
   cout<<"----------------------------------------------"<<endl;
   cout << "按分类搜索任务"<<endl;
   cout<<"----------------------------------------------"<<endl;
   while(1)
   {
            cout << "输入将要搜索日程的分类：(输入quit退出程序)\n";
            cout<<"----------------------------------------------"<<endl;
            cin>>cla;
         classes=new char[cla.length()+1];
         strcpy(classes,cla.data());
         while ((clear = getchar()) != '\n') {}
         if(strcasecmp(classes,"quit")==0) 
         {
            delete [] classes;
            return;
         }
          s_list.findTaskByClass(classes);
          delete [] classes;
   }
   }

void scheduleManage::displayScheduleBytime()
{

    int choic, point;
    char clear;
    bool yun, flag = 1, ff;
    int year = 13, month = 13, day = 33;
    long a, b;
    while (1)
    {
        cout<<"----------------------------------------------"<<endl;
        cout << "选择按时间显示方式：\n";
        cout<<"----------------------------------------------"<<endl;
        cout<< "输入1，可选择显示某一年的全部任务\n"
             << "输入2，可选择显示某一月的全部任务\n"
             << "输入3，可选择显示某一天的全部任务\n"
             << "输入4，可选择显示某日至某日的全部任务\n"
             << "输入5，可选择显示全部任务\n"
             << "输入0，可选择退出按时间显示的程序：\n";
        point = scanf("%d", &choic);
        while ((clear = getchar()) != '\n')
        {
        }
        if (point != 1)
        {
            cout << "选项输入错误，选项应为整数;\n";
            continue;
        }
        else
        {
            switch (choic)
            {
            case 5:
                a = 0;
                b = 60000010000;
                break;
            case 0:
                cout << endl;
                return;
            case 4:
                cout << "输入开始日期（输入格式如2022 6 10）：\n";
                point = scanf("%d %d %d", &year, &month, &day);
                while ((clear = getchar()) != '\n')
                {
                }
                if (point == 3)
                {
                    yun = (year % 4 == 0 && year % 400 != 0);
                    ff = (year < 1900 || month < 1 || month > 12) || (month < 8 && day > 30 + month % 2) || (month > 7 && day > 31 - month % 2) || ((month == 2) && day > (yun + 28));
                    if (ff)
                    {
                        cout << "输入错误；返回\n";
                        continue;
                    }
                    a = getLongIntTime(year, month, day, 0, 0);
                    cout << "输入结束日期（输入格式如2022 6 10）：\n";
                    point = scanf("%d %d %d", &year, &month, &day);
                    while ((clear = getchar()) != '\n')
                    {
                    }
                }
                else
                {
                    cout << "输入错误;返回\n";
                    continue;
                }
                if (point == 3)
                {
                    yun = (year % 4 == 0 && year % 400 != 0) && (month == 2);
                    ff = (year < 1900 || month < 1 || month > 12) || (month < 8 && day > 30 + month % 2) || (month > 7 && day > 31 - month % 2) || ((month == 2) && day > (yun + 28));
                    if (ff)
                    {
                        cout << "输入错误；返回\n";
                        continue;
                    }
                    b = getLongIntTime(year, month, day, 25, 0);
                }
                else
                {
                    cout << "输入错误；返回\n";
                    continue;
                }
                if (a > b)
                {
                    cout << "输入错误；返回\n";
                    continue;
                }
                break;
            case 3:
                cout << "输入目标日期（输入格式如2022 6 10）：";
                point = scanf("%d %d %d", &year, &month, &day);
                while ((clear = getchar()) != '\n')
                {
                }
                if (point == 3)
                {
                    yun = (year % 4 == 0 && year % 400 != 0) && (month == 2);
                    ff = (year < 1900 || month < 1 || month > 12) || (month < 8 && day > 30 + month % 2) || (month > 7 && day > 31 - month % 2) || ((month == 2) && day > (yun + 28));
                    if (ff)
                    {
                        cout << "输入错误；返回\n";
                        continue;
                    }
                    a = getLongIntTime(year, month, day, 0, 0);
                    b = getLongIntTime(year, month, day, 23, 59);
                }
                else
                {
                    cout << "输入错误；返回\n";
                    continue;
                }
                break;
            case 2:
                cout << "输入目标月份（输入格式如2022 6）：\n";
                point = scanf("%d %d", &year, &month);
                while ((clear = getchar()) != '\n')
                {
                }
                if (point == 2)
                {
                    if (year < 1900 || month < 1 || month > 12)
                    {
                        cout << "输入错误；返回\n";
                        continue;
                    }
                    a = getLongIntTime(year, month, 1, 0, 0);
                    b = getLongIntTime(year, month, 32, 0, 0);
                }
                else
                {
                    cout << "输入错误；返回\n";
                    continue;
                }
                break;
            case 1:
                cout << "输入目标年份（输入格式如2022）：\n";
                point = scanf("%d", &year);
                while ((clear = getchar()) != '\n')
                {
                }
                if (point == 1)
                {
                    if (year < 1900)
                    {
                        cout << "输入错误；返回\n";
                        continue;
                    }
                    a = getLongIntTime(year, 0, 0, 0, 0);
                    b = getLongIntTime(year, 12, 31, 23, 59);
                    // cout << a << "\n"
                    //      << b << endl;
                }
                else
                {
                    cout << "输入错误；返回\n";
                    continue;
                }
                break;
            default:
                cout << "错误,请重新";
                continue;
            }
            s_list.displayTask(a, b, 0, 1, 0);
            cout<<endl;
        }
    }

}

// void scheduleManage::run(){
//     thread first(&scheduleManage::alert,this);
//     first.detach();
//     menu();
//     return;
// }

bool isCorrectTime(int year, int month, int day, int hour, int minutes)
{
    bool isLeapYear = false;
    bool flag = true;
    if (year % 4 == 0)
    {
        isLeapYear = true;
    }
    if (year % 400 == 0)
    {
        isLeapYear = false;
    }
    if (year < 1900)
    {
        flag = false;
    }
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 8:
    case 10:
    case 12:
        if ((day < 1) || (day > 31))
        {
            flag = false;
        }
        break;
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
        if ((day < 1) || (day > 30))
        {
            flag = false;
        }
        break;
    case 2:
        if (isLeapYear)
        {
            if ((day < 1) || (day > 29))
            {
                flag = false;
            }
        }
        else
        {
            if ((day < 1) || (day > 28))
            {
                flag = false;
            }
        }
        break;
    default:
        flag = false;
        break;
    }
    if ((hour < 0) || (hour > 23))
    {
        flag = false;
    }
    if ((minutes < 0) || (minutes > 59))
    {
        flag = false;
    }
    return flag;
}

bool isInterger(char *input)
{
    int number = strlen(input);
    bool isInt = true;
    for (int i = 0; i < number; i++)
    {
        if ((input[i] < 48) || (input[i] > 57))
        {
            isInt = false;
        }
    }
    return isInt;
}