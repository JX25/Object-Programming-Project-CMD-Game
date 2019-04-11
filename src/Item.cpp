#include "Item.h"



Item::Item(string iN,string iT):itemName(iN),itemType(iT)
{
}
Item::Item()
{

}


Item::~Item()
{
}


string Item::getDescr()
{
	return itemType;
}

string Item::getName()
{
	return itemName;
}