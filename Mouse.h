#pragma once
#include<iostream>
#include<windows.h>
#include<ctime>
#include"globals.h"
#include"tools.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 

using namespace std;
//右键单击就很正常，
//左键单击有问题，它不知道是单击还是选择，两次左键单击之间必须单击一次右键，有时右键单击也被当成左键
//(以上问题已解决，只需调用函数取消控制台的快速编辑模式即可)
//判断左键单击
bool click();

//判断右键单击事件，
bool click_Right();

//判断左键双击事件(好像不行，还是单击，而且会导致其他异常）
bool doubleClick();

//将某块矩形区域设置为白底黑字（highlight）
void highLightArea(SMALL_RECT area);

//把highlight后的区域重置回原状（即黑底白字）
void resetArea(SMALL_RECT area);

//判断鼠标是否在某个矩形范围内
bool mouseInArea(SMALL_RECT area);

//获取鼠标在控制台坐标系下的坐标（一单位是一个字符）（我自己写的）
COORD getMousePosOfClient();
