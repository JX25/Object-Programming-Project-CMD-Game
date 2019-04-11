#include "Equipment.h"




Equipment::Equipment()
{
	packOfFood.clear();
	packOfPotion.clear();
	gold = 0;
}


Equipment::~Equipment()
{
}

void Equipment::addPotion(Potion P)
{
	packOfPotion.push_back(P);
}

void Equipment::addFood(Food F)
{
	packOfFood.push_back(F);
}

int Equipment::usePotion()
{
	if (packOfPotion.empty())
	{
		return 0;
	}
	
	Potion p = packOfPotion.back();
	packOfPotion.pop_back();
	return p.usePotion();
}

int Equipment::useFood()
{
	if (packOfFood.empty())
	{
		return 0;
	}

	Food f = packOfFood.back();
	packOfFood.pop_back();
	return f.eatFood();
}

int Equipment::goldAmount()
{
	return gold;
}

void Equipment::buy(int price)
{
	gold -= price;
}

int Equipment::sizeOfFoodPack()
{
	return (packOfFood.size());
}

int Equipment::sizeOfPotionPack()
{
	return (packOfPotion.size());
}

Equipment::Equipment(int g, int p, int f)
{
	gold = g;
	Potion pot;
	for (int i = 0; i < p; i++) this->addPotion(pot);
	Food food;
	for (int i = 0; i < p; i++) this->addFood(food);
}