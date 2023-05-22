#pragma once
#include"block.h"
class Block_T :public Block
{
public:
	Block_T();
	Block_T(short x, short y);//有参构造函数，指定方块初始位置(x,y)
	void rotate();//方块旋转(利用多态，不同方块旋转不一样)
private:
	int state = 4;//state 从1到4分别对应四个摆放方向
};