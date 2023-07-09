#pragma once
#include"Tools.h"
#include"Mouse.h"
#include"Option.h"
#include"globals.h"
#include"game.h"
#include"printLetter.h"
#include"help.h"
#include"setting.h"

//生成主菜单界面的按钮
void createMenuOptions();

//打印Russia Block大标题
void print_title();

//打印排行榜信息
void showRankList();

//在游戏开始前，弹出两个窗口，让用户设置地图高度和宽度
void setMapSizeByWindow();

//显示主菜单界面
void mainMenu();

