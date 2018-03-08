#include "Dungeon.h"

Field::Field()
{
	en = nullptr;
	chest = nullptr;
	type.visited = false;
	type.hero = false;
	type.border = false;
	type.what = ' ';
}

Dungeon::Dungeon(int step)
{

		N = 10 * step + 2;
		map = new Field*[N];
		for (size_t i = 0; i < N; i++) map[i] = new Field[N];
		//set borders
		setBorders();
		//player starting postion

		//players field properties
		map[1][N - 2].type.hero = true;
		map[1][N - 2].type.visited = false;
		map[1][N - 2].type.border = false;
		map[1][N - 2].type.what = '@';
		map[1][N - 2].en = nullptr;
		map[1][N - 2].chest = nullptr;

		//generate enemies and chests
		if (step==1)
		{
			group1 = new Enemy[5];
			group2 = new Enemy[5];
			for (int i = 0; i < 5; i++) group1[i] = Enemy::Skeleton();
			for (int i = 0; i < 5; i++) group2[i] = Enemy::Zombie();
			chests = new Chest[step*10];
			for (int i = 0; i <10; i++) chests[i] = Chest::Chest(200, 500, "Small chest");
		}
		else if (step == 2)
		{
			group1 = new Enemy[10];
			group2 = new Enemy[10];
			for (int i = 0; i < 10; i++) group1[i] = Enemy::Ghost();
			for (int i = 0; i < 10; i++) group2[i] = Enemy::Vampire();
			chests = new Chest[20];
			for (int i = 0; i <20; i++) chests[i] = Chest::Chest(500, 1500, "Medium chest");
		}
		else
		{
			group1 = new Enemy[25];
			group2 = new Enemy[25];
			for (int i = 0; i < 25; i++) group1[i] = Enemy::SkeletonDragon();
			for (int i = 0; i < 25; i++) group2[i] = Enemy::Lich();
			chests = new Chest[50];
			for (int i = 0; i <50; i++) chests[i] = Chest::Chest(2500, 5000, "Big chest");
		}

		setChestsAndEnemies();
}

Dungeon::~Dungeon()
{
	delete[] map;
	delete[] group1;
	delete[] group2;
	delete[] chests;
}


void Dungeon::setBorders()
{
	//poziomo
	for (int i = 0; i < N; i++)
	{
		map[i][0].type.border = true;
		map[i][0].type.visited = false;
		map[i][0].type.hero = false;
		map[i][0].type.what = 'X';

		map[i][N - 1].type.border = true;
		map[i][N - 1].type.visited = false;
		map[i][N - 1].type.hero = false;
		map[i][N - 1].type.what = 'X';
	}//pionowo
	for (int i = 0; i < N; i++)
	{
		map[0][i].type.border = true;
		map[0][i].type.visited = false;
		map[0][i].type.hero = false;
		map[0][i].type.what = 'X';

		map[N - 1][i].type.border = true;
		map[N - 1][i].type.visited = false;
		map[N - 1][i].type.hero = false;
		map[N - 1][i].type.what = 'X';
	}
	
}

void Dungeon::setChestsAndEnemies()
{
	int i = 0;
	//E1
	do
	{
		int x, y;
		x = rand() % (N - 2) + 1;
		y = rand() % (N - 2) + 1;

		if ( map[x][y].type.hero==false && map[x][y].en==nullptr && map[x][y].chest==nullptr )
		{
			map[x][y].en = &group1[i];
			map[x][y].type.what = '?';
			i++;
		}
		else continue;
	} while (i < N/2-1);
	//E2
	i = 0;
	do
	{
		int x, y;
		x = rand() % (N - 2) + 1;
		y = rand() % (N - 2) + 1;

		if (map[x][y].type.hero == false && map[x][y].en == nullptr && map[x][y].chest == nullptr)
		{
			map[x][y].en = &group2[i];
			map[x][y].type.what = '?';
			i++;
		}
		else continue;
	} while (i < N/2 - 1);
	//CH
	i = 0;
	do
	{
		int x, y;
		x = rand() % (N - 2) + 1;
		y = rand() % (N - 2) + 1;

		if (map[x][y].type.hero == false && map[x][y].en == nullptr && map[x][y].chest == nullptr)
		{
			map[x][y].chest = &chests[i];
			map[x][y].type.what = '?';
			i++;
		}
		else continue;
	} while (i < N  );
}

bool Dungeon::moveHero(char act,int x,int y)
{
	switch (act)
	{
	case 'm':
		return true;
	case 'f':
		return true;
	case '0':
		return true;
	case 'w':
		if (map[x ][y-1].type.border == false) return true;
		else return false;
		break;
	case 's':
		if (map[x ][y+1].type.border == false) return true;
		else return false;
		break;
	case 'a':
		if (map[x-1][y].type.border == false) return true;
		else return false;
		break;
	case 'd' :
		if (map[x+1][y].type.border == false) return true;
		else return false;
		break;
	default :
		cout << "\nError! No action with " << act << endl;
		return false;
	}
}

