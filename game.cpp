#include"game.h"

//判断游戏是否结束，如果结束返回true
bool gameOver()
{
	for (int i = 2; i < map[0].size(); i += 2)
	{
		//从上往下数第五行有方块，说明已经满了，游戏结束
		if (map[warnningLine_height][i] != 0)
		{
			return true;
		}
	}
	return false;
}

//重置map，将它所有元素重置为0
void resetMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			map[i][j] = 0;
		}
	}
}

//画警示线
//不知道为什么没用
void drawWarningLine()
{
	setpos(2, warnningLine_height);
	setColorAttr(31);
	for (int i = 0; i < playingArea_width - 2; i++)
	{
		cout << "==";
	}
	setColorAttr(39);
}

void game()
{
	if (backGroundMusic_isOpen)
	{
		PlayBackgroundMusic(backgroundMusicPath);
	}
	drawInterface();//画游戏区方框，在信息区打印各种信息名称
	Block* b = NULL;//指向当前操作方块的指针
	srand(int(time(0)));
	int type2 = 1;
	while (!gameOver())
	{
		updateMap();
		//drawWarningLine();//只在这里画的话会被方块擦掉一小段，在下面的while (!b->reachEnd())里面画才能时刻保持警戒线的完整性
		clearLine();
		updateInformation();
		//printMapInfo();//打印map数组的值，用于调试bug
		int type = type2;
		//先不随机，让每次都下落L型方块，方便测试，之后再调成随机的-------------------------记得改回来
		type2 = 1 + rand() % 5;
		//先指定每次都下落L型方块，方便测试，之后再调成随机的-------------------------记得改回来
		tellNextBlock(type2);
		if (type == 1)
		{
			b = new Block_I;
		}
		else if (type == 2)
		{
			b = new Block_L;
		}
		else if (type == 3)
		{
			b = new Block_Square;
		}
		else if (type == 4)
		{
			b = new Block_T;
		}
		else if (type == 5)
		{
			b = new Block_Z;
		}
		//......(每加一种类型的方块，都在这里添加一个else if就行)

		int tempSpeed = speed;//保存一下默认速度，用于加速后恢复初始速度
		//只要还能下落，就一直下落，并能通过键盘操纵左右移动
		while (!b->reachEnd())
		{
			drawWarningLine();//在这里画才能时刻保持警戒线的完整性
			b->drop();
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
					//72上 80下 75左 77右
				case 'a':
				case 75:
					b->moveLeft();
					break;
				case 'd':
				case 77:
					b->moveRight();
					break;
				case 'j':
					b->rotate();
					break;
				case 'p':
					setpos(playingArea_width * 2 + 10, 2);
					cout << "游戏已暂停，";
					system("pause");//请按任意键继续在这里
					setpos(playingArea_width * 2 + 10, 2);
					cout << "                                      ";//清除暂停提示信息
					break;
				case 's':
				case 80:
					speed = 30;
					break;
				case 'w':
				case 72:
					speed = tempSpeed;
					break;
				case 'q':
					system("cls");
					savePlayerInfo();
					stopBackgroundMusic();
					mainMenu();
					return;
				default:
					break;
				}
			}
		}
		//此次方块下落已完成，回收堆区对象
		delete b;
		speed = tempSpeed;
	}
	setpos(playingArea_width / 2, 3);
	cout << "方块溢出，游戏结束！";
	setpos(playingArea_width / 2, 4);
	setpos(playingArea_width / 2, 4);
	cout << "3秒后自动返回主菜单";
	Sleep(3000);
	resetMap();//一定要，不然再次进入游戏时还没开始就结束了
	clearScreen();
	stopBackgroundMusic();
	mainMenu();
}