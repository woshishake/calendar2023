#ifndef USER_H
#define USER_H
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include <iomanip>
#include"md5.h"
#include<QMessageBox>

class user{
    private:
        struct userInfo{
            string username;
            string password;
            userInfo(string a="",string b=""):username(a),password(b){};
        };
    std::vector<userInfo>  userList;
    public:
        user();
        void addUser(string username,string password);
        bool checkPassword(string username,string password);
        bool checkUser(string name);
        void saveUserFile();
        void deleteUser(string username);
        int findUser(string username);

};

#endif // USER_H
