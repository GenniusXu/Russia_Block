#include"mainMenu.h"

void createMenuOptions()
{
    short menu_option_left_limit = getConsoleWidth() / 2 - 8;
    short menu_option_top_limit = getConsoleHeight() / 2;
    //每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
    options.push_back(Option("开始游戏", { menu_option_left_limit,menu_option_top_limit, menu_option_left_limit + 18,menu_option_top_limit + 2 }));
    options.push_back(Option("游戏帮助", { menu_option_left_limit,menu_option_top_limit + 3, menu_option_left_limit + 18,menu_option_top_limit + 5 }));
    options.push_back(Option("退出", { menu_option_left_limit,menu_option_top_limit + 6, menu_option_left_limit + 18,menu_option_top_limit + 8 }));
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

//显示主菜单界面
void mainMenu()
{
    print_title();
    createMenuOptions();
    drawOptions();
    while (1)
    {
        highLightOptions();
        string opt = chooseOption();
        if (opt != "unknown")
        {
            if (opt == "开始游戏")
            {
                options.clear();
                clearScreen();
                game();
                break;
            }
            else if (opt == "游戏帮助")
            {
                options.clear();
                clearScreen();
                //暂时还没写------------------------------------之后会写
                //help();
                //暂时还没写------------------------------------之后会写
                break;
            }
            else if (opt == "退出")
            {
                exit(0);
            }
        }
    }
}

