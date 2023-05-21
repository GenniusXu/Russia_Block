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
#include"game.h"
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