bool Dungeon::isEvent(Field p)
{
	//cout << "O" << endl;
	if (p.chest != nullptr) return true;
	if (p.en != nullptr) return true;
	else return false;
}



void Dungeon::ExploreDungeon(Hero &H)
{
	bool success = false;
	bool retreat = false;
	int player_x = 1;
	int player_y = N - 2;
	int prev_x, prev_y;
	int chestCounter = N - 2;
	do {
		system("cls");
		printDungeon();
		cout << H << endl;
		try
		{
			string action_string;
			cin >> action_string;
			char action = action_string[0];
			if (!moveHero(action, player_x, player_y)) throw Error(Error::errMove);
			if (action == '0') break;
			switch (action)
			{
			case 'm':
				H.heal();
				break;
			case 'f':
				H.eat();
				break;
			case 'd':
				if (isEvent(map[player_x + 1][player_y]))
				{
					if (map[player_x + 1][player_y].chest != nullptr && map[player_x + 1][player_y].chest->isOpened() == false)
					{
						H.buy(-map[player_x + 1][player_y].chest->openTheChest());
						Sleep(500);
						--chestCounter;
					}
					else if (map[player_x + 1][player_y].en != nullptr && map[player_x + 1][player_y].en->ifDefeated() == false)
					{
						int x=Fight(H, *(map[player_x + 1][player_y].en));
						if (x == 0) retreat = true;
						if (x == 2) Interfaces::printGameOver();
					}
				}
				//change previous field
				prev_x = player_x;
				prev_y = player_y;
				map[prev_x][prev_y].type.hero = false;
				map[prev_x][prev_y].type.visited = true;
				map[prev_x][prev_y].type.what = 'V';
				//moveplayer
				++player_x;
				map[player_x][player_y].type.hero = true;
				map[player_x][player_y].type.visited = false;
				map[player_x][player_y].type.what = '@';



				break;
			case 'a':
				if (isEvent(map[player_x - 1][player_y]))
				{
					if (map[player_x - 1][player_y].chest != nullptr && map[player_x - 1][player_y].chest->isOpened() == false)
					{
						H.buy(-map[player_x - 1][player_y].chest->openTheChest());
						Sleep(800);
						--chestCounter;
					}
					else if (map[player_x - 1][player_y].en != nullptr && map[player_x - 1][player_y].en->ifDefeated() == false)
					{
						int x=Fight(H, *(map[player_x - 1][player_y].en));
						if (x == 0) retreat = true;
						if (x == 2) Interfaces::printGameOver();
					}
				}
				//change previous field
				prev_x = player_x;
				prev_y = player_y;
				map[prev_x][prev_y].type.hero = false;
				map[prev_x][prev_y].type.visited = true;
				map[prev_x][prev_y].type.what = 'V';
				//moveplayer
				--player_x;
				map[player_x][player_y].type.hero = true;
				map[player_x][player_y].type.visited = false;
				map[player_x][player_y].type.what = '@';


				break;
			case 'w':
				if (isEvent(map[player_x][player_y - 1]))
				{
					if (map[player_x][player_y - 1].chest != nullptr && map[player_x][player_y - 1].chest->isOpened() == false)
					{
						H.buy(-map[player_x][player_y - 1].chest->openTheChest());
						Sleep(500);
						--chestCounter;
					}
					else if (map[player_x][player_y - 1].en != nullptr && map[player_x][player_y - 1].en->ifDefeated() == false)
					{
						int x = Fight(H, *(map[player_x][player_y -1 ].en));
						if (x == 0) retreat = true;
						if (x == 2) Interfaces::printGameOver();
					}
				}
				//change previous field
				prev_x = player_x;
				prev_y = player_y;
				map[prev_x][prev_y].type.hero = false;
				map[prev_x][prev_y].type.visited = true;
				map[prev_x][prev_y].type.what = 'V';
				//moveplayer
				--player_y;
				map[player_x][player_y].type.hero = true;
				map[player_x][player_y].type.visited = false;
				map[player_x][player_y].type.what = '@';


				break;
			case 's':
				if (isEvent(map[player_x][player_y + 1]))
				{
					if (map[player_x][player_y + 1].chest != nullptr && map[player_x][player_y + 1].chest->isOpened() == false)
					{
						H.buy(-map[player_x][player_y + 1].chest->openTheChest());
						Sleep(500);
						--chestCounter;
					}
					else if (map[player_x][player_y + 1].en != nullptr && map[player_x][player_y + 1].en->ifDefeated() == false)
					{
						int x=Fight(H, *(map[player_x ][player_y+1].en));
						if (x == 0) retreat = true;
						if (x == 2) Interfaces::printGameOver();
					}
				}
				//change previous field
				prev_x = player_x;
				prev_y = player_y;
				map[prev_x][prev_y].type.hero = false;
				map[prev_x][prev_y].type.visited = true;
				map[prev_x][prev_y].type.what = 'V';
				//moveplayer
				++player_y;
				map[player_x][player_y].type.hero = true;
				map[player_x][player_y].type.visited = false;
				map[player_x][player_y].type.what = '@';


				break;
			}
		}
		catch (Error &err)
		{
			cout << err.errorWhat() << endl;
			Sleep(2000);
		}

		if (chestCounter == 0)
		{
			success = true;
			break;
		}
		if (retreat == true)
		{
			break;
		}
	} while (H.checkHealth(0) > 0);

	if (success == true)
	{
		cout << "You found all of the chests congratulations!" << endl;
		Sleep(1000);
		GamePoints += N;
	}
	if (retreat == true)
	{
		cout << "You escaped from dungeon" << endl;
	}

	if (H.checkHealth(0) <= 0)
	{
		Interfaces::printGameOver();
	}
}

