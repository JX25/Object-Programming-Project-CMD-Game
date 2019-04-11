#pragma once
#include "lib.h"
#include "Food.h"
#include "Potion.h"

class Equipment
{
protected:
	vector<Food> packOfFood;
	vector<Potion> packOfPotion;
	int gold;
	friend class Town;
public:
	Equipment();
	Equipment(int, int, int);
	void addPotion(Potion);
	int usePotion();
	void addFood(Food);
	int useFood();
	int goldAmount();
	void buy(int);
	int sizeOfFoodPack();
	int sizeOfPotionPack();
	~Equipment();
};

