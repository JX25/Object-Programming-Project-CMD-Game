#pragma once
#include "lib.h"
class Character
{
protected:
	string name;
	string race;
	int health;
	int stamina;
	int attack;
	int defence;
	int dexterity;
public:
	 Character();
	 ~Character();
	virtual int quickAttack();
	virtual int powerAttack();
	virtual int defend();
	virtual void wait();
	virtual bool dogde();
	virtual void suffer();
	bool isDefeated(int);
	friend class Town;
};

