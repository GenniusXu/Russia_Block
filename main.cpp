#include<iostream>
#include"Block.h"
#include"globals.h"
#include"interface.h"
#include"tools.h"
#include"Block_I.h"
#include"Block_L.h"
#include"Block_Square.h"
#include"Block_T.h"
#include"Block_Z.h"
#include"testInformation.h"
#include<random>
<<<<<<< HEAD
=======
#include"game.h"
>>>>>>> 3ca3518a029e0a3f2fe501d2a8a7a6b3893454f6
#include"mainMenu.h"
using namespace std;


int main()
{
	disableQuickEditMode();
	EnableVTMode();
	fullScreen();
	HideCursor();
	while (1)
	{
		mainMenu();
	}
	return 0;
}