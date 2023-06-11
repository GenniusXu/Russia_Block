#include"help.h"

//创建在Help窗口的按键
void createHelpOptions()
{
	short menu_option_left_limit = 10;
	short menu_option_top_limit = getConsoleHeight() - 5;
	//每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
	options.push_back(Option("返回主菜单", { menu_option_left_limit,menu_option_top_limit, menu_option_left_limit + 18,menu_option_top_limit + 2 }));
}

//进入帮助界面
void help()
{
	system("cls");
	cout << "游戏规则：" << endl;
	cout << "由小方块组成的不同形状的板块陆续从屏幕上方落下来，" << endl;
	cout << "玩家通过调整板块的位置和方向，使它们在屏幕底部拼出完整的一条或几条。" << endl;
	cout << "这些完整的横条会随即消失，给新落下来的板块腾出空间." << endl;
	cout << "与此同时，玩家得到分数奖励。没有被消除掉的方块不断堆积起来，" << endl;
	cout << "一旦堆到屏幕顶端，玩家便告输，游戏结束。" << endl;

	cout << endl;

	cout << "游戏操作：" << endl;
	cout << "方块左移：←或a" << endl;
	cout << "方块右移：→或d" << endl;
	cout << "方块旋转：j" << endl;
	cout << "加速下落：↓或s" << endl;
	cout << "恢复正常速度：↑或w" << endl;
	cout << "暂停：p" << endl;

	createHelpOptions();
	drawOptions();
	while (1)
	{
		highLightOptions();
		string opt = chooseOption();
		if (opt != "unknown")
		{
			if (opt == "返回主菜单")
			{
				options.clear();
				clearScreen();
				mainMenu();
				return;
			}
		}
	}
}
