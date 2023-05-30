#include"globals.h"

//------------------------------------以下是有关游戏区和信息区绘制的全局变量------------------------------

//注意，这里的是方块的个数，水平方向上一个方块占两个字符的位置
int playingArea_width = 30;
int playingArea_height = 37;
int informationArea_width = 20;
int informationArea_height = 37;
int warnningLine_height = 5;

//------------------------------------以下是有关玩家信息的全局变量------------------------------

string player = "玩家1";
string password = "123456";
int score = 0;
int highestScore = 0;
vector<vector<int> >map(playingArea_height, vector<int>(playingArea_width * 2, 0));//二维数组，数组下标对应棋盘坐标，一格就是一格,而且包括边框也算在map里面

//------------------------------------以下是有关游戏参数、游戏按键的全局变量------------------------------

int speed = 3;//方块下落速度（秒/格）


//------------------------------------以下是有关音效的全局变量------------------------------

sf::Sound backgroundMusic;//背景音乐对象
sf::SoundBuffer backgroundMusicBuffer;//背景音乐缓冲
bool backGroundMusic_isOpen = true;//记录背景音乐是否打开的变量
string backgroundMusicPath = "背景音乐.wav";//背景音乐文件路径

sf::Sound clearSoundEffect;//背景音乐对象
sf::SoundBuffer clearSoundEffectBuffer;//背景音乐缓冲
bool clearSoundEffect_isOpen = true;//记录背景音乐是否打开的变量
string clearSoundEffectPath = "消行音效.wav";//背景音乐文件路径