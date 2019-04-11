#pragma once
#include "Item.h"
class Potion :
	public Item
{
protected:
	int price;
	int healthRecover;
public:
	Potion();
	int usePotion();
	~Potion();
};

