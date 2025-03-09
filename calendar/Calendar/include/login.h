#ifndef _USERLOGIN_H
#define _USERLOGIN_H

#include<user.h>

class login{
    private:
        user list;
    public:
        login():list(){}
        // void userDisplay(){
        //     list.displayUserList();
        // }
        bool m_login(char *username,char *password);
        void m_deleteUser(char *username,char *password);
        void m_modifyPassword(char *username,char *password,char *n_password);
        char* loginUser();
        void loginModify(char *username);
        bool loginDelete(char *username);
};

#endif // !1