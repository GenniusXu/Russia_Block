#pragma once
//所有输出测试数据或者测试函数效果的模块都放在这个头文件里

#include"globals.h"
#include<iostream>
#include"tools.h"
#include<iomanip>
using namespace std;

//输出map每个元素的值
void printMapInfo()
{
	setpos(2, 1);
	cout << map.size() << "  " << map[0].size();
	for (int i = 0; i < map.size(); i++)
	{
		setpos(playingArea_width * 2 + 5, i);
		for (int j = 0; j < map[0].size(); j += 2)
		{
			cout << setw(2) << map[i][j];
		}
	}
}