void Dungeon::printDungeon()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cout << map[j][i].type.what;
		cout << endl;
	}
	cout << endl;
	cout << "UP: w, DOWN: s, RIGHT: d, LEFT: a, \nPOTION: m, FOOD: f, LEAVE: 0" << endl;
}

int Dungeon::Fight(Hero &H, Enemy &E)
{
	int heroAttack;
	int enemyAttack;
	int heroDef=H.defence+H.armor.getDefence();
	do {
		heroAttack = 0;
		enemyAttack = 0;
		system("cls");
		Interfaces::printFight();
		cout << H << endl;
		cout << E << endl;
		cout << "Your action: ";
		//Interfaces::printControl();
		string choice;
		cin >> choice;
		if (correctChoice(choice, 1, 6))
		{
			int ch = stoi(choice);
			if (ch == 6) return 0;
			switch (ch)
			{
			case 1:
				if (H.stamina >= 20)
				{
					cout << "Preparing Quick attack" << endl;
					heroAttack = H.quickAttack();
				}
				else
				{
					heroAttack = 0;
					cout << "Not enough stamina points, you are resting" << endl;
					H.checkStamina(100);
				}
				break;
			case 2:
				if (H.stamina >= 50)
				{
					cout << "Preparing Power attack" << endl;
					heroAttack = H.powerAttack();
				}
				else
				{
					heroAttack = 0;
					cout << "Not enough stamina points, you are resting" << endl;
					H.checkStamina(100);
				}
				break;
			case 3:
				H.checkStamina(100);
				cout << "You recovered your Stamina" << endl;
				break;
			case 4:
				H.heal();
				cout << "You recovered your HP" << endl;
				break;
			case 5:
				H.eat();
				cout << "You recovered your HP" << endl;
				break;
			}
			//Enemy Turn!
			if (E.checkStamina(0) >= 20)
			{
				if (E.checkStamina(0) > 50)
				{
					enemyAttack = E.powerAttack();
					cout << "Enemy preparing power attack" << endl;
				}
				else
				{
					enemyAttack = E.quickAttack();
					cout << "Enemy preparing quick attack" << endl;
				}
			}
			else
			{
				E.wait();
				cout << "Enemy restoring his stamina" << endl;
			}

			//UDERZENIA:
			//GRACZ:
			if (E.dogde()) {
				heroAttack = 0;
				cout << "Enemy dogded your attack!" << endl;
			}
			else{
				if ((heroAttack - E.defend() ) < 0) heroAttack = 0;
				else heroAttack -= E.defend();
				E.suffer(  heroAttack );
				cout << "Enemy suffer " <<heroAttack << " dmg" << endl;
				if (E.isDefeated())
				{
					cout << "You slained your enemy!" << endl;
					H.lvlEXP(E.exp);
					E.defeated = true;
					system("pause");
					return 1;
				}
			}
			//PRZECIWNIK:
			if (H.dogde()) {
				enemyAttack = 0;
				cout << "You dogded enemy's attack!" << endl;
			}
			else {
				if ((enemyAttack - (H.defence + H.armor.getDefence())) < 0) enemyAttack = 0;
				else enemyAttack -= (H.defence + H.armor.getDefence());
				H.suffer( enemyAttack );
				cout << "You suffer " << enemyAttack  << " dmg" << endl;
				if (H.checkHealth(0)<=0)
				{
					cout << "You have been killed!" << endl;
					return 2;
				}
			}
		}
		else
		{
			cout << "There is no option like this!";
		}
		system("pause");
	} while (H.checkHealth(0) > 0 && E.checkHealth(0) > 0);
}