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

//将方块固定，并在map_game中标记
void Block::fixBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//该坐标有下落的方块
			if (shape[i][j] == 1)
			{
				//将map_game中对应的坐标设置成下落方块的color值，表示这里已经有方块，且颜色为color
				map_game[pos.Y + i][pos.X + 2 * j] = color;
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
				if (map_game[pos.Y + i + 1][pos.X + 2 * j] != 0)
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

//每次消掉了一行，都要重新根据map_game记录的值来更新方块的位置
void updateMap()
{
	for (int i = 0; i < map_game.size() - 1; i++)
	{
		for (int j = 2; j < map_game[i].size() - 2; j += 2)
		{
			if (map_game[i][j] != 0)
			{
				setpos(j,i);
				setColorAttr(map_game[i][j]);
				cout << "■";
				setColorAttr(37);
			}
			else
			{
				setpos(j, i);
				cout << "  ";
			}
		}
	}
}

//当一行填满，自动消掉一行，并让上方方块下落一行
void clearLine()
{
	for (int i = 0; i < map_game.size() - 1; i++)
	{
		int count = 0;
		for (int j = 2; j < map_game[i].size() - 2; j += 2)
		{
			if (map_game[i][j] != 0)
			{
				count++;
			}
		}
		//有一行满了，就要清除这一行，并把这行上面的方块下移一行，然后updateLine（更新图像），并且分数score += 10
		if (count == playingArea_width - 2)
		{
			for (int k = i; k >= 1; k--)
			{
				for (int m = 2; m < map_game[k].size() - 2; m += 2)
				{
					map_game[k][m] = map_game[k - 1][m];
				}
			}
			if (clearSoundEffect_isOpen)
			{
				PlayClearSoundEffect(clearSoundEffectPath);
			}
			updateMap();
			score += 10 * speed;
		}
		
	}
}

