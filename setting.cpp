#include"setting.h"

//创建在setting窗口的按键
void createSettingOptions()
{
    short setting_option_left_limit = 2;
    short setting_option_top_limit = 6;
    short setting_option_left_limit2 = 50;
    short setting_option_top_limit2 = 6;

    //每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
    setpos(setting_option_left_limit + 3, setting_option_top_limit - 2);
    cout << "游戏按键更改";
    options.push_back(Option("暂停", { setting_option_left_limit,setting_option_top_limit, setting_option_left_limit + 18,setting_option_top_limit + 2 }));
    options.push_back(Option("左移", { setting_option_left_limit,setting_option_top_limit + 3, setting_option_left_limit + 18,setting_option_top_limit + 5 }));
    options.push_back(Option("右移", { setting_option_left_limit,setting_option_top_limit + 6, setting_option_left_limit + 18,setting_option_top_limit + 8 }));
    options.push_back(Option("加速", { setting_option_left_limit,setting_option_top_limit + 9, setting_option_left_limit + 18,setting_option_top_limit + 11 }));
    options.push_back(Option("恢复", { setting_option_left_limit,setting_option_top_limit + 12, setting_option_left_limit + 18,setting_option_top_limit + 14 }));

    setpos(setting_option_left_limit2 + 3, setting_option_top_limit2 - 2);
    cout << "其他设置更改";
    options.push_back(Option("背景音乐", { setting_option_left_limit2,setting_option_top_limit, setting_option_left_limit2 + 18,setting_option_top_limit +  2}));
    options.push_back(Option("方块下落速度", { setting_option_left_limit2,setting_option_top_limit + 3, setting_option_left_limit2 + 18,setting_option_top_limit + 5 }));
    
    options.push_back(Option("返回主菜单", { 2,30, 20,32 }));
    options.push_back(Option("恢复默认设置", { 22,30, 40,32 }));
}

//进入游戏设置界面
void setting()
{
    createSettingOptions();
    drawOptions();
    while (1)
    {
        highLightOptions();
        string opt = chooseOption();
        if (opt != "unknown")
        {
            if (opt == "暂停")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    //如果用户输入了一长串，则只取第一个字符
                    key_for_pause = s[0];
                }
            }
            else if (opt == "左移")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    //如果用户输入了一长串，则只取第一个字符
                    key_for_left = s[0];
                }
            }
            else if (opt == "右移")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    //如果用户输入了一长串，则只取第一个字符
                    key_for_right = s[0];
                }
            }
            else if (opt == "加速")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    //如果用户输入了一长串，则只取第一个字符
                    key_for_down = s[0];
                }
            }
            else if (opt == "恢复")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    //如果用户输入了一长串，则只取第一个字符
                    key_for_up = s[0];
                }
            }
            else if (opt == "背景音乐")
            {
                //开就变关，关就变开
                backGroundMusic_isOpen = !backGroundMusic_isOpen;
            }
            else if (opt == "方块下落速度")
            {
                string s = GetDataFromWindow(L"请输入新的方块下落速度");
                if (s != "\0")
                {
                    //将字符串转成int
                    speed = stoi(s);
                }
            }
            else if (opt == "恢复默认设置")
            {
                key_for_up = 'w';//代替↑的按键
                key_for_down = 's';//代替↓的按键
                key_for_left = 'a'; //代替←的按键
                key_for_right = 'd';//代替→的按键
                key_for_rotate = 'j';//代替旋转j的按键
                key_for_pause = 'p';//代替暂停p的按键
                key_for_quit = 'q';//代替返回主菜单q的按键
            }
            else if (opt == "返回主菜单")
            {
                options.clear();
                clearScreen();
                mainMenu();
                break;
            }
        }
    }
}