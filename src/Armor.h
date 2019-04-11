#pragma once
#include "Item.h"
class Armor :
	public Item
{
	int price;
	int hp;
	int stamina;
	int baseDefence;
	friend class Hero;
	friend class Town;
public:
	void presentArmor();
	Armor(int);
	string getName();
	string getDescr();
	int getPrice();
	int getDefence();
	int getStamina();
	int getHP();
	Armor();
	Armor(string, string, int, int, int, int);
	~Armor();
};

