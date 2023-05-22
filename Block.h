#pragma once
#include<Windows.h>
#include"tools.h"
#include"globals.h"
#include<ctime>
using namespace std;

class Block
{
	friend void tellNextBlock(int type);
public:
	Block();//无参构造函数，方块初始位置为游戏区上方中间位置
	Block(short x, short y);//有参构造函数，指定方块初始位置(x,y)
	void show();//打印方块
	void erase();//擦去方块
	virtual void rotate();//方块旋转(利用多态，不同方块旋转不一样)
	void showNextShape();//在信息区预告下一方块形状
	void fixBlock();//将方块固定，并在map中标记
	bool reachEnd();//判断是否已经无法继续下落，无法继续下落就返回true
	bool drop();//方块下落,如果还能下落返回true，如果已经不能继续下落返回false
	void moveLeft();//方块左移1格
	void moveRight();//方块右移1格

protected:
	int shape[4][4];//存储当前下落方块形状的二维数组，1代表有，0代表无
	static int nextShape[4][4];//存储下一个出现的方块形状的二维数组，1代表有，0代表无
	COORD pos;//4*4方块区域左上角坐标
	int color;//方块的颜色，作为setColorAttr的参数
	int blockWidth;//方块的横向长度（用于判断方块是否超出了游戏区）
};

//每次消掉了一行，都要重新根据map记录的值来更新方块的位置
void updateMap();

//当一行填满，自动消掉一行，并让上方方块下落一行
void clearLine();






