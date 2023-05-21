#pragma once
<<<<<<< HEAD
=======
#pragma once
>>>>>>> 3ca3518a029e0a3f2fe501d2a8a7a6b3893454f6
#include"Tools.h"
#include"Mouse.h"
#include"globals.h"

//画线字符(不用启用虚拟机模式也不会出现乱码）
//"┌","┐","└","┘","─","│","┼"

ostream& operator<<(ostream& cout, SMALL_RECT s);

class Option
{
public:
    Option(string s = "unknown", SMALL_RECT a = { 0,4,11,6 });
    void setName(string s);
    string getName();
    void setArea(SMALL_RECT a);
    SMALL_RECT getArea();
    void draw();
    bool isHighLight;

private:
    string name;//选项名称
    SMALL_RECT area;//选项图标范围
};

extern vector<Option>options;//管理所有选项控件的数组

//绘制所有图标
void drawOptions();

//遍历所有选项图标，如果鼠标的位置在图标区域，就highlight该图标
void highLightOptions();

//判断鼠标是否单击了某个选项，如果是，返回该选项的编号
string chooseOption();