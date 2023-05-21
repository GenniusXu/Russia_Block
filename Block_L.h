#pragma once
#include"block.h"
class Block_L :public Block
{
public:
	Block_L();
	Block_L(short x, short y);//有参构造函数，指定方块初始位置(x,y)
	void rotate();//方块旋转(利用多态，不同方块旋转不一样)
private:

};