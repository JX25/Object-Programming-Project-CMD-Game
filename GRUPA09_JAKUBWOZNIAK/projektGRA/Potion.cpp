#include "Potion.h"



Potion::Potion():healthRecover(100),price(90),Item("Health potion","This mixture will bring you back to live")
{
}


Potion::~Potion()
{
}

int Potion::usePotion()
{
	cout << "You have just drink medicine!" << endl;
	return healthRecover;
}
