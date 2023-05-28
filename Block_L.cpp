#include"Block_L.h"

Block_L::Block_L()
{
	color = 32;//绿色
	blockWidth = 4;
	state = 4;
	//只是为了更直观的看，所以整一个tempShape，然后再将tempShape复制到shape中
	int tempShape[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,1},
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
Block_L::Block_L(short x, short y)
{
	color = 32;//绿色
	pos.X = x;
	pos.Y = y;
}

void Block_L::rotate()
{
	erase();
	//state 从1到4分别对应四个摆放方向
	if (state == 1)
	{
		int tempShape[4][4] =
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,1},
			{1,1,1,1}
		};
		//如果旋转后右边出界，则要将方块强行左移到恰好不出界的位置
		//注意一格方块是占两个单位pos
		if (pos.X + 8 >= playingArea_width * 2)
		{
			pos.X = (playingArea_width - 5) * 2;
		}
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
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				shape[i][j] = tempShape[i][j];
			}
		}
		blockWidth = 2;
	}
	else if (state == 3)
	{
		int tempShape[4][4] =
		{
			{1,1,1,1},
			{1,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		};
		//如果旋转后右边出界，则要将方块强行左移到恰好不出界的位置
		//注意一格方块是占两个单位pos
		if (pos.X + 8 >= playingArea_width * 2)
		{
			pos.X = (playingArea_width - 5) * 2;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				shape[i][j] = tempShape[i][j];
			}
		}
		blockWidth = 4;
	}
	else if (state == 4)
	{
		int tempShape[4][4] =
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0}
		};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				shape[i][j] = tempShape[i][j];
			}
		}
		blockWidth = 2;
	}
	state++;
	if (state > 4)
	{
		state = 1;
	}
}