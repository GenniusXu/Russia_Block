#pragma once
#include<string>
#include<vector>
#include<map>
#include<SFML/Audio.hpp>
using namespace std;

//------------------------------------以下是有关游戏区和信息区绘制的全局变量------------------------------

extern int playingArea_width;
extern int playingArea_height;
extern int informationArea_width;
extern int informationArea_height;
extern int warnningLine_height;

//------------------------------------以下是有关玩家信息的全局变量------------------------------

extern string player;
extern string password;
extern int score;
extern int highestScore;
extern vector<vector<int>>map_game;

//自定义分数排序方式
struct ScoreComparator
{
    bool operator()(const pair<string, int> p1, const pair<string, int> p2) const
    {
        return p1.second > p2.second;  // 按分数降序排序
    }
};
extern multimap<int, string, std::greater<int>>rankList;

//------------------------------------以下是有关游戏参数、游戏按键的全局变量------------------------------

extern int speed;//方块下落速度
extern char key_for_up;//代替↑的按键
extern char key_for_down;//代替↓的按键
extern char key_for_left; //代替←的按键
extern char key_for_right;//代替→的按键
extern char key_for_rotate;//代替旋转j的按键
extern char key_for_pause;//代替暂停p的按键
extern char key_for_quit;//代替返回主菜单q的按键



//------------------------------------以下是有关音效的全局变量------------------------------

extern sf::Sound backgroundMusic;//背景音乐对象
extern sf::SoundBuffer backgroundMusicBuffer;//背景音乐缓冲
extern bool backGroundMusic_isOpen;//记录背景音乐是否打开的变量
extern string backgroundMusicPath;//背景音乐文件路径

extern sf::Sound clearSoundEffect;//消行音效对象
extern sf::SoundBuffer clearSoundEffectBuffer;//消行音效缓冲
extern bool clearSoundEffect_isOpen;//记录消行音效是否打开的变量
extern string clearSoundEffectPath;//消行音效文件路径
