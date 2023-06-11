#include"saveAndRead.h"

//在注册账号时创建PlayerInfoRecords_player.dat文件并将其中数据初始化为默认值
void createPlayerInfo(string player, string password)
{
	//将当前数据全部存到PlayerInfo的数据成员中
	PlayerInfo info;
	strcpy_s(info.playerName, player.c_str());
	strcpy_s(info.password, password.c_str());
	info.highestScore = 0;
	info.height = playingArea_height;
	info.width = playingArea_width;
	for (int i = 0; i < playingArea_height; i++)
	{
		for (int j = 0; j < playingArea_width * 2; j++)
		{
			info.map[i][j] = 0;
		}
	}
	info.speed = 5;//方块下落速度（秒/格）
	info.key_for_up = 'w';//代替↑的按键
	info.key_for_down = 's';//代替↓的按键
	info.key_for_left = 'a'; //代替←的按键
	info.key_for_right = 'd';//代替→的按键
	info.key_for_rotate = 'j';//代替旋转j的按键
	info.key_for_pause = 'p';//代替暂停p的按键
	info.key_for_quit = 'q';//代替返回主菜单q的按键
	info.backGroundMusic_isOpen = true;//记录背景音乐是否打开的变量
	strcpy_s(info.backgroundMusicPath, "背景音乐.wav");//背景音乐文件路径
	info.clearSoundEffect_isOpen = true;//记录背景音乐是否打开的变量
	strcpy_s(info.clearSoundEffectPath, "消行音效.wav");//消行音效文件路径

	//将PlayerInfo写入文件
	ofstream f;
	f.open("PlayerInfoRecords_" + player + ".dat", ios::out | ios::binary);
	if (!f.is_open())
	{
		ShowMessageBox("账号创建失败！");
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
			info.map[i][j] = map_game[i][j];
		}
	}
	info.speed = speed;//方块下落速度（秒/格）
	info.key_for_up = key_for_up;//代替↑的按键
	info.key_for_down = key_for_down;//代替↓的按键
	info.key_for_left = key_for_left; //代替←的按键
	info.key_for_right = key_for_right;//代替→的按键
	info.key_for_rotate = key_for_rotate;//代替旋转j的按键
	info.key_for_pause = key_for_pause;//代替暂停p的按键
	info.key_for_quit = key_for_quit;//代替返回主菜单q的按键
	info.backGroundMusic_isOpen = backGroundMusic_isOpen;//记录背景音乐是否打开的变量
	strcpy_s(info.backgroundMusicPath, backgroundMusicPath.c_str());//背景音乐文件路径
	info.clearSoundEffect_isOpen = clearSoundEffect_isOpen;//记录背景音乐是否打开的变量
	strcpy_s(info.clearSoundEffectPath, clearSoundEffectPath.c_str());//消行音效文件路径

	//将PlayerInfo写入文件
	ofstream f;
	f.open("PlayerInfoRecords_" + player + ".dat", ios::out | ios::binary);
	if (!f.is_open())
	{
		ShowMessageBox("游戏进度保存失败！");
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
		ShowMessageBox("用户不存在，登录失败！");
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
				map_game[i][j] = info.map[i][j];
			}
		}
		speed = info.speed;//方块下落速度（秒/格）
		key_for_up = info.key_for_up;//代替↑的按键
		key_for_down = info.key_for_down;//代替↓的按键
		key_for_left = info.key_for_left; //代替←的按键
		key_for_right = info.key_for_right;//代替→的按键
		key_for_rotate = info.key_for_rotate;//代替旋转j的按键
		key_for_pause = info.key_for_pause;//代替暂停p的按键
		key_for_quit = info.key_for_quit;//代替返回主菜单q的按键
		backGroundMusic_isOpen = info.backGroundMusic_isOpen;//记录背景音乐是否打开的变量
		backgroundMusicPath = info.backgroundMusicPath;//背景音乐文件路径
		clearSoundEffect_isOpen = info.clearSoundEffect_isOpen;//记录背景音乐是否打开的变量
		clearSoundEffectPath = info.clearSoundEffectPath;//背景音乐文件路径
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

//保存排行榜信息
void saveRankList()
{
	ofstream f;
	f.open("rankListRecord.dat", ios::out);
	if (!f.is_open())
	{
		ShowMessageBox("排行榜数据保存失败！");
		return;
	}
	int i = 1;
	for (const auto& pair : rankList) 
	{
		//只保存前十名的排行榜信息
		if (i > 10)
		{
			break;
		}
		f << pair.second << " " << pair.first << "\n";
		i++;
	}
	f.close();
}

//读取排行榜信息
void readRankList()
{
	rankList.clear();//先把现在rankList里面所有的内容清空，再重新从文件中读取，防止重复写入相同的内容
	ifstream f;
	f.open("rankListRecord.dat", ios::in);
	if (!f.is_open())
	{
		ShowMessageBox("排行榜数据读取存失败！");
		return;
	}
	int score;
	string name;
	while (f >> name >> score)
	{
		rankList.insert(make_pair(score, name));
	}
	f.close();
}