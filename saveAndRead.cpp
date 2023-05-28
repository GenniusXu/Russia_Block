#include"saveAndRead.h"

//在注册账号时创建PlayerInfoRecords_player.dat文件并将其中数据初始化为默认值
void createPlayerInfo(string player, string password)
{
	//将当前数据全部存到PlayerInfo的数据成员中
	PlayerInfo info;
	strcpy_s(info.playerName, player.c_str());
	strcpy_s(info.password, password.c_str());
	info.highestScore = 0;
	info.height = 37;
	info.width = 20;
	for (int i = 0; i < 37; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			info.map[i][j] = 0;
		}
	}

	//将PlayerInfo写入文件
	ofstream f;
	f.open("PlayerInfoRecords_" + player + ".dat", ios::out | ios::binary);
	if (!f.is_open())
	{
		cerr << "文件打开失败！";
		return;
	}
	f.write((const char*)&info, sizeof(info));
	f.close();
}

//保存玩家信息到当前目录下的二进制文件PlayerInfoRecord.dat中
void savePlayerInfo()
{
	//将当前数据全部存到PlayerInfo的数据成员中
	PlayerInfo info;
	strcpy_s(info.playerName, player.c_str());
	strcpy_s(info.password, password.c_str());
	info.highestScore = highestScore;
	info.height = playingArea_height;
	info.width = playingArea_width;
	for (int i = 0; i < playingArea_height; i++)
	{
		for (int j = 0; j < playingArea_width * 2; j++)
		{
			info.map[i][j] = map[i][j];
		}
	}

	//将PlayerInfo写入文件
	ofstream f;
	f.open("PlayerInfoRecords_" + player + ".dat", ios::out | ios::binary);
	if (!f.is_open())
	{
		cerr << "文件打开失败！";
		return;
	}
	f.write((const char*)&info, sizeof(info));
	f.close();
}

// 从当前目录下的二进制文件PlayerInfoRecords_player.dat中读取玩家信息(player为当前玩家名)，若读取成功返回1，否则返回0
bool readPlayerInfo(string player_arg, string password_arg)
{
	// 将二进制文件中的数据全部读取到PlayerInfo中
	PlayerInfo info;
	ifstream f;
	f.open("PlayerInfoRecords_" + string(player_arg) + ".dat", ios::in | ios::binary);
	if (!f.is_open())
	{
		cerr << "文件打开失败！";
		return false;
	}
	f.read((char*)&info, sizeof(info));

	// 如果玩家名与密码匹配，才进行读取，否则提示用户名或密码错误
	if (password_arg.compare(info.password) == 0)
	{
		// 将PlayerInfo中的数据全部赋值给全局变量
		player = info.playerName;
		password = info.password;
		highestScore = info.highestScore;
		playingArea_height = info.height;
		playingArea_width = info.width;
		for (int i = 0; i < playingArea_height; i++)
		{
			for (int j = 0; j < playingArea_width * 2; j++)
			{
				map[i][j] = info.map[i][j];
			}
		}
	}
	else
	{
		// 弹出提示窗口“用户名或密码错误”
		ShowMessageBox("用户名或密码错误！");
		return false;
	}

	f.close();
	return true;
}
