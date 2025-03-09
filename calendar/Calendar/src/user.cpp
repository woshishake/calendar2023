#include "user.h"
using namespace std;

user::user()
{
    //尝试打开
    FILE *fp;
    char filename[45] = "./file/user";
    fp = fopen(filename, "r");
    //新建文件
    if (fp == NULL)
    {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            cout << "创建文件失败" << endl;
            return;
        }
        fclose(fp);
        fp = fopen(filename, "r");
    }
    if (fp == NULL)
    {
        cout << "打开文件失败" << endl;
        return;
    }
    //创建用户列表
    userInfo tmp;
    //按读取，插入容器
    while (!feof(fp))
    {
        int pout = fscanf(fp, "%s %s", tmp.username, tmp.password);
        if (pout == 2)
        {
            userList.push_back(tmp);
        }
    }
    fclose(fp);
}

// 检查用户是否存在，存在则返回true，不存在则返回false；
bool user::checkUser(char *name)
{
    //是否为空
    if (userList.size() == 0)
    {
        return false;
    }
    bool flag = false;
    //遍历
    for (int i = 0; i < userList.size(); i++)
    {
        if (!strcmp(userList[i].username, name))
        {
            flag = true;
        }
    }
    return flag;
}

//添加用户，有重复用户名会打印错误提示
void user::addUser(char *username, char *password)
{
    //检验用户是否存在
    if (checkUser(username))
    {
        cout << "用户已存在" << endl;
        return;
    }
    //插入新用户
    userInfo tmp;
    strcpy(tmp.username, username);
    strcpy(tmp.password, password);
    userList.push_back(tmp);
    return;
}

//打印用户列表，调试用
void user::displayUserList()
{
    cout << std::left << std::setw(15) << "用户名称\t\t"
         << "用户密码（已加密）" << endl;
    for (int i = 0; i < userList.size(); i++)
    {
        cout << std::left << std::setw(15) << userList[i].username << "\t\t" << userList[i].password << endl;
    }
    return;
}

//保存用户列表（保存用户信息）
void user::saveUserFile()
{
    //打开文件
    FILE *fp;
    char filename[45] = "./file/user";
    fp = fopen(filename, "w+");
    //检查文件是否打开
    if (fp == NULL)
    {
        cout << "保存文件失败" << endl;
        return;
    }
    //遍历
    for (int i = 0; i < userList.size(); i++)
    {
        fprintf(fp, "%s %s\n", userList[i].username, userList[i].password);//格式化输出
    }
    fclose(fp);
    return;
}

//核对用户名及密码，用户名不存在或用户名存在密码错误返回false；用户名存在且密码正确返回true
bool user::checkPassword(char *username, char *password)
{
    bool flag = false;
    //遍历
    for (int i = 0; i < userList.size(); i++)
    {
        if (!strcmp(userList[i].username, username))//检查用户名
        {
            if (!strcmp(userList[i].password, password))//检查密码
            {
                flag = true;
            }
        }
    }
    return flag;
}

//查找用户信息在迭代器中位置，不存在或为第一个则返回0
int user::findUser(char *username)
{
    int tmp = 0;
    for (int i = 0; i < userList.size(); i++)
    {
        if (!strcmp(userList[i].username, username))
        {
            tmp = i;
        }
    }
    return tmp;
}

//删除用户，若用户不存在打印错误提醒并返回false，删除成功返回true
bool user::deleteUser(char *username)
{
    if (!checkUser(username))
    {
        cout << "删除用户不存在" << endl;
        return false;
    }
    userList.erase(userList.begin() + findUser(username));
    return true;
}

//修改用户密码，传入参数为用户名和新密码，用户不存在则不修改密码
void user::modifyPassword(char *username,char *n_password){
    for (int i = 0; i < userList.size(); i++){
        if (!strcmp(userList[i].username, username)){
            strcpy(userList[i].password,n_password);
        }
    }
    return;
}