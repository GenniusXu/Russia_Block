#include"Mouse.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 

using namespace std;
//右键单击就很正常，
//左键单击有问题，它不知道是单击还是选择，两次左键单击之间必须单击一次右键，有时右键单击也被当成左键
//(以上问题已解决，只需调用函数取消控制台的快速编辑模式即可)
//判断左键单击
bool click()
{
    static clock_t s = clock();
    clock_t e = clock();
    if (KEY_DOWN(VK_LBUTTON) && (e - s) / CLOCKS_PER_SEC > 0.03)//如果不加时间判断，会导致单击一次却被判断单击了很多次
    {
        s = clock();
        return true;
    }
    return false;
}
//判断右键单击事件，
bool click_Right()
{
    static clock_t s = clock();
    clock_t e = clock();
    if (KEY_DOWN(VK_RBUTTON) && (e - s) / CLOCKS_PER_SEC > 0.03)//如果不加时间判断，会导致单击一次却被判断单击了很多次
    {
        s = clock();
        return true;
    }
    return false;
}
//判断左键双击事件(好像不行，还是单击，而且会导致其他异常）
bool doubleClick()
{
    if (WM_LBUTTONDBLCLK)
    {
        return true;
    }
    return false;
}

//将某块矩形区域设置为白底黑字（highlight）
void highLightArea(SMALL_RECT area)
{
    //SMALL_RECT的初始化方式为“左上右下”

    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // 接收实际着色数量的变量
    DWORD getWrittenCount = 0;

    // 着色起点坐标
    //COORD writtenPos = { 5, 0 };
    COORD writtenPos = { 5, 0 };

    // 着色
    // 参数：控制台输出句柄，背景前景色代号，着色字符数量int，着色起点坐标COORD，接收实际着色数量的指针DWORD（没什么用，但一定要传，且不能为null）
    // eg: FillConsoleOutputAttribute(outputHandle, 0xF0, 9, writtenPos, &getWrittenCount);
    // 即从（5,0）开始（包括5）（坐标从0开始算）将后面9个字符变为白色背景，黑色字体
    // 详见Windows控制台API基本使用（下）  API介绍  一节
    for (short i = area.Top; i <= area.Bottom; i++)
    {
        writtenPos = { area.Left,i };
        FillConsoleOutputAttribute(outputHandle, 0XF0, area.Right - area.Left + 1, writtenPos, &getWrittenCount);
    }
}

//把highlight后的区域重置回原状（即黑底白字）
void resetArea(SMALL_RECT area)
{
    //SMALL_RECT的初始化方式为“左上右下”

    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // 接收实际着色数量的变量
    DWORD getWrittenCount = 0;

    // 着色起点坐标
    COORD writtenPos = { 5, 0 };

    // 着色
    // 参数：控制台输出句柄，背景前景色代号，着色字符数量int，着色起点坐标COORD，接收实际着色数量的指针DWORD（没什么用，但一定要传，且不能为null）
    // eg: FillConsoleOutputAttribute(outputHandle, 0xF0, 9, writtenPos, &getWrittenCount);
    // 即从（5,0）开始（包括5）（坐标从0开始算）将后面9个字符变为白色背景，黑色字体
    // 详见Windows控制台API基本使用（下）  API介绍  一节
    for (short i = area.Top; i <= area.Bottom; i++)
    {
        writtenPos = { area.Left,i };
        FillConsoleOutputAttribute(outputHandle, 07, area.Right - area.Left + 1, writtenPos, &getWrittenCount);
    }
}

//判断鼠标是否在某个矩形范围内
bool mouseInArea(SMALL_RECT area)
{
    //SMALL_RECT的初始化方式为“左上右下”
    HWND hwnd = GetForegroundWindow();
    POINT pt;
    GetCursorPos(&pt);
    //把窗口坐标系（原点在屏幕左上角）转换为客户区坐标系（原点在黑框框左上角）
    //如果调用成功，会将POINT结构体pt中记录的坐标转换为新的坐标
    // 所以一定要先GetCursorPos(&pt);再ScreenToClient(hwnd, &pt);否则没有用
    ScreenToClient(hwnd, &pt);
    // 输出句柄
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //经过测试的本电脑完美数据（一个字符宽度为8单位，高度为16单位，减1是避免光标位置与鼠标重叠，不好看）(只适用于此电脑，换了分辨率就不行)
    //int fontsize_x = 8;
    //int fontsize_y = 16;

    //通用公式，每行（列）像素值个数/每行（列）字符个数
    int fontsize_x = GetSystemMetrics(SM_CXFULLSCREEN) / getConsoleWidth();
    int fontsize_y = GetSystemMetrics(SM_CYFULLSCREEN) / getConsoleHeight();
    COORD pos;
    pos.X = pt.x / fontsize_x;
    pos.Y = pt.y / fontsize_y;

    if (area.Left <= pos.X && pos.X <= area.Right && area.Top <= pos.Y && pos.Y <= area.Bottom)
    {
        return true;
    }

    return false;
}

//获取鼠标在控制台坐标系下的坐标（一单位是一个字符）（我自己写的）
COORD getMousePosOfClient()
{
    HWND hwnd = GetForegroundWindow();
    POINT pt;
    GetCursorPos(&pt);
    //把窗口坐标系（原点在屏幕左上角）转换为客户区坐标系（原点在黑框框左上角）
    //如果调用成功，会将POINT结构体pt中记录的坐标转换为新的坐标
    // 所以一定要先GetCursorPos(&pt);再ScreenToClient(hwnd, &pt);否则没有用
    ScreenToClient(hwnd, &pt);
    // 输出句柄
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //经过测试的本电脑完美数据（一个字符宽度为8单位，高度为16单位，减1是避免光标位置与鼠标重叠，不好看）(只适用于此电脑，换了分辨率就不行)
    //int fontsize_x = 8;
    //int fontsize_y = 16;

    //通用公式，每行（列）像素值个数/每行（列）字符个数
    int fontsize_x = GetSystemMetrics(SM_CXFULLSCREEN) / getConsoleWidth();
    int fontsize_y = GetSystemMetrics(SM_CYFULLSCREEN) / getConsoleHeight();
    COORD pos;
    pos.X = pt.x / fontsize_x;
    pos.Y = pt.y / fontsize_y;
    return pos;
}
