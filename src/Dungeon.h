#pragma once
#include "Hero.h"
#include "Enemy.h"
#include "Chest.h"
#include "lib.h"
#include "town.h"
struct typeOfField
{
	bool visited;
	bool hero;
	bool border;
	char what;
};

struct Field
{
	typeOfField type;
	Enemy *en;
	Chest *chest;
	Field();
};

class Dungeon
{
protected:
	Field **map;
	int N;
	Enemy *group1;
	Enemy *group2;
	Chest *chests;

public:
	bool moveHero(char,int,int);
	bool isEvent(Field);
	void setChestsAndEnemies();
	friend class Town;
	//friend class Interfaces;
	void ExploreDungeon(Hero &);
	void printDungeon();
	//void NormalDungeon(Hero &);
	//void HardDungeon(Hero&);
	//void FinalFight(Hero&);
	void setBorders();
	int Fight(Hero &, Enemy &);

	Dungeon(int);
	~Dungeon();
};


