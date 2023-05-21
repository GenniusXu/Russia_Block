#include<iostream>
#include"Block.h"
#include"globals.h"
#include"interface.h"
#include"tools.h"
#include"Block_I.h"
#include"Block_L.h"
#include"Block_Square.h"
#include"Block_T.h"
#include"Block_Z.h"
#include"testInformation.h"
#include<random>
using namespace std;

void game()
{
	Block* b = NULL;//指向当前操作方块的指针
	srand(int(time(0)));
	int type2 = 1;
	while (1)
	{
		clearLine();
		printMapInfo();//打印map数组的值，用于调试bug
		int type = type2;
		//先不随机，让每次都下落L型方块，方便测试，之后再调成随机的-------------------------记得改回来
		//type2 = 1 + rand() % 5;
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

		//只要还能下落，就一直下落，并能通过键盘操纵左右移动
		while (!b->reachEnd())
		{
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
					default:
						break;
				}
			}
		}
		//此次方块下落已完成，回收堆区对象
		delete b;
	}
}

int main()
{
	EnableVTMode();
	fullScreen();
	HideCursor();
	drawInterface();
	while (1)
	{
		updateInformation();
		game();
	}
	return 0;
}