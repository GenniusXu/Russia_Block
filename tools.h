#pragma once
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include<iomanip>
#include<vector>
#include <Windows.h>
#include <codecvt>
#include<cstdlib>
#include<string>
#include<SFML/Audio.hpp>
#include"globals.h"

using namespace std;
#ifndef KEY_DOWN
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#endif
#define clean 0x2
#define box 0x4
#define full 0x1


//简中版Windows下控制台默认代码页为936(GBK), 如果直接显示UTF8内容会乱码, 此时需要用以下代码将代码页修改到兼容UTF-8的代码页.
//首先如果你使用msvc开发应用, 必须确保启用编译器的utf8模式
//好像这个程序里没什么用，用了反而乱码
void setConsoleUTF8();

//启用虚拟终端模式
//启用虚拟终端模式后可以在Windows中使用在Linux/Mac中可用的转义字符序列控制终端行为
//经测试虚拟终端功能仅支持win10及更新的系统.
bool EnableVTMode();

//获取当前窗口宽度
int getConsoleWidth();

//获取当前窗口高度
int getConsoleHeight();

int getLargestConsoleWidth();


int getLargestConsoleHeight();


//修改字符和背景颜色
//且只会修改setColorAttr(int attr)后的字符和背景颜色，原来的不会改，这个很好
//修改字符颜色建议使用VT模式完成
//下面代码首先需要启用VT模式
extern const char ESC;
extern const int ATTR_NORMAL; // 传入此常量可将当前颜色设置恢复为预设值
//前景色
enum ConsoleForeground : int;

// 背景色
enum ConsoleBackground : int;

void setColorAttr(int attr);

//调用后可以隐藏光标，等待输入时就不会一直有个东西在闪 
void HideCursor();        

//调用后可以显示光标，等待输入时就会一直有个东西在闪 
void ShowCursor();

//全屏
void fullScreen();

//GPT写的全屏函数
void SetWindowSizeToFullScreen();

//控制光标位置， 列， 行，横着数i格，数着数j格 
void setpos(int i, int j);

//更高效的清屏函数
void clearScreen();

//将光标位置设置到当前鼠标所指位置，并返回当前光标位置COORD结构体
COORD setCursorPosToMousePos();

//获取光标位置
COORD getCursorPos();


//移除控制台的快速编辑模式，使得无法用鼠标左键选择某个光标或区域，
//防止鼠标左键单击事件 与之冲突 导致鼠标左键点击判断无效
void disableQuickEditMode();


//隐藏控制台窗口的最大化按钮和窗口调整大小功能
void DisableMaximizeAndResize();


//隐藏控制台窗口边框
void HideConsoleWindowBorders();


//禁止移动窗口位置(好像没什么用)
void DisableMaximizeAndMove();

// 回调函数，处理窗口消息
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 创建窗口并获取用户输入(注意，参数是wstring类型，所以要传  L"xxx"  这样，而不能只是  "xxx" )
string GetDataFromWindow(wstring tips);

//弹出提示信息窗口
void ShowMessageBox(const string& msg);


//（循环）（后台）（非阻塞）播放指定路径的背景音乐
void PlayBackgroundMusic(string path);

//停止播放背景音乐
void stopBackgroundMusic();

//（单次）（后台）（非阻塞）播放指定路径的消行音效
void PlayClearSoundEffect(string path);