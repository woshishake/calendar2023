#include "login.h"

bool login::m_login(char *username, char *password)
{
    bool flag;
    if (list.checkUser(username))
    {
        string b = md5(password);
        char pWord[40];
        strcpy(pWord, b.data());
        flag = list.checkPassword(username, pWord);
        if (flag)
        {
            cout<<"密码正确，成功登陆"<<endl;
            return true;
        }
        if (!flag)
        {
            cout << "密码错误" << endl;
            return false;
        }
    }
    else
    {
        if (strlen(username) > 21)
        {
            cout << "用户名过长" << endl;
            return false;
        }
        else
        {
            string a = md5(password);
            char pWord[40];
            strcpy(pWord, a.data());
            cout << "成功添加用户： " << username << endl;
            list.addUser(username, pWord);
            list.saveUserFile();
        }
    }
    return true;
}

void login::m_deleteUser(char *username, char *password)
{
    bool flag;
    //加密
    string b = md5(password);
    char pWord[40];
    strcpy(pWord, b.data());
    
    flag = list.checkPassword(username, pWord);
    if(flag){
        list.deleteUser(username);
        cout<<"删除成功"<<endl;
        list.saveUserFile();
    }
    if(!flag){
        cout<<"用户名不存在或密码错误，删除失败"<<endl;
    }
    return;
}

void login::m_modifyPassword(char *username,char *password,char *n_password){
    bool flag;
    string b = md5(password);
    // cout<<b<<endl;
    char pWord[40];
    strcpy(pWord, b.data());
    string a = md5(n_password);
    // cout<<a<<endl;
    char pNWord[40];
    strcpy(pNWord, a.data());
    flag = list.checkPassword(username, pWord);
    if(flag){
        list.modifyPassword(username,pNWord);
        cout<<"用户"<<username<<"修改密码成功"<<endl;
        list.saveUserFile();
    }
    if(!flag){
        cout<<"用户名不存在或密码错误，修改失败"<<endl;
    }
    return;
}

char* login::loginUser(){
    string name, pass;
    char *username,*password;
    char clear;
    bool flag=true;
   cout<<"请输入用户名：(可输入new创建新用户)(输入quit退出程序)\n";
   while(1){
    if(flag){cin>>name;
    while((clear=getchar())!='\n'){}
    if(name.length()>22)
    {
        cout<<"用户名过长,请重新输入(输入quit退出程序)\n";
        continue;
    }
    username=new char[name.length()+1];
    strcpy(username,name.data());
    if(strcasecmp(username,"quit")==0)return NULL;
    if((strcasecmp(username,"new")==0)||(!flag))
    {
     cout<<"输入新用户名(输入quit退出程序)\n";
     cin>>name;
     while((clear=getchar())!='\n'){}
     if(name.length()>22)
    {
        cout<<"用户名过长,请重新输入(输入quit退出程序)\n";
        continue;
    }
     flag=false;
     delete []username;
    username=new char[name.length()+1];
    strcpy(username,name.data());
    if(strcasecmp(username,"quit")==0)return NULL;
    }

    if(list.checkUser(username))
    {   
        if(!flag)
        {
            cout<<"用户名已存在,请重新";
            continue;
        }
        while(1)
        {cout<<"输入密码：(输入quit退出程序)\n";
         cin>>pass;
         while((clear=getchar())!='\n'){}
         if(strcasecmp(pass.c_str(),"quit")==0)return NULL;
         pass=md5(pass);
         password=new char[pass.length()+1];
         strcpy(password,pass.data());
         if(list.checkPassword(username,password))
        {
         cout<<"登录成功\n";
         delete [] password;
         return username;
        }
        else {
            cout<<"密码错误,请重新";
            delete []password;
            continue;
        }}}
        else{
       if(flag)cout<<"用户名不存在,请重新输入(输入quit退出程序)\n";
       else break;
       }
        continue;
    }
    }

    while(1){
         cout<<"用户名创建成功，请输入密码(输入quit退出程序)\n";
         cin>>pass;
         if(strcasecmp(pass.c_str(),"quit")==0)return NULL;
         pass=md5(pass);
         while((clear=getchar())!='\n'){}
         password=new char[pass.length()+1];
         strcpy(password,pass.data());
         list.addUser(username,password);
         cout<<"密码设置成功，用户已创建\n"
              <<"用户登录成功\n";
         delete []password;
         list.saveUserFile();
         return username;
    }
}

void login::loginModify(char *username)
{
    string pass;
    char *password;
    char confirm,clear;
    cout<<"修改前";
    while(1){
    cout<<"输入当前密码:(输入quit退出程序)\n";;
    cin>>pass;
    while((clear=getchar())!='\n'){}
    if(strcasecmp(pass.c_str(),"quit")==0)return;
    pass=md5(pass);
    password=new char[pass.length()+1];
    strcpy(password,pass.data());
    if(list.checkPassword(username,password))
        {
         cout<<"输入新密码:(输入quit退出程序)\n";;
         delete [] password;
         cin>>pass;
         while((clear=getchar())!='\n'){}
         if(strcasecmp(pass.c_str(),"quit")==0)return;
         pass=md5(pass);
         password=new char[pass.length()+1];
         strcpy(password,pass.data());
         list.modifyPassword(username,password);
         cout<<"密码修改成功\n";
         list.saveUserFile();
         delete []password;
         return ;
        }
        else {
            cout<<"密码错误,请重新";
            delete []password;
            continue;
        }
    } 
}

bool login::loginDelete(char *username)
{
    string pass;
    char *password;
    char confirm,clear;
    cout<<"删除前";
    while(1){
    cout<<"输入当前密码:(输入quit退出程序)\n";;
    cin>>pass;
    while((clear=getchar())!='\n'){}
    if(strcasecmp(pass.c_str(),"quit")==0)return false;
    pass=md5(pass);
    password=new char[pass.length()+1];
    strcpy(password,pass.data());
    if(list.checkPassword(username,password))
        {
            delete []password;
          cout<<"密码正确,删除成功\n";
          list.deleteUser(username);
          list.saveUserFile();
          return true;
        }
        else {
            cout<<"密码错误,请重新";
            delete []password;
            continue;
        }
    } 
}
