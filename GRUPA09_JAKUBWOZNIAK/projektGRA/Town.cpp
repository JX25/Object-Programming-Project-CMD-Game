#include "Town.h"

Town::Town()
{
	GameDays = 0;
	GamePoints = 0;
	cout << "Type your city's name: ";
	while (true)
	{
		try
		{
			cin.ignore(100, '\n');
			cin.clear();

			getline(cin, nameOfCity, '\n');
			if (nameOfCity.length() < 1) throw Error(Error::errTooShort);
			for (int i = 0; i < nameOfCity.length(); i++)
			{
				if ((nameOfCity[i] == ' ' && nameOfCity[i + 1] == ' ') || (nameOfCity[i] == '-' && nameOfCity[i + 1] == '-')) throw Error(Error::errCity);
				if (nameOfCity[i] == ' ' || nameOfCity[i] == '-') continue;
				if (!isalpha(static_cast<int>(nameOfCity[i]))) throw Error(Error::errCity);
			}
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			cout << "Write you city's name name again!" << endl;
		}
	}
	mainHero;
}


Town::~Town()
{
}

void Town::visitMerchant()
{
	Interfaces::printMerchant(mainHero);
}

void Town::visitMedic()
{
	Interfaces::printMedic(mainHero);
}

void Town::visitBlacksmith()
{
	Interfaces::printBlacksmith(mainHero);
}

void Town::visitInnkeeper()
{
	Interfaces::printInnkeeper(mainHero);
}

void Town::sleepInSlums()
{
	Interfaces::printSleepInSlums(mainHero);
	GameDays++;
}


void Town::visitDungeons()
{
	Interfaces::printDungeon(mainHero);
}

void Town::Game()
{
	do
	{
		if (GamePoints > 600) Interfaces::printEndGame();
		system("cls");
		string choice;
		cout << "Small town: " << nameOfCity << endl;
		cout << "Day: " << GameDays << endl;
		cout << "Points: " << GamePoints << endl;
		cout << "There are some possibilities to go, what do you want to visit?" << endl;
		cout << " 1. Check Merchant's armors" << endl;
		cout << " 2. Check Blacksmith's weapons" << endl;
		cout << " 3. Go to Inn" << endl;
		cout << " 4. Sleep in the town" << endl;
		cout << " 5. Buy some medicines" << endl;
		cout << " 6. Visit Dungeons" << endl;
		if (GamePoints >= 500) cout << " 7.Final fight with boss" << endl;
		cout << " 9. Save game" << endl;
		cout << " 0. Exit the game" << endl;
		cout << endl;
		cout << "Hero Info: " << endl;
		cout << mainHero << endl;
		cout << "What are you going to do? ";
		try
		{
			cin >> choice;
			if (choice[0] == '7' && GamePoints < 500) throw Error(Error::errLevel);
			if (!correctChoice(choice, 0, 9)) throw Error(Error::errChoice);
			int ch = stoi(choice);
			switch (ch)
			{
			case 1:
				Town::visitMerchant();
				break;
			case 2:
				Town::visitBlacksmith();
				break;
			case 3:
				Town::visitInnkeeper();
				break;
			case 4:
				Town::sleepInSlums();
				break;
			case 5:
				Town::visitMedic();
				break;
			case 6:
				Town::visitDungeons();
				break;
			case 7:
				//final boss
				//
				break;
			case 9:
				this->save();
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "No options like that!" << endl;
				break;
			}
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
			system("cls");
		}


	} while (true);
}

bool fexists(const std::string& filename) {
	std::ifstream ifile(filename.c_str());
	return (bool)ifile;
}

void Town::save()
{
	fstream file;
	string filename;
	system("cls");
	if (CreateDirectory("\save", NULL)) cout << "Your saves are in 'save' folder";
	cout << endl;
	cout << "Save name: ";
	do {

		try
		{
			cin >> filename;
			cout << endl;
			filename = "\save\\" + filename + ".ddd";
			if (fexists(filename)) throw Error(Error::errFileName);
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(500);
		}
	} while (true);
	cout << "Creating your save: " << filename << endl;
	file.open(filename, fstream::out);

	//saving Hero's EQ
	file << this->mainHero.EQ.goldAmount() << ';' << this->mainHero.EQ.sizeOfPotionPack() << ';' << this->mainHero.EQ.sizeOfFoodPack() << endl;
	//saving weapon
	file << this->mainHero.weapon.getName() << ';' << this->mainHero.weapon.getDescr() << ';' << this->mainHero.weapon.getAttack() << ';';
	file << this->mainHero.weapon.getPrice() << ';' << this->mainHero.weapon.getWeight() << endl;
	//saving armor
	file << this->mainHero.armor.getName() << ';' << this->mainHero.armor.getDescr() << ';' << this->mainHero.armor.getPrice() << ';';
	file << this->mainHero.armor.getHP() << ';' << this->mainHero.armor.getStamina() << ';' << this->mainHero.armor.getDefence() << endl;
	//saving Hero
	file << this->mainHero.name << ';' << this->mainHero.race << ';' << this->mainHero.health;
	file << ';' << this->mainHero.stamina << ';' << this->mainHero.attack << ';' << this->mainHero.defence;
	file << ';' << this->mainHero.dexterity << ';' << this->mainHero.experience_points;
	file << ';' << this->mainHero.hpEveryLVL << ';' << this->mainHero.stEveryLVL << ';' << this->mainHero.level;
	file << ';' << this->mainHero.maxHealth << ';' << this->mainHero.maxStamina << endl;
	//saving Town
	file << nameOfCity << ';' << GameDays << ';' << GamePoints << endl;
	file.close();
	Sleep(1500);
}

