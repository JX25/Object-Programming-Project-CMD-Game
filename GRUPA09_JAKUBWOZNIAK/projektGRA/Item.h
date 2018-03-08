#include "lib.h"
#pragma once
class Item
{
protected:
	string itemName;
	string itemType;
public:
	Item(string,string);
	string virtual getName();
	string virtual getDescr();
	Item();
	~Item();
};

