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

	//下面是按键、音乐、速度等设置信息
	int speed = 5;//方块下落速度（秒/格）
	char key_for_up;//代替↑的按键
	char key_for_down;//代替↓的按键
	char key_for_left; //代替←的按键
	char key_for_right;//代替→的按键
	char key_for_rotate;//代替旋转j的按键
	char key_for_pause;//代替暂停p的按键
	char key_for_quit;//代替返回主菜单q的按键
	bool backGroundMusic_isOpen = true;//记录背景音乐是否打开的变量
	char backgroundMusicPath[100];//背景音乐文件路径
	bool clearSoundEffect_isOpen = true;//记录背景音乐是否打开的变量
	char clearSoundEffectPath[100];//背景音乐文件路径
};


//在注册账号时创建PlayerInfoRecords_player.dat文件并将其中数据初始化为默认值
void createPlayerInfo(string player, string password);

//保存玩家信息到当前目录下的二进制文件PlayerInfoRecord.dat中
void savePlayerInfo();

//从当前目录下的二进制文件PlayerInfoRecords_player.dat中读取玩家信息(player为当前玩家名)，若读取成功返回1，否则返回0
bool readPlayerInfo(string player_arg, string password_arg);

//保存排行榜信息
void saveRankList();

//读取排行榜信息
void readRankList();