#include"game.h"

// 画整个游戏界面
void drawInterface()
{
	drawPlayingArea();
	drawInformationArea();
}

//画游戏区
void drawPlayingArea()
{
	//上边界
	setpos(0, 0);
	for (int i = 0; i < playingArea_width; i++)
	{
		cout << "■";
	}
	//左右边界
	for (int i = 0; i < playingArea_height; i++)
	{
		setpos(0, i);
		cout << "■";
		setpos((playingArea_width - 1) * 2, i);
		cout << "■";
	}
	//下边界
	setpos(0, playingArea_height - 1);
	for (int i = 0; i < playingArea_width; i++)
	{
		cout << "■";
	}
}

//画信息区
void drawInformationArea()
{
	setpos(playingArea_width * 2 + 10, 5);
	cout << "玩家名：" << player;
	setpos(playingArea_width * 2 + 10, 7);
	cout << "当前分数：";
	setpos(playingArea_width * 2 + 10, 9);
	cout << "历史最高分：";
	setpos(playingArea_width * 2 + 10, 11);
	cout << "下一个方块：";

	int offset = 50;
	setpos(playingArea_width * 2 + offset, 4);
	cout << "游戏操作：";
	setpos(playingArea_width * 2 + offset, 6);
	cout << left << setw(16) << "方块左移：" << key_for_left << " 或 ←";
	setpos(playingArea_width * 2 + offset, 7);
	cout << left << setw(16) << "方块右移：" << key_for_right << " 或 →";
	setpos(playingArea_width * 2 + offset, 8);
	cout << left << setw(16) << "方块旋转：" << key_for_rotate;
	setpos(playingArea_width * 2 + offset, 9);
	cout << left << setw(16) << "加速下落：" << key_for_down << " 或 ↓";
	setpos(playingArea_width * 2 + offset, 10);
	cout << left << setw(16) << "恢复正常速度：" << key_for_up << " 或 ↑";
	setpos(playingArea_width * 2 + offset, 11);
	cout << left << setw(16) << "暂停：" << key_for_pause;
	setpos(playingArea_width * 2 + offset, 12);
	cout << left << setw(16) << "返回主菜单：" << key_for_quit;
}

void updateInformation()
{
	//更新分数
	setpos(playingArea_width * 2 + 20, 7);
	cout << "                           ";//清除原来的数据
	setpos(playingArea_width * 2 + 20, 7);
	cout << score;
	if (score > highestScore)
	{
		highestScore = score;
	}

	//更新历史最高分
	setpos(playingArea_width * 2 + 22, 9);
	cout << "                           ";//清除原来的数据
	setpos(playingArea_width * 2 + 22, 9);
	cout << highestScore;
}

//在信息区显示下一个方块的形状
void tellNextBlock(int type)
{
	setpos(playingArea_width * 2 + 10, 13);
	cout << "              ";//清除原来的数据
	setpos(playingArea_width * 2 + 10, 14);
	cout << "              ";//清除原来的数据
	setpos(playingArea_width * 2 + 10, 15);
	cout << "              ";//清除原来的数据
	setpos(playingArea_width * 2 + 10, 16);
	cout << "              ";//清除原来的数据
	if (type == 1)
	{
		//不知道为什么这样显示不出来
		/*Block_I b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(31);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "■■■■";
		setColorAttr(37);
	}
	else if (type == 2)
	{
		//不知道为什么这样显示不出来
		/*Block_L b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(32);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "    ■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■■";
		setColorAttr(37);
	}
	else if (type == 3)
	{
		//不知道为什么这样显示不出来
		/*Block_Square b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(33);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "■■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■";
		setColorAttr(37);
	}
	else if (type == 4)
	{
		//不知道为什么这样显示不出来
		/*Block_T b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(34);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "  ■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■■";
		setColorAttr(37);
	}
	else if (type == 5)
	{
		//不知道为什么这样显示不出来
		/*Block_Z b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(35);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "■■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "  ■■";
		setColorAttr(37);
	}
	else if (type == 6)
	{
		//不知道为什么这样显示不出来
		/*Block_Z_opposite b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(95);
		setpos(playingArea_width * 2 + 10, 13);
		 cout << "  ■■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■";
		setColorAttr(37);
	}
	else if (type == 7)
	{
		//不知道为什么这样显示不出来
		/*Block_L_opposite b(playingArea_width * 2 + 10, 13);
		b.show();*/
		setColorAttr(92);
		setpos(playingArea_width * 2 + 10, 13);
		cout << "■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■■";
		setColorAttr(37);
	}
}

//判断游戏是否结束，如果结束返回true
bool gameOver()
{
	for (int i = 2; i < map_game[0].size(); i += 2)
	{
		//从上往下数第五行有方块，说明已经满了，游戏结束
		if (map_game[warnningLine_height][i] != 0)
		{
			return true;
		}
	}
	return false;
}

//重置map_game，将它所有元素重置为0
void resetMap()
{
	for (int i = 0; i < map_game.size(); i++)
	{
		for (int j = 0; j < map_game[i].size(); j++)
		{
			map_game[i][j] = 0;
		}
	}
}

//画警示线
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
		//printMapInfo();//打印map_game数组的值，用于调试bug
		int type = type2;
		//先不随机，让每次都下落L型方块，方便测试，之后再调成随机的-------------------------记得改回来
		//如果下一个方块跟现在的方块是一样的，就重新生成一个，避免总是出现同一个方块的尴尬情况
		do
		{
			type2 = 1 + rand() % 7;
		} while (type2 == type);
		//type2 = 2;
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
		else if (type == 6)
		{
			b = new Block_Z_opposite;
		}
		else if (type == 7)
		{
			b = new Block_L_opposite;
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
				if (ch == 75 || ch == key_for_left)
				{
					b->moveLeft();
				}
				else if (ch == 77 || ch == key_for_right)
				{
					b->moveRight();
				}
				else if (ch == 80 || ch == key_for_down)
				{
					speed += 20;
				}
				else if (ch == 72 || ch == key_for_up)
				{
					speed = tempSpeed;
				}
				else if (ch == key_for_rotate)
				{
					b->rotate();
				}
				else if (ch == key_for_pause)
				{
					stopBackgroundMusic();
					setpos(playingArea_width * 2 + 10, 2);
					cout << "游戏已暂停，";
					system("pause");//请按任意键继续在这里
					setpos(playingArea_width * 2 + 10, 2);
					cout << "                                      ";//清除暂停提示信息
					if (backGroundMusic_isOpen)
					{
						PlayBackgroundMusic(backgroundMusicPath);
					}
				}
				else if (ch == key_for_quit)
				{
					system("cls");
					savePlayerInfo();
					rankList.insert(make_pair(score, player));
					saveRankList();
					stopBackgroundMusic();
					mainMenu();
					return;
				}
			}
		}
		//此次方块下落已完成，回收堆区对象
		delete b;
		speed = tempSpeed;
	}
	setpos(playingArea_width / 2, 3);
	cout << "方块溢出，游戏结束！";
	rankList.insert(make_pair(score, player));
	saveRankList();
	setpos(playingArea_width / 2, 4);
	setpos(playingArea_width / 2, 4);
	cout << "3秒后自动返回主菜单";
	Sleep(3000);
	resetMap();//一定要，不然再次进入游戏时还没开始就结束了
	clearScreen();
	stopBackgroundMusic();
	mainMenu();
}