#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "Hero.h"
#include "Enemy.h"

class Interfaces
{
public:
	Interfaces();
	~Interfaces();

	void static printStart();
	void static printNewGame();
	void static printLoadGame();
	void static printSaveFile();
	void static printEndGame();
	void static printGameOver();

	void static printMerchant(Hero &H);
	void static printBlacksmith(Hero &H);
	void static printMedic(Hero &H);
	void static printInnkeeper(Hero &H);
	void static printSleepInSlums(Hero &H);
	void static printDungeon(Hero &H);
	void static printFight();

};

