#include"Block.h"

int Block::nextShape[4][4] =
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{1,1,1,1}
};

//无参构造函数，方块初始位置为游戏区上方中间位置
Block::Block()
{
	pos.X = playingArea_width - 2;
	pos.Y = 1;
}

//打印方块
void Block::show()
{
	setColorAttr(color);//文字颜色设为某类型方块的专有颜色
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			setpos(pos.X + 2 * j, pos.Y + i);//因为x方向上一个方块占两个字符位置，所以加 2*j
			if (shape[i][j] == 1)
			{
				cout << "■";
			}
		}
	}
	setColorAttr(37);//文字颜色设置回正常的白色
}

//有参构造函数，指定方块初始位置(x,y)
Block::Block(short x, short y)
{
	pos.X = x;
	pos.Y = y;
}

//擦去方块
void Block::erase()
{
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == 1)
			{
				setpos(pos.X + 2 * j, pos.Y + i);//因为x方向上一个方块占两个字符位置，所以加 2*j
				cout << "  ";
			}
		}
	}
}

//方块旋转
void Block::rotate()
{

}

//在信息区预告下一方块形状
void Block::showNextShape()
{

}

//将方块固定，并在map中标记
void Block::fixBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//该坐标有下落的方块
			if (shape[i][j] == 1)
			{
				//将map中对应的坐标设置成下落方块的color值，表示这里已经有方块，且颜色为color
				map[pos.Y + i][pos.X + 2 * j] = color;
			}
		}
	}
}

//判断是否已经不能再继续下落
bool Block::reachEnd()
{
	//如果已经到达游戏区下边界（还不是很完善，只是粗略的判断，后面要改），则已经不能继续下落
	if (pos.Y >= playingArea_height - 5)
	{
		fixBlock();
		return true;
	}
	//如果任意一个小方块的下方已经有方块，则已经不能继续下落
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//该坐标有下落的方块
			if (shape[i][j] == 1)
			{
				//下落的方块的下面一格已经有方块
				if (map[pos.Y + i + 1][pos.X + 2 * j] != 0)
				{
					fixBlock();
					return true;
				}
			}
		}
	}
	return false;
}

;//方块下落
bool Block::drop()
{
	static clock_t startTime = clock();
	clock_t endTime = clock();
	if (!reachEnd())
	{
		if (double((endTime - startTime)) / CLOCKS_PER_SEC > 1.0 / speed)
		{
			erase();
			pos.Y += 1;
			show();
			startTime = clock();
		}
		return true;
	}
	erase();
	return false;
}

//方块左移1格
void Block::moveLeft()
{
	if (pos.X -2 > 0)
	{
		erase();
		pos.X -= 2;//一个方块占两格
		show();
	}
}

//方块右移1格
void Block::moveRight()
{
	if (pos.X + 2 < 2 * playingArea_width - 2 * blockWidth)
	{
		erase();
		pos.X += 2;//一个方块占两格
		show();
	}
}

//每次消掉了一行，都要重新根据map记录的值来更新方块的位置
void updateMap()
{
	//测试------------------------------------
	setpos(2, 3);
	cout << "调用了update";//有问题，没走到
	//测试------------------------------------
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size() - 2; j += 2)
		{
			if (map[i][j] != 0)
			{
				setpos(i, j);
				setColorAttr(map[i][j]);
				cout << "■";
				setColorAttr(37);
			}
			else
			{
				cout << "  ";
			}
		}
	}
}

//当一行填满，自动消掉一行，并让上方方块下落一行
void clearLine()
{
	for (int i = 0; i < map.size(); i++)
	{
		bool fullLine = true;//记录是否满一行的变量
		for (int j = 0; j < map[i].size() - 2; j+=2)
		{
			if (map[i][j] == 0)
			{
				//只要一行里有一个是0，那就没满
				fullLine = false;
			}
		}
		//有一行满了，就要清除这一行，并把这行上面的方块下移一行，然后updateLine（更新图像）
		if (fullLine == true)
		{
			//测试-----------------------------------
			setpos(2, 4);
			cout << "测试信息，走到了fullLine==true";//有问题，没走到
			//测试----------------------------------------
			for (int k = i; k >= 1; k--)
			{
				for (int m = 0; m < map[k].size(); m += 2)
				{
					map[k][m] = map[k - 1][m];
				}
			}
			updateMap();
		}
	}
}

