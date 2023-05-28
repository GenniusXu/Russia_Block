#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"globals.h"
#include<string>
#include<fstream>
#include<Windows.h>
#include"tools.h"
using namespace std;

//一个存储着游戏玩家所有信息的类
class PlayerInfo
{
public:
	char playerName[40];//用户名
	char password[40];//密码
	int highestScore;//历史最高分
	int height;//地图高度
	int width;//地图宽度
	int map[37][60];//地图二维数组
	//注意！！！！
	//注意！！！！
	//注意！！！！
	//map必须为大小确定的二维数组，不能是vector，否则读取二进制文件时容易造成访问权限冲突（因为你的sizeof(PlayerInfo)不确定）
};


//在注册账号时创建PlayerInfoRecords_player.dat文件并将其中数据初始化为默认值
void createPlayerInfo(string player, string password);

//保存玩家信息到当前目录下的二进制文件PlayerInfoRecord.dat中
void savePlayerInfo();

//从当前目录下的二进制文件PlayerInfoRecords_player.dat中读取玩家信息(player为当前玩家名)，若读取成功返回1，否则返回0
bool readPlayerInfo(string player_arg, string password_arg);