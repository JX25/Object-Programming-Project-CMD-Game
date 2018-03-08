#include "Interfaces.h"
#include "lib.h"
#include <iomanip>
#include "Dungeon.h"

Interfaces::Interfaces()
{
}

Interfaces::~Interfaces()
{
}

void Interfaces::printStart()
{
	cout << "Please choose option:" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Exit Game" << endl;

}

void Interfaces::printNewGame()
{
	system("cls");
	cout << "New Game" << endl;

}

void Interfaces::printMerchant(Hero &H)
{
	system("cls");
	Armor *store = new Armor[3];
	store[0] = Armor(0);
	store[1] = Armor(1);
	store[2] = Armor(3);
	string choice;
	do
	{
		try
		{
			cout << "You have visited local Merchant\n";
			cout << "These are his armors:\n";
			for (int i = 0; i < 3; i++) store[i].presentArmor();
			cout << "0. Exit the shop" << endl;
			cout << "Which armor would you like to buy? ";

			cin >> choice;
			if (!correctChoice(choice, 0, 3)) throw Error(Error::errChoice);
			int ch = stoi(choice);
			if (ch == 0) break;
			if (H.goldAmount() < store[ch-1].getPrice()) throw Error(Error::errMoney);
			H.changeArmor(store[ch-1]);
			H.buy(store[ch - 1].getPrice());
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}
	} while (true);

}

void Interfaces::printBlacksmith(Hero &H)
{
	system("cls");
	Weapon *store = new Weapon[3];
	store[0] = Weapon(0);
	store[1] = Weapon(1);
	store[2] = Weapon(3);

	string choice;
	do
	{
		try
		{
			cout << "You have visited local Blacksmith\n";
			cout << "These are his weapons:\n";
			for (int i = 0; i < 3; i++) store[i].presentWeapon();
			cout << "0. Exit the shop" << endl;
			cout << "Which weapon would you like to buy? ";

			cin >> choice;
			if (!correctChoice(choice, 0, 3)) throw Error(Error::errChoice);
			int ch = stoi(choice);
			if (ch == 0) break;
			if (H.goldAmount() < store[ch-1].getPrice()) throw Error(Error::errMoney);
			H.changeWeapon(store[ch-1]);
			H.buy(store[ch - 1].getPrice());
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}
	} while (true);

}

void Interfaces::printMedic(Hero &H)
{
	system("cls");
	string choice;
	do
	{
		try
		{
			cout << "You have opened door of local medic\n";
			cout << "This is his offer:\n";
			cout << "1. Mixture of health: +100HP cost: 90 gold" << endl;
			cout << "0. Exit the shop" << endl;
			cout << "Which weapon would you like to buy? ";
			cin >> choice;
			if (!correctChoice(choice, 0, 1)) throw Error(Error::errChoice);
			int ch = stoi(choice);
			if (ch == 0) break;
			if (H.goldAmount() < 100) throw Error(Error::errMoney);
			Potion p;
			H.buyPotion(p);
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}
	} while (true);

}

void Interfaces::printInnkeeper(Hero &H)
{
	system("cls");
	string choice;
	do
	{
		try
		{
			cout << "You have opened door of Rassback Inn\n";
			cout << "This is Innkeeper's  offer:\n";
			cout << "1. Fresh Bread: +10HP cost: 20 gold" << endl;
			cout << "2. Sleep: (recover your HP,ST ++nextday) 40 gold" << endl;
			cout << "0. Exit the bar" << endl;
			cout << "What would you do? ";

			cin >> choice;
			if (!correctChoice(choice, 0, 2)) throw Error(Error::errChoice);
			int ch = stoi(choice);
			if (ch == 0) break;
			if (ch==1 && H.goldAmount() < 20) throw Error(Error::errMoney);
			if (ch == 1 && H.goldAmount() >= 20)
			{
				Food f;
				H.buyFood(f);
			}
			if (ch == 2 && H.goldAmount() >=40 )
			{
				H.buy(40);
				H.checkHealth(10000);
				H.checkStamina(10000);
				++GameDays;
			}
			if (ch == 2 && H.goldAmount() < 40) throw Error(Error::errMoney);
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}
	} while (true);

}

void Interfaces::printSleepInSlums(Hero &H)
{
	H.checkHealth(50);
	H.checkStamina(50);
}

void Interfaces::printDungeon(Hero &H)
{
	system("cls");
	string choice;
	do
	{
		try
		{
			cout << "Which dungeon do you want to explore?\n";
			cout << "1. The nearest dungeon (easy)" << endl;
			cout << "2. The danger and dark dungeon (medium)" << endl;
			cout << "3. The dungeon, where nobody have returned (hard)" << endl;
			cout << "0. Exit the dungeons" << endl;
			cout << "What would you do? ";

			cin >> choice;
			if (!correctChoice(choice, 0, 3)) throw Error(Error::errChoice);
			int ch = stoi(choice);

			if (ch == 1)
			{
				Dungeon D1(1);
				D1.ExploreDungeon(H);
			}
			else if (ch == 2)
			{
				Dungeon D1(2);
				D1.ExploreDungeon(H);
			}
			else if(ch==3)
			{
				Dungeon D1(3);
				D1.ExploreDungeon(H);
			}
			else break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}
	} while (true);
}

void Interfaces::printGameOver()
{
	system("cls");
	cout << "You have died!" << endl;
	cout << "The game will shut down in 3 sec" << endl;
	Sleep(3000);
	exit(0);
}

void Interfaces::printEndGame()
{
	system("cls");
	cout << "You finished game!!!!!" << endl;
	cout << "Thank you for playing!" << endl;
	Sleep(15000);
	exit(0);
}

void Interfaces::printFight()
{
	system("cls");
	cout << "####################" << endl;
	cout << "1. Quick Attack" << endl;
	cout << "2. Power Attack" << endl;
	cout << "3. Wait" << endl;
	cout << "4. Eat food" << endl;
	cout << "5. Use potion" << endl;
	cout << "6. Run away!" << endl;
	cout << "####################" << endl;
}

void Interfaces::printLoadGame()
{
	cout << "Loading..." << endl;
}

void Interfaces::printSaveFile()
{
	system("cls");
	cout << "Do you want to save game?" << endl;
	cout << "1. Yes\n0. No" << endl;
}