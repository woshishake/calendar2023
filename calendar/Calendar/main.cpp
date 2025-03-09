#include "scheduleManage.h"
#include "login.h"
using namespace std;

// 不涉及数组长度是否越界/日期信息是否正确与以及各种其他检查
// 基础程序不实现以上功能

// 运行demo1和2必须检查路径文件夹是否存在，需要自己创建文件夹或者在schedule.cpp 的saveFile/loadFile中自行修改文件路径（如果要改两个一起改）

void run();
void getHelp();
void getHelp(char *helpCommand);

int main(int argc, char *argv[])
{

    // 空参数
    if (argc < 2)
    {
        cout << "请输入命令,或者输入help获取帮助" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        return 0;
    }

    // 登陆操作（删除用户.3/修改密码4/获取帮助1/直接运行1/登陆2)

    char *userCommand = argv[1];
    login userList;
    bool invalidCommand = true;
    bool userLogIn = false;
    if (!strcasecmp(userCommand, "Help"))
    {
        invalidCommand = false;
        if ((argc != 2) && (argc != 3))
        {
            cout << "Help指令参数错误" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return -1;
        }
        if (argc == 2)
        {
            getHelp();
            cout << "--------------------------------------------------------------------" << endl;
        }
        if (argc == 3)
        {
            char *helpCommand = argv[2];
            getHelp(helpCommand);
            cout << "--------------------------------------------------------------------" << endl;
        }
    }
    if (!strcasecmp(userCommand, "run"))
    {
        invalidCommand = false;
        if (argc != 2)
        {
            cout << "run指令参数错误" << endl;
            return -1;
        }
        cout << "-------------------------进入run循环模式-----------------------------" << endl;
        run();
    }
    if (!strcasecmp(userCommand, "deleteUser"))
    {
        invalidCommand = false;
        if (argc != 4)
        {
            cout << "删除用户指令参数错误" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return -1;
        }
        userList.m_deleteUser(argv[2], argv[3]);
        cout << "--------------------------------------------------------------------" << endl;
    }
    if (!strcasecmp(userCommand, "changePassword"))
    {
        invalidCommand = false;
        if (argc != 5)
        {
            cout << "修改密码指令参数错误" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return -1;
        }
        userList.m_modifyPassword(argv[2], argv[3], argv[4]);
        cout << "--------------------------------------------------------------------" << endl;
    }
    if ((invalidCommand)&&(argc>2))
    {
        if (strlen(argv[1]) > 21)
        {
            cout << "是否需要登陆或者创建用户？请使用小于等于7个中文字符或21个英文字符的用户名" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            return -1;
        }
            userLogIn = userList.m_login(argv[1], argv[2]);

    }
    if ((!userLogIn) && (invalidCommand))
    {
        cout << "无效的命令参数或无效的登陆信息，请输入help获取帮助" << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }

    if (userLogIn)
    {
        int commandStart = 3;
        if (argc < commandStart + 1)
        {
            cout << "--------------------------------------------------------------------" << endl;
            return 0;
        }
        char *command = argv[commandStart];
        char username[31] = {0};
        strcpy(username, argv[1]);
        scheduleManage list(username);
        bool isCorrectCommand = false;
        if (!strcasecmp(command, "addTask"))
        {
            isCorrectCommand = true;
            if ((argc < (commandStart + 12)) || (argc > (commandStart + 14)))
            {
                cout << "格式错误，无法添加日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }
            for (int i = (commandStart + 2); i < (commandStart + 12); i++)
            {
                if (!isInterger(argv[i]))
                {
                    cout << "错误参数,第 " << i << " 个： ";
                    cout << argv[i] << endl;
                    cout << "输入参数格式错误" << endl;
                    cout << "请重新添加日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
            }
            int y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2;
            y1 = atoi(argv[commandStart + 2]);
            m1 = atoi(argv[commandStart + 3]);
            d1 = atoi(argv[commandStart + 4]);
            h1 = atoi(argv[commandStart + 5]);
            mi1 = atoi(argv[commandStart + 6]);
            y2 = atoi(argv[commandStart + 7]);
            m2 = atoi(argv[commandStart + 8]);
            d2 = atoi(argv[commandStart + 9]);
            h2 = atoi(argv[commandStart + 10]);
            mi2 = atoi(argv[commandStart + 11]);
            char *classification = new char();
            char a[7] = "默认";
            int priority = 2;
            if (argc == (commandStart + 12))
            {
                strcpy(classification, a);
            }
            else
            {
                bool isPrio = false;
                if (!strcmp(argv[commandStart + 12], "高"))
                {
                    priority = 3;
                    strcpy(classification, a);
                    isPrio = true;
                }
                if (!strcmp(argv[commandStart + 12], "中"))
                {
                    priority = 2;
                    strcpy(classification, a);
                    isPrio = true;
                }
                if (!strcmp(argv[commandStart + 12], "低"))
                {
                    priority = 1;
                    strcpy(classification, a);
                    isPrio = true;
                }
                if (argc == commandStart + 13)
                {
                    if (!isPrio)
                    {
                        strcpy(classification, argv[commandStart + 12]);
                    }
                    // cout << "14个参数" << endl;
                    // cout << classification << " " << priority << endl;
                }
                if (argc == commandStart + 14)
                {
                    if (!isPrio)
                    {
                        cout << "输入参数格式错误" << endl;
                        cout << "请重新添加日程" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        return -1;
                    }
                    strcpy(classification, argv[commandStart + 13]);
                    // cout << "15个参数" << endl;
                    // cout << classification << " " << priority << endl;
                }
            }
            list.m_addTask(argv[commandStart + 1], y1, m1, d1, h1, mi1, y2, m2, d2, h2, mi2, priority, classification);
            cout << "--------------------------------------------------------------------" << endl;
            delete classification;
        }
        if (!strcasecmp(command, "displayTask"))
        { // 格式： 1 yyyy 2 yyyy mm 3 yyyy mm dd 4 yyyy mm dd yyyy mm dd 5 全部（自定义）
            isCorrectCommand = true;
            if ((argc < (commandStart + 2)) || (argc > (commandStart + 8)) || ((argc < (commandStart + 8)) && (argc > (commandStart + 5))))
            {
                cout << "displayTask参数格式错误，请重新查找日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }
            if (!isInterger(argv[commandStart + 1]))
            {
                cout << "不存在的选项参数，请重新查找日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }
            int option = atoi(argv[commandStart + 1]);
            long int min, max = 0;
            int y1, m1, d1, y2, m2, d2;
            switch (option)
            {
            case 1:
                if (argc != (commandStart + 3))
                {
                    cout << "按年查找参数错误，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                cout << "按年查找: " << endl;
                if (!isInterger(argv[commandStart + 2]))
                {
                    cout << "时间输入不正确，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                y1 = atoi(argv[commandStart + 2]);
                if (y1 < 1900)
                {
                    cout << "不合适的查找年份，年数应大于1900.请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                min = getLongIntTime(y1, 1, 1, 0, 0);
                max = getLongIntTime(y1, 12, 31, 23, 59);
                list.m_display(min, max);
                break;
            case 2:
                if (argc != (commandStart + 4))
                {
                    cout << "按月查找参数错误，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                for (int i = (commandStart + 2); i < (commandStart + 4); i++)
                {
                    if (!isInterger(argv[i]))
                    {
                        cout << "时间输入不正确，请重新查找日程" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        return -1;
                    }
                }
                y1 = atoi(argv[commandStart + 2]);
                m1 = atoi(argv[commandStart + 3]);
                if (y1 < 1900)
                {
                    cout << "不合适的查找年份，年数应大于1900。请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                if ((m1 < 1) || (m1 > 12))
                {
                    cout << "不合适的查找月份。请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                switch (m1)
                {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    d2 = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    d2 = 30;
                    break;
                case 2:
                    bool isLeapYear = false;
                    if (y1 % 4 == 0)
                    {
                        isLeapYear = true;
                    }
                    if (y1 % 400 == 0)
                    {
                        isLeapYear = false;
                    }
                    if (isLeapYear)
                    {
                        d2 = 29;
                    }
                    else
                    {
                        d2 = 28;
                    }
                }
                min = getLongIntTime(y1, m1, 1, 0, 0);
                max = getLongIntTime(y1, m1, d2, 23, 59);
                cout << "按月查找: " << endl;
                list.m_display(min, max);
                break;
            case 3:
                if (argc != (commandStart + 5))
                {
                    cout << "按日查找参数错误，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                for (int i = (commandStart + 2); i < (commandStart + 5); i++)
                {
                    if (!isInterger(argv[i]))
                    {
                        cout << "时间输入不正确，请重新查找日程" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        return -1;
                    }
                }
                y1 = atoi(argv[commandStart + 2]);
                m1 = atoi(argv[commandStart + 3]);
                d1 = atoi(argv[commandStart + 4]);
                if (!isCorrectTime(y1, m1, d1, 0, 0))
                {
                    cout << "不存在的时间参数，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                min = getLongIntTime(y1, m1, d1, 0, 0);
                max = getLongIntTime(y1, m1, d1, 23, 59);
                cout << "按日查找: " << endl;
                list.m_display(min, max);
                break;

            case 4:
                if (argc != (commandStart + 8))
                {
                    cout << "自定义查找参数错误，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }

                for (int i = (commandStart + 2); i < (commandStart + 8); i++)
                {
                    if (!isInterger(argv[i]))
                    {
                        cout << "时间输入不正确，请重新查找日程" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        return -1;
                    }
                }
                y1 = atoi(argv[commandStart + 2]);
                m1 = atoi(argv[commandStart + 3]);
                d1 = atoi(argv[commandStart + 4]);
                y2 = atoi(argv[commandStart + 5]);
                m2 = atoi(argv[commandStart + 6]);
                d2 = atoi(argv[commandStart + 7]);
                if (!isCorrectTime(y1, m1, d1, 0, 0))
                {
                    cout << "不存在的时间参数，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                if (!isCorrectTime(y2, m2, d2, 0, 0))
                {
                    cout << "不存在的时间参数，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                min = getLongIntTime(y1, m1, d1, 0, 0);
                max = getLongIntTime(y2, m2, d2, 23, 59);
                cout << "自定义查找: " << endl;
                list.m_display(min, max);
                break;
            case 5:
                if (argc != (commandStart + 2))
                {
                    cout << "参数格式错误，请重新查找日程" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    return -1;
                }
                list.m_display(0, 50000010000);
                break;
            default:
                cout << "不存在的选项参数，请重新查找日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }
            cout << "--------------------------------------------------------------------" << endl;
        }
        if (!strcasecmp(command, "deleteTask"))
        {
            isCorrectCommand = true;
            if (argc != commandStart + 2)
            {
                cout << "删除日程参数错误" << endl
                     << "请重新删除日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }
            if (!isInterger(argv[commandStart + 1]))
            {
                cout << "输入id格式错误，请重新删除日程" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                return -1;
            }

            int id = atoi(argv[commandStart + 1]);
            list.deleteSchedule(id, true);
            cout << "--------------------------------------------------------------------" << endl;
        }
        if (!isCorrectCommand)
        {
            cout << "请输入正确指令，或者输入help获取帮助" << endl;
            cout << "--------------------------------------------------------------------" << endl;
        }
    }

    return 0;
}

void run()
{
    login userList;
    char *username = userList.loginUser();
    if (username == NULL)
    {
        return;
    }
    char command[40] = {0};
    bool flag = true;
    bool isCorrectCommand = false;
    char clear;
    while (flag)
    {
        cout <<endl<< "请输入命令：deleteUser/changePassword/menu/quit，其中menu为日程管理" << endl;
        cin >> command;
        while ((clear = getchar()) != '\n')
        {
        }
        if (!strcasecmp(command, "quit"))
        {
            isCorrectCommand = true;
            return;
        }
        if (!strcasecmp(command, "deleteUser"))
        {
            isCorrectCommand = true;
            userList.loginDelete(username);
            return;
        }
        if (!strcasecmp(command, "changepassword"))
        {
            isCorrectCommand = true;
            userList.loginModify(username);
        }
        if (!strcasecmp(command, "menu"))
        {
            isCorrectCommand = true;
            flag = false;
        }
        if (!isCorrectCommand)
        {
            cout << "无效的命令" << endl;
        }
        isCorrectCommand = false;
    }
    if (strlen(username) > 22)
    {
        cout << "用户名过长" << endl;
    }
    char user[22] = {};
    strcpy(user, username);
    scheduleManage list(user);

    thread first(&scheduleManage::alert, &list);

    first.detach();
    list.menu();

    return;
}

void getHelp()
{
    cout << "这些命令是程序内部定义的，输入“help”以获取本列表" << endl;
    cout << "输入 “help 名称”以获得函数“名称”的更多信息" << endl;
    cout << "有* 标记的函数可以查看更多信息 例如：*deleteUser" << endl;
    cout << "使用./calendar以运行本程序" << endl;
    cout << endl;
    cout << "命令行函数：" << endl;
    cout << "用户名 密码 （可用于注册账号）" << endl;
    cout << "*deleteuser 用户名 密码" << endl;
    cout << "*changePassword 用户名 密码 新密码" << endl;
    cout << "*help [函数名]" << endl;
    cout << "*run" << endl;
    cout << "用户名 密码 *addTask [参数...]" << endl;
    cout << "用户名 密码 *deleteTask id" << endl;
    cout << "用户名 密码 *displayTask [参数...]" << endl;
    cout << endl;
    cout << "run模式函数：" << endl;
    cout << "addTask" << endl;
    cout << "deleteTask" << endl;
    cout << "displayTask" << endl;
    cout << "quit" << endl;
}

void getHelp(char *helpCommand)
{
    bool isCorrectCommand = false;
    if (!strcasecmp(helpCommand, "deleteUser"))
    {
        isCorrectCommand = true;
        cout << "deleteUser: deleteUser 用户名 密码" << endl;
        cout << endl;
        cout << "会根据提供的用户名，密码来匹配已有用户" << endl;
        cout << "若匹配成功，则删除用户信息，并提示‘删除成功’" << endl;
        cout << "若匹配不成功，则不进行删除操作，提示‘用户名或密码不存在’" << endl;
    }
    if (!strcasecmp(helpCommand, "changePassword"))
    {
        isCorrectCommand = true;
        cout << "changePassword: changePassword 用户名 密码 新密码" << endl;
        cout << endl;
        cout << "会根据提供的用户名，密码来匹配已有用户" << endl;
        cout << "若匹配成功，则更改用户密码，并提示‘用户修改密码成功’" << endl;
        cout << "若匹配不成功，则不进行删除操作，提示‘用户名或密码不存在，修改失败’" << endl;
    }
    if (!strcasecmp(helpCommand, "help"))
    {
        isCorrectCommand = true;
        cout << "help: help [函数名]" << endl;
        cout << endl;
        cout << "不带参数的help命令用于获取函数列表" << endl;
        cout << "[函数名]用于获取函数列表中带*函数更多信息" << endl;
        cout << "若[函数名]为不带*函数，则返回‘错误函数或函数无更多信息‘" << endl;
    }
    if (!strcasecmp(helpCommand, "run"))
    {
        isCorrectCommand = true;
        cout << "run: run" << endl;
        cout << endl;
        cout << "进入run模式，根据提示可进行用户的创建或登陆" << endl;
        cout << "登陆成功后，对账户进行修改密码/删除/日程管理，或quit推出run模式" << endl;
        cout << "进入日程管理之后，可以添加/删除/查找（显示）特定时间的日程，或quit退出登陆" << endl;
    }
    if (!strcasecmp(helpCommand, "addtask"))
    {
        isCorrectCommand = true;
        cout << "addtask: 用户名 密码 addtask 任务名称 yyyy mm dd hh mm yyyy mm dd hh mm [优先级] [任务分类]" << endl;
        cout << endl;
        cout << "会根据提供的用户名，密码来匹配已有用户" << endl;
        cout << "若用户不存在，则根据输入用户名和密码添加用户并添加日程" << endl;
        cout << "用户存在但密码错误，则不进行日程添加，提示‘密码错误’'无效的命令参数或无效的登陆信息" << endl;
        cout<<"！！！！注意："<<endl;
        cout << "yyyy mm dd hh mm 为日期格式 年 月 日 时 分 秒，其中年必须大于等于1900，第一个日期为提醒时间，第二个日期为日程开始时间" << endl;
        cout << "若成功提醒’添加日程成功‘" << endl;
    }
    if (!strcasecmp(helpCommand, "deletetask"))
    {
        isCorrectCommand = true;
        cout << "deletetask: 用户名 密码 deletetask id" << endl;
        cout << endl;
        cout << "会根据提供的用户名，密码来匹配已有用户" << endl;
        cout << "若用户不存在，则根据输入用户名和密码添加用户并删除日程" << endl;
        cout << "用户存在但密码错误，则不进行日程删除，提示‘密码错误’'无效的命令参数或无效的登陆信息" << endl;
        cout << "若成功提醒’删除成功‘" << endl;
    }
    if (!strcasecmp(helpCommand, "displaytask"))
    {
        isCorrectCommand = true;
        cout << "displaytask: 用户名 密码 displaytask 模式选项 [年] [月] [日] [年] [月] [日]" << endl;
        cout << endl;
        cout << "会根据提供的用户名，密码来匹配已有用户" << endl;
        cout << "若用户不存在，则根据输入用户名和密码添加用户并查找日程" << endl;
        cout << "用户存在但密码错误，则不进行日程查找，提示‘密码错误’'无效的命令参数或无效的登陆信息" << endl;
        cout << "共有五种模式，选项参数分别为：1,2,3,4,5" << endl;
        cout << "模式1： 按年查找，示例：user password displaytask 1 2023" << endl;
        cout << "模式2： 按月查找，示例：user password displaytask 2 2023 12" << endl;
        cout << "模式3： 按日查找，示例：user password displaytask 3 2023 12 4" << endl;
        cout << "模式4： 自定义查找，示例：user password displaytask 4 2023 12 3 2023 12 4" << endl;
        cout << "模式5： 全部显示，示例：user password displaytask 5" << endl;
        cout << "所有时间都是开始时间，若查找时间段内存在日程，则会打印日程信息" << endl;
    }
    if (!isCorrectCommand)
    {
        cout << "错误函数或函数无更多信息" << endl;
    }
    return;
}