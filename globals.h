#pragma once
#include<string>
#include<vector>
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
extern vector<vector<int>>map;

//------------------------------------以下是有关游戏参数、游戏按键的全局变量------------------------------

extern int speed;


//------------------------------------以下是有关音效的全局变量------------------------------

extern sf::Sound backgroundMusic;//背景音乐对象
extern sf::SoundBuffer backgroundMusicBuffer;//背景音乐缓冲
extern bool backGroundMusic_isOpen;//记录背景音乐是否打开的变量
extern string backgroundMusicPath;//背景音乐文件路径

extern sf::Sound clearSoundEffect;//背景音乐对象
extern sf::SoundBuffer clearSoundEffectBuffer;//背景音乐缓冲
extern bool clearSoundEffect_isOpen;//记录背景音乐是否打开的变量
extern string clearSoundEffectPath;//背景音乐文件路径
