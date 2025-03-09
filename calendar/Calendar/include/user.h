#ifndef _USER_H
#define _USER_H
#include<iostream>
#include<vector>
#include<cstring>
#include <iomanip>
#include"md5.h"

class user{
    private:
        struct userInfo{
            char username[22];//用户名
            char password[40];//密码
            userInfo():username(""),password(""){};
        };
    std::vector<userInfo>  userList;  //用户列表
    public:
        user();
        //添加用户，有重复用户名会打印错误提示
        void addUser(char *username,char *password);
        //删除用户，若用户不存在打印错误提醒并返回false，删除成功返回true
        bool deleteUser(char *username);
        //核对用户名及密码，用户名不存在或用户名存在密码错误返回false；用户名存在且密码正确返回true
        bool checkPassword(char *username,char *password);
        // 检查用户是否存在，存在则返回true，不存在则返回false；
        bool checkUser(char *name);
        //打印用户列表，调试用
        void displayUserList();
        //保存用户列表（保存用户信息）
        void saveUserFile();
        //修改用户密码，传入参数为用户名和新密码，用户不存在则不修改密码
        void modifyPassword(char *username,char *n_password);
        //查找用户信息在迭代器中位置，不存在或为第一个则返回0
        int findUser(char *username);
        
};

#endif // !_USER_H
#define _USER_H