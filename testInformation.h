#pragma once
//所有输出测试数据或者测试函数效果的模块都放在这个头文件里

#include"globals.h"
#include<iostream>
#include"tools.h"
#include<iomanip>
#include"saveAndRead.h"
using namespace std;

//输出map每个元素的值
void printMapInfo();

//打印二进制文件中的数据
void printFileInfo(string player_arg);