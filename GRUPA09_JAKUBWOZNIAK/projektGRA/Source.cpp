#include "lib.h"
#include "Town.h"
#include "Interfaces.h"
#include <cstdio>

int main()
{
	srand(time(NULL));
	HWND hwnd = GetConsoleWindow();
	if( hwnd != NULL ){ MoveWindow(hwnd ,0,0 ,800,800 ,TRUE); } //ustawienie okna konsoli
	system("cls");
	cout << "Welcome in the game Darker Dungeon v0.0.15 alpha" << endl; //ekran startowy
	string option;
	do
	{
		Interfaces::printStart();
		try
		{
			cout << "Your choice: ";
			cin >> option;
			cout << endl;
			if (!correctChoice(option, 1, 3)) throw Error(Error::errChoice);
			break;
		}
		
		catch (Error &err)
		{
			system("cls");
			cout << err.errorWhat() << endl;
		}
		
	} while (true);

	int choose = stoi(option);

	//Tryb GRY
	if (choose == 1)//Nowa gra
	{
		Town Estate;
		Estate.Game();
	}
	else if (choose == 2)//Wczytywanie
	{
		Town Estate = Town::load();
		Estate.Game();
		//Town Estate(loadFile());
	}
	else exit(0);
}