void GetFilesInDirectory(std::vector<string> &out, const string &directory);

Town Town::load()
{
	system("cls");
	cout << "Wczytywanie pliku:" << endl;
	cout << "Lista plikow mozliwych do wczytania:" << endl;
	vector<string> lista_plikow;
	GetFilesInDirectory(lista_plikow, "\save");
	int ii = 1;
	for (vector<string>::iterator i = lista_plikow.begin(); i != lista_plikow.end(); ++i,++ii)
	{
		cout << ii << ") " << *i << endl;
	}
	//wczytywanie
	string filename;
	cout << endl;
	cout << "Load file name (with save and .ddd 'save/game.ddd'): ";
	do {

		try
		{
			cin >> filename;
			cout << endl;
			if (!fexists(filename)) throw Error(Error::errFileName);
			break;
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(500);
		}
	} while (true);

	fstream file;
	file.open(filename, ios::in);

	string line;
	
	// replace(line.begin(), line.end(), ' ', '_');

	//eq
	getline(file, line);
	replace(line.begin(), line.end(), ';', ' ');
	stringstream ss(line);
	int gold, potAm, fooAm;
	ss >> gold >> potAm >> fooAm;
	Equipment EQ = Equipment(gold, potAm, fooAm);
	//weapon
	getline(file, line);
	replace(line.begin(), line.end(), ' ', '_');
	replace(line.begin(), line.end(), ';', ' ');
	stringstream ww(line);
	string nameW, descrW;
	int att, price;
	double weight;
	ww >> nameW >> descrW >> att >> price >> weight;
	replace(nameW.begin(), nameW.end(), '_', ' ');
	replace(descrW.begin(), descrW.end(), '_', ' ');
	Weapon W = Weapon(nameW, descrW, att, price, weight);
	//armor
	getline(file, line);
	replace(line.begin(), line.end(), ' ', '_');
	replace(line.begin(), line.end(), ';', ' ');
	stringstream aa(line);
	string nameA, descrA;
	int priceA, hp, staminaA, defenceA;
	aa >> nameA >> descrA >> priceA >> hp >> staminaA >> defenceA;
	replace(nameA.begin(), nameA.end(), '_', ' ');
	replace(descrA.begin(), descrA.end(), '_', ' ');
	Armor A = Armor(nameA, descrA, priceA, hp, staminaA,defenceA);
	//hero
	getline(file, line);
	replace(line.begin(), line.end(), ' ', '_');
	replace(line.begin(), line.end(), ';', ' ');
	stringstream hh(line);
	string nameHero, race;
	int health, stamina, attack, defence, dexterity, exp, hplvl, stlvl, lvl, maxhp, maxst;
	hh >> nameHero >> race >> health >> stamina >> attack >> defence >> dexterity >> exp >> hplvl >> stlvl >> lvl >> maxhp >> maxst;
	replace(nameHero.begin(), nameHero.end(), '_', ' ');
	Hero H=Hero(nameHero, race, health, stamina, attack, defence, dexterity, exp, hplvl, stlvl, lvl, maxhp, maxst,EQ,W,A);
	//town
	getline(file, line);
	replace(line.begin(), line.end(), ' ', '_');
	replace(line.begin(), line.end(), ';', ' ');
	stringstream tt(line);
	string cityname;
	int points, days;
	tt >> cityname >> days >> points;
	replace(cityname.begin(), cityname.end(), '_', ' ');
	Town *T = new Town(cityname, days, points, &H);
	cout << "Your game is loading..." << endl;
	Sleep(1000);
	return *T;
}

Town::Town(string city, int d, int p, Hero* h)
{
	nameOfCity = city;
	GameDays = d;
	GamePoints = p;
	mainHero.operator=(*h) ;
}

void GetFilesInDirectory(std::vector<string> &out, const string &directory)
{
	HANDLE dir;
	WIN32_FIND_DATA file_data;

	if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		return; /* No files found */

	do {
		const string file_name = file_data.cFileName;
		const string full_file_name = directory + "/" + file_name;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		if (file_name[0] == '.')
			continue;

		if (is_directory)
			continue;

		out.push_back(full_file_name);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
} // GetFilesInDirectory