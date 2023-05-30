#pragma once
#include<string>
#include<vector>
#include<SFML/Audio.hpp>
using namespace std;

extern int playingArea_width;
extern int playingArea_height;
extern int informationArea_width;
extern int informationArea_height;

extern string player;
extern string password;
extern int score;
extern int highestScore;

extern int speed;

extern vector<vector<int>>map;

extern int warnningLine_height;

extern sf::Sound backgroundMusic;//背景音乐对象
extern sf::SoundBuffer backgroundMusicBuffer;//背景音乐缓冲

extern bool backGroundMusic_isOpen;//记录背景音乐是否打开的变量
extern string backgroundMusicPath;