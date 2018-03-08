#pragma once
#include "Global.h"
#include "Hero.h"
#include "Interfaces.h"
#include <fstream>
#include <sstream>
class Town
{
protected:
	string nameOfCity;
	Hero mainHero;
public:
	void Game();
	friend class Hero;
	void visitMerchant();
	void visitBlacksmith();
	void visitMedic();
	void visitInnkeeper();
	void sleepInSlums();
	void visitDungeons();
	void save();
	Town static load();
	//void finalFight();
	Town();
	Town(string, int, int, Hero*);
	~Town();
};
