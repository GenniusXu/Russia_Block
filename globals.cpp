#include"globals.h"

//注意，这里的是方块的个数，水平方向上一个方块占两个字符的位置
extern int playingArea_width = 30;
extern int playingArea_height = 37;
extern int informationArea_width = 20;
extern int informationArea_height = 37;

string player = "玩家1";
string password = "123456";
extern int score = 0;
extern int highestScore = 0;

extern int speed = 3;//方块下落速度（秒/格）

//二维数组，数组下标对应棋盘坐标，一格就是一格,而且包括边框也算在map里面
vector<vector<int> >map(playingArea_height, vector<int>(playingArea_width * 2, 0));

extern int warnningLine_height = 5;


sf::Sound backgroundMusic;//背景音乐对象
sf::SoundBuffer backgroundMusicBuffer;//背景音乐缓冲

bool backGroundMusic_isOpen = true;//记录背景音乐是否打开的变量
string backgroundMusicPath = "背景音乐.wav";//背景音乐文件路径