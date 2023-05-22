#include"mainMenu.h"

void createMenuOptions()
{
    short menu_option_left_limit = getConsoleWidth() / 2 - 8;
    short menu_option_top_limit = getConsoleHeight() / 2;
    //每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
    options.push_back(Option("开始游戏", { menu_option_left_limit,menu_option_top_limit, menu_option_left_limit + 18,menu_option_top_limit + 2 }));
    options.push_back(Option("游戏设置", { menu_option_left_limit,menu_option_top_limit + 3, menu_option_left_limit + 18,menu_option_top_limit + 5 }));
    options.push_back(Option("游戏帮助", { menu_option_left_limit,menu_option_top_limit + 6, menu_option_left_limit + 18,menu_option_top_limit + 8 }));
    options.push_back(Option("退出", { menu_option_left_limit,menu_option_top_limit + 9, menu_option_left_limit + 18,menu_option_top_limit + 11 }));
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

