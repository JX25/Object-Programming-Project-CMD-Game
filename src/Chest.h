#pragma once
#include "Item.h"
class Chest : public Item
{
protected:
	int goldInBox;
	bool opened;
public:
	Chest();
	Chest(int, int, string);
	bool isOpened();
	int gold();
	int openTheChest();
	~Chest();
};

