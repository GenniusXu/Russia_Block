#pragma once
#include<iostream>
#include"Block.h"
#include"globals.h"
#include"tools.h"
#include"Block_I.h"
#include"Block_L.h"
#include"Block_L_opposite.h"
#include"Block_Square.h"
#include"Block_T.h"
#include"Block_Z.h"
#include"Block_Z_opposite.h"
#include"testInformation.h"
#include<random>
#include"mainMenu.h"
#include"saveAndRead.h"
#include<iomanip>
using namespace std;

void drawInterface();//画整个游戏界面

void drawPlayingArea();//画游戏区

void drawInformationArea();//画信息区

void updateInformation();//更新信息区数据

void tellNextBlock(int type);//在信息区显示下一个方块的形状

//判断游戏是否结束，如果结束返回true
bool gameOver();

//重置map_game，将它所有元素重置为0
void resetMap();

//画警示线
void drawWarningLine();

//进入游戏
void game();


