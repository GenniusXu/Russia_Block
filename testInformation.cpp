#include"testInformation.h"

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

void printFileInfo(string player_arg)
{
	PlayerInfo info;
	ifstream f;
	f.open("PlayerInfoRecords_" + string(player_arg) + ".dat", ios::in | ios::binary);
	if (!f.is_open())
	{
		cerr << "文件打开失败！";
		return;
	}
	f.read((char*)&info, sizeof(info));

	// 将PlayerInfo中的数据全部赋值给全局变量
	player = info.playerName;
	password = info.password;
	highestScore = info.highestScore;
	playingArea_height = info.height;
	playingArea_width = info.width;
	//map = info.map;	

	cout << player << endl << password << endl << highestScore << endl << playingArea_height << endl << playingArea_width << endl;
	f.close();
}