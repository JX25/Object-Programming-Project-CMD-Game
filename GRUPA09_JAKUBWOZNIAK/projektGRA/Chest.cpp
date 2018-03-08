#include "Chest.h"



Chest::Chest():goldInBox(350),opened(false),Item("Chest","Some amount of gold hidden in the box")
{}

Chest::Chest(int Od, int Do,string chN) : goldInBox(rand() % (Do - Od) + Od),opened(false),Item(chN, "Some amount of gold hidden in the box")
{}

int Chest::openTheChest()
{
	cout << "The chest has been opened!" << endl;
	cout << "You found " << goldInBox << " gold" << endl;
	opened = true;
	Sleep(800);
	return goldInBox;
}

bool Chest::isOpened()
{
	return opened;
}

int Chest::gold()
{
	return goldInBox;
}

Chest::~Chest()
{}
