#pragma once
#include "Item.h"
class Weapon :
	public Item
{
protected:
	int price;
	int baseAttack;
	double weight;
	friend class Hero;
public:
	Weapon(int=0);
	Weapon(string, string, int, int, double);
	void presentWeapon();
	int getAttack();
	int getPrice();
	double getWeight();
	string getName();
	string getDescr();
	~Weapon();
};

