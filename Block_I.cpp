#include"Block_I.h"

Block_I::Block_I()
{
	color = 31;//红色
	blockWidth = 4;
	state = 2;
	//只是为了更直观的看，所以整一个tempShape，然后再将tempShape复制到shape中
	int tempShape[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1}
	};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = tempShape[i][j];
		}
	}
}

//有参构造函数，指定方块初始位置(x,y)
Block_I::Block_I(short x, short y)
{
	color = 31;//红色
	pos.X = x;
	pos.Y = y;
}

void Block_I::rotate()
{
	erase();
	//state 从1到2分别对应两个个摆放方向
	if (state == 1)
	{
		int tempShape[4][4] =
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}
		};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				shape[i][j] = tempShape[i][j];
			}
		}
		blockWidth = 4;
	}
	else if (state == 2)
	{
		int tempShape[4][4] =
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,0,0,0},
			{1,0,0,0}
		};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				shape[i][j] = tempShape[i][j];
			}
		}
		blockWidth = 1;
	}
	state++;
	if (state > 2)
	{
		state = 1;
	}
}