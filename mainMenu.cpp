#include"mainMenu.h"

void createMenuOptions()
{
    short menu_option_left_limit = getConsoleWidth() / 2 - 8;
    short menu_option_top_limit = getConsoleHeight() / 2;
    //每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
    options.push_back(Option("新的游戏", { menu_option_left_limit,menu_option_top_limit, menu_option_left_limit + 18,menu_option_top_limit + 2 }));
    options.push_back(Option("继续游戏", { menu_option_left_limit,menu_option_top_limit + 3, menu_option_left_limit + 18,menu_option_top_limit + 5 }));
    options.push_back(Option("游戏设置", { menu_option_left_limit,menu_option_top_limit + 6, menu_option_left_limit + 18,menu_option_top_limit + 8 }));
    options.push_back(Option("游戏帮助", { menu_option_left_limit,menu_option_top_limit + 9, menu_option_left_limit + 18,menu_option_top_limit + 11 }));
    //options.push_back(Option("排行榜", { menu_option_left_limit,menu_option_top_limit + 12, menu_option_left_limit + 18,menu_option_top_limit + 14 }));
    options.push_back(Option("退出", { menu_option_left_limit,menu_option_top_limit + 12, menu_option_left_limit + 18,menu_option_top_limit + 14 }));
}

//打印Tetris(俄罗斯方块)大标题
void print_title()
{
    int t = getConsoleWidth() / 2 - 20;
    int p = 9;
    print_T(t, p);
    print_E(t + 7, p);
    print_T(t + 14, p);
    print_R(t + 21, p);
    print_I(t + 28, p);
    print_S(t + 35, p);

    setColorAttr(40);
}

//打印排行榜信息
void showRankList()
{
    short rankList_left_limit = getConsoleWidth() / 2 + 30;
    short rankList_top_limit = getConsoleHeight() / 3 + 10;
    readRankList();
    setpos(rankList_left_limit + 8, rankList_top_limit - 3);
    cout << "光荣榜";
    setpos(rankList_left_limit, rankList_top_limit - 1);
    cout << left << setw(10) << "名次" << left << setw(10) << "玩家名" << left << setw(10) << "分数" << endl;

    int i = 1;
    for (multimap<int, string, std::greater<int>>::iterator it = rankList.begin(); it != rankList.end(); it++, i++)
    {
        if (i <= 10)
        {
            setpos(rankList_left_limit, rankList_top_limit + i);
            cout << left << setw(10) << i << left << setw(10) << it->second << left << setw(10) << it->first;
        }
    }
}

//在游戏开始前，弹出两个窗口，让用户设置地图高度和宽度
void setMapSizeByWindow()
{
    int height = stoi(GetDataFromWindow(L"请设置地图高度（20,37）"));
    int width = stoi(GetDataFromWindow(L"请设置地图宽度（15,30）"));
    //string height_string = GetDataFromWindow(L"请设置地图高度（20,37）");
    while (height < 20 || height > 37 || width < 15 || width > 30)
    {
        ShowMessageBox("高度或宽度不符合要求！");
        height = stoi(GetDataFromWindow(L"请设置地图高度（20,37）"));
        width = stoi(GetDataFromWindow(L"请设置地图宽度（15,30）"));
    }
    playingArea_height = height;
    playingArea_width = width;
}

//显示主菜单界面
void mainMenu()
{
    print_title();
    createMenuOptions();
    drawOptions();
    showRankList();
    while (1)
    {
        highLightOptions();
        string opt = chooseOption();
        if (opt != "unknown")
        {
            if (opt == "新的游戏")
            {
                options.clear();
                clearScreen();
                resetMap();
                setMapSizeByWindow();
                score = 0;
                game();
                break;
            }
            if (opt == "继续游戏")
            {
                options.clear();
                clearScreen();
                game();
                break;
            }
            else if (opt == "游戏设置")
            {
                options.clear();
                clearScreen();
                setting();
                break;
            }
            else if (opt == "游戏帮助")
            {
                options.clear();
                clearScreen();
                help();
                break;
            }
            else if (opt == "退出")
            {
                exit(0);
            }
        }
    }
}

