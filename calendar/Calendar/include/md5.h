#ifndef MD5_H
#define MD5_H

#include<iostream>
#include<string.h>
using namespace std;


void mainLoop(unsigned int M[]);

unsigned int* add(string str);

string changeHex(int a);

string getMD5(string source);

string md5(string ss);

#endif
