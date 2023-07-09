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
    options.push_back(Option("旋转", { setting_option_left_limit,setting_option_top_limit + 15, setting_option_left_limit + 18,setting_option_top_limit + 17 }));

    setpos(setting_option_left_limit2 + 3, setting_option_top_limit2 - 2);
    cout << "其他设置更改";
    options.push_back(Option("背景音乐", { setting_option_left_limit2,setting_option_top_limit, setting_option_left_limit2 + 18,setting_option_top_limit + 2 }));
    options.push_back(Option("消行音效", { setting_option_left_limit2,setting_option_top_limit + 3, setting_option_left_limit2 + 18,setting_option_top_limit + 5 }));
    options.push_back(Option("方块下落速度", { setting_option_left_limit2,setting_option_top_limit + 6, setting_option_left_limit2 + 18,setting_option_top_limit + 8 }));
    options.push_back(Option("自定义背景音乐", { setting_option_left_limit2,setting_option_top_limit + 9, setting_option_left_limit2 + 18,setting_option_top_limit + 11 }));
    options.push_back(Option("背景颜色", { setting_option_left_limit2,setting_option_top_limit + 12, setting_option_left_limit2 + 18,setting_option_top_limit + 14 }));

    options.push_back(Option("返回主菜单", { 2,30, 20,32 }));
    options.push_back(Option("恢复默认设置", { 22,30, 40,32 }));
}

//在按钮旁边显示当前设置的按键
void showCurrentKeyInfo()
{
    short setting_option_left_limit = 2 + 22;
    short setting_option_top_limit = 6 + 1;
    short setting_option_left_limit2 = 50 + 22;
    short setting_option_top_limit2 = 7 + 1;

    setpos(setting_option_left_limit, setting_option_top_limit);
    cout << key_for_pause;
    setpos(setting_option_left_limit, setting_option_top_limit + 3);
    cout << key_for_left;
    setpos(setting_option_left_limit, setting_option_top_limit + 6);
    cout << key_for_right;
    setpos(setting_option_left_limit, setting_option_top_limit + 9);
    cout << key_for_down;
    setpos(setting_option_left_limit, setting_option_top_limit + 12);
    cout << key_for_up;
    setpos(setting_option_left_limit, setting_option_top_limit + 15);
    cout << key_for_rotate;

    setpos(setting_option_left_limit2, setting_option_top_limit);
    if (backGroundMusic_isOpen)
    {
        cout << "开";
    }
    else
    {
        cout << "关";
    }
    setpos(setting_option_left_limit2, setting_option_top_limit + 3);
    if (clearSoundEffect_isOpen)
    {
        cout << "开";
    }
    else
    {
        cout << "关";
    }
    setpos(setting_option_left_limit2, setting_option_top_limit + 6);
    cout << "         ";
    setpos(setting_option_left_limit2, setting_option_top_limit + 6);
    cout << speed;
    setpos(setting_option_left_limit2, setting_option_top_limit + 9);
    cout << "                                                                                         ";
    setpos(setting_option_left_limit2, setting_option_top_limit + 9);
    cout << backgroundMusicPath;
    setpos(setting_option_left_limit2, setting_option_top_limit + 12);
    if (backgroundColor == 49 || backgroundColor == 40)
    {
        cout << "默认";
    }
    else
    {
        setColorAttr(backgroundColor);
        cout << "    ";
        setColorAttr(49);
    }

}

//检查按键设置是否有冲突，有就返回true，否则返回false，keyToCheck是被检测的按键
bool ifKeyConflict(char keyToCheck)
{
    char keys[7];//存放所有按键的数组
    keys[0] = key_for_down;
    keys[1] = key_for_left;
    keys[2] = key_for_pause;
    keys[3] = key_for_quit;
    keys[4] = key_for_right;
    keys[5] = key_for_rotate;
    keys[6] = key_for_up;
    for (int i = 0; i < sizeof(keys); i++)
    {
        if (keyToCheck == keys[i])
        {
            return true;
        }
    }
    return false;
}

//进入游戏设置界面
void setting()
{
    createSettingOptions();
    drawOptions();
    showCurrentKeyInfo();
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
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_pause = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "左移")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_left = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "右移")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_right = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "加速")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_down = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "恢复")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_up = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "旋转")
            {
                string s = GetDataFromWindow(L"请输入新的按键");
                if (s != "\0")
                {
                    if (!ifKeyConflict(s[0]))
                    {
                        //如果用户输入了一长串，则只取第一个字符
                        key_for_rotate = s[0];
                    }
                    else
                    {
                        ShowMessageBox("按键冲突！");
                    }
                }
            }
            else if (opt == "背景音乐")
            {
                //开就变关，关就变开
                backGroundMusic_isOpen = !backGroundMusic_isOpen;
            }
            else if (opt == "消行音效")
            {
                //开就变关，关就变开
                clearSoundEffect_isOpen = !clearSoundEffect_isOpen;
            }
            else if (opt == "方块下落速度")
            {
                string s = GetDataFromWindow(L"请输入新的方块下落速度(1-20)");
                if (s != "\0")
                {
                    //将字符串转成int
                    int tempSpeed = stoi(s);
                    if (tempSpeed <= 20 && 1 <= tempSpeed)
                    {
                        speed = tempSpeed;
                    }
                    else if (tempSpeed > 20)
                    {
                        speed = 20;
                    }
                }
            }
            else if (opt == "自定义背景音乐")
            {
                string path = GetDataFromWindow(L"请输入本地背景音乐路径");
                if (path == "\0")
                {
                    ShowMessageBox("路径不能为空！");
                    continue;
                }
                else if (path.size() >= 80)
                {
                    ShowMessageBox("路径过长！");
                    continue;
                }
                backgroundMusicPath = path;
            }
            else if (opt == "背景颜色")
            {
                //现在是黑色，点一下改成灰色
                if (backgroundColor == 49 || backgroundColor == 40)
                {
                    backgroundColor = 100;
                }
                //现在是灰色，点一下改成亮青色
                else if (backgroundColor == 100)
                {
                    backgroundColor = 106;
                }
                //现在是亮青色，点一下改成亮洋红色
                else if (backgroundColor == 106)
                {
                    backgroundColor = 105;
                }
                //现在是亮洋红色，点一下改成亮黑色
                else if (backgroundColor == 105)
                {
                    backgroundColor = 49;
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
                backGroundMusic_isOpen = true;
                clearSoundEffect_isOpen = true;
                backgroundMusicPath = "背景音乐.wav";
                clearSoundEffectPath = "消行音效.wav";
                speed = 5;
                backgroundColor = 49;
            }
            else if (opt == "返回主菜单")
            {
                options.clear();
                clearScreen();
                mainMenu();
                break;
            }
            showCurrentKeyInfo();//更新一下，显示新设置的按键信息
        }
    }
}