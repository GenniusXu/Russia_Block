#pragma once
#include<iostream>
#include"Block.h"
#include"globals.h"
#include"interface.h"
#include"tools.h"
#include"Block_I.h"
#include"Block_L.h"
#include"Block_Square.h"
#include"Block_T.h"
#include"Block_Z.h"
#include"testInformation.h"
#include<random>
#include"mainMenu.h"
#include"saveAndRead.h"
using namespace std;

//判断游戏是否结束，如果结束返回true
bool gameOver();

//重置map，将它所有元素重置为0
void resetMap();

//画警示线
void drawWarningLine();

//进入游戏
void game();


