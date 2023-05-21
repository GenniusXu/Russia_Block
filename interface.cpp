#include"interface.h"

//画整个游戏界面
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
	cout<<"下一个方块：";
}

void updateInformation()
{
	//更新分数
	setpos(playingArea_width * 2 + 20, 7);
	cout << "                           ";//清除原来的数据
	setpos(playingArea_width * 2 + 20, 7);
	cout << score;

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
		cout << "■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "■■■■";
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
		cout << "■■■";
		setpos(playingArea_width * 2 + 10, 14);
		cout << "  ■■■";
		setColorAttr(37);
	}
}