#include"LoginAndRegister.h"

//生成注册和登录界面的按钮
void createLoginAndRegisterOptions()
{
    short menu_option_left_limit = getConsoleWidth() / 2 - 8;
    short menu_option_top_limit = getConsoleHeight() / 2;
    //每个控件在y方向占3格，所以RECT的第二个和第四个参数每加一行就加3就行
    options.push_back(Option("注册", { menu_option_left_limit,menu_option_top_limit, menu_option_left_limit + 18,menu_option_top_limit + 2 }));
    options.push_back(Option("登录", { menu_option_left_limit,menu_option_top_limit + 3, menu_option_left_limit + 18,menu_option_top_limit + 5 }));
    options.push_back(Option("退出", { menu_option_left_limit,menu_option_top_limit + 6, menu_option_left_limit + 18,menu_option_top_limit + 8 }));
    //options.push_back(Option("游戏帮助", { menu_option_left_limit,menu_option_top_limit + 9, menu_option_left_limit + 18,menu_option_top_limit + 11 }));
    //options.push_back(Option("退出", { menu_option_left_limit,menu_option_top_limit + 12, menu_option_left_limit + 18,menu_option_top_limit + 14 }));


}


//显示注册和登录界面
void LoginAndRegister()
{
    print_title();
    createLoginAndRegisterOptions();
    drawOptions();
    while (1)
    {
        highLightOptions();
        string opt = chooseOption();
        if (opt != "unknown")
        {
            if (opt == "注册")
            {
                //strcpy_s(player, GetUsernameFromWindow().c_str());
                //strcpy_s(password, GetPasswordFromWindow().c_str());
                player = GetDataFromWindow(L"请输入用户名");
                if (player == "\0")
                {
                    ShowMessageBox("用户名不能为空！");
                    continue;
                }
                password = GetDataFromWindow(L"请设置密码");
                if (password == "\0")
                {
                    ShowMessageBox("密码不能为空！");
                    continue;
                }
                createPlayerInfo(player, password);
                ShowMessageBox("注册成功！");
                options.clear();
                clearScreen();
                mainMenu();
                break;
            }
            if (opt == "登录")
            {
                //strcpy_s(player, GetUsernameFromWindow().c_str());
                //strcpy_s(password, GetPasswordFromWindow().c_str());
                player = GetDataFromWindow(L"请输入用户名");
                if (player == "\0")
                {
                    ShowMessageBox("用户名不能为空！");
                    continue;
                }
                password = GetDataFromWindow(L"请输入密码");
                if (password == "\0")
                {
                    ShowMessageBox("密码不能为空！");
                    continue;
                }
                //读取成功进入游戏菜单界面，读取失败仍停留在当前界面
                if (readPlayerInfo(player, password))
                {
                    options.clear();
                    clearScreen();
                    mainMenu();
                    break;
                }
            }
            else if (opt == "退出")
            {
                exit(0);
            }
        }
    }
}
