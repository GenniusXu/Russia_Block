#pragma once
#include"globals.h"
#include<iostream>
#include"tools.h"
#include"Block.h"
#include"Block_I.h"
#include"Block_L.h"
#include"Block_Square.h"
#include"Block_T.h"
#include"Block_Z.h"

void drawInterface();//画整个游戏界面
void drawPlayingArea();//画游戏区
void drawInformationArea();//画信息区
void updateInformation();//更新信息区数据

void tellNextBlock(int type);//在信息区显示下一个方块的形状