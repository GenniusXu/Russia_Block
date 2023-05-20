#include"Block_Square.h"

Block_Square::Block_Square()
{
	color = 33;//黄色
	blockWidth = 2;
	//只是为了更直观的看，所以整一个tempShape，然后再将tempShape复制到shape中
	int tempShape[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0}
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
Block_Square::Block_Square(short x, short y)
{
	color = 33;//黄色
	pos.X = x;
	pos.Y = y;
}

void Block_Square::rotate()
{
	//正方形怎么转都一样，所以空实现就行
}