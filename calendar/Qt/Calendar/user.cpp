#include "user.h"
using namespace std;

user::user()
{
    FILE *fp;
    char filename[45] = "./user.txt";
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            QMessageBox::information(NULL,"错误","创建文件失败");
            return;
        }
        fclose(fp);
        fp = fopen(filename, "r");
    }
    if (fp == NULL)
    {
        QMessageBox::information(NULL,"错误","打开文件失败");
        return;
    }
    userInfo tmp;
    while (!feof(fp))
    {
        userInfo tmp;
        char username[22];
        char password[40];
        int pout = fscanf(fp, "%s %s",username,password);
        tmp.username=username;
        tmp.password=password;
        if (pout == 2)
        {
            userList.push_back(tmp);
        }
    }
    fclose(fp);
}

// 检查用户是否存在，存在则返回true，不存在则返回false；
bool user::checkUser(string name)
{
    if (userList.size() == 0)
    {
        return false;
    }
    bool flag = false;
    for (int i = 0; i < userList.size(); i++)
    {
        if (userList[i].username==name)
        {
            flag = true;
        }
    }
    return flag;
}

void user::addUser(string username, string password)
{
    if (checkUser(username))
    {
        QMessageBox::information(NULL,"错误","用户已存在");
        return;
    }
    userInfo tmp(username,password);
    userList.push_back(tmp);
    return;
}


void user::saveUserFile()
{
    FILE *fp;
    char filename[45] = "./user.txt";
    fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        QMessageBox::information(NULL,"错误","保存文件失败");
        return;
    }
    for (int i = 0; i < userList.size(); i++)
    {
        fprintf(fp, "%s %s\n", userList[i].username.c_str(), userList[i].password.c_str());
    }
    fclose(fp);
    return;
}

bool user::checkPassword(string username, string password)
{
    bool flag = false;
    for (int i = 0; i < userList.size(); i++)
    {
        if (userList[i].username== username)
        {
            if (userList[i].password==password)
            {
                flag = true;
            }
        }
    }
    return flag;
}

int user::findUser(string username)
{
    int tmp = 0;
    for (int i = 0; i < userList.size(); i++)
    {
//        if (!strcmp(userList[i].username, username))
//        {
//            tmp = i;
//        }
    }
    return tmp;
}


void user::deleteUser(string username){
    for (int i = 0; i < userList.size(); i++){
        if(userList[i].username== username){
            userList.erase(userList.begin()+i);
        }
    }
}
