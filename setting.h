#pragma once
#include<cstdlib>
#include<iostream>
#include"tools.h"
#include"Mouse.h"
#include"Option.h"
#include"mainMenu.h"
using namespace std;

//创建在setting窗口的按键
void createSettingOptions();

//在按钮旁边显示当前设置的按键
void showCurrentKeyInfo();

//检查按键设置是否有冲突，有就返回true，否则返回false，keyToCheck是被检测的按键
bool ifKeyConflict(char keyToCheck);

//进入游戏设置界面
void setting();