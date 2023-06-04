#include"testInformation.h"

//输出map_game每个元素的值
void printMapInfo()
{
	setpos(2, 1);
	cout << map_game.size() << "  " << map_game[0].size();
	for (int i = 0; i < map_game.size(); i++)
	{
		setpos(playingArea_width * 2 + 5, i);
		for (int j = 0; j < map_game[0].size(); j += 2)
		{
			cout << setw(2) << map_game[i][j];
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
	//map_game = info.map_game;	

	cout << player << endl << password << endl << highestScore << endl << playingArea_height << endl << playingArea_width << endl;
	f.close();
}

//插入排行榜数据并打印排行榜
void insertAndPrintRankList()
{
	rankList.insert(make_pair(100, "张三"));
	rankList.insert(make_pair(200, "张三"));
	rankList.insert(make_pair(500, "李四"));
	rankList.insert(make_pair(400, "王五"));
	rankList.insert(make_pair(300, "赵六"));

	saveRankList();
	cout << "保存完毕" << endl;
	
	for (multimap<int, string, std::greater<int>>::iterator it = rankList.begin(); it != rankList.end(); it++)
	{
		cout << "Player: " << it->second << ", Score: " << it->first << endl;
	}
	readRankList();
	cout << "读取完毕" << endl;
	for (multimap<int, string, std::greater<int>>::iterator it = rankList.begin(); it != rankList.end(); it++)
	{
		cout << "Player: " << it->second << ", Score: " << it->first << endl;
	}
}