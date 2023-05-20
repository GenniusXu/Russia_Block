#pragma once
#pragma once
#include"Block.h"
class Block_Z :public Block
{
public:
	Block_Z();
	Block_Z(short x, short y);//有参构造函数，指定方块初始位置(x,y)
	void rotate();//方块旋转(利用多态，不同方块旋转不一样)
private:

};