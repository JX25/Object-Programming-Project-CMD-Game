#pragma once
#include "Item.h"
class Food :
	public Item
{
protected:
	int price;
	int healthRecover;
public:
	Food(int, int ,string, string);
	Food();
	int eatFood();
	~Food();
};

