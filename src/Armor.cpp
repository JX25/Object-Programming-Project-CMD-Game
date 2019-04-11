#include "Armor.h"
#include <iomanip>

Armor::Armor() {};

Armor::Armor(int stop)
{
	string adjectives[] = { "Leather","Old","Leaky","Non-amplified","Damaged" };
	string adjectivesGood[] = { "Silver","Steel","Iron","Gleaming","Fortified" };
	string adjectivesBetter[] = { "Heavenly","Devilish","Fiery","Lightning","Undead" };

	if (stop == 0)
	{
		itemName = adjectives[rand() % 5] + " " + "Coat";
		itemType = "Common armor";
		price = rand() % 500 + 1500;
		hp = (rand() % 6 + 1)*50;
		stamina = (rand() % 10 + 1)*25;
		baseDefence = (rand() % 10 + 1) * 5;
	}
	else if (stop == 1)
	{
		itemName = adjectivesGood[rand() % 5] + " " + "Hauberk";
		itemType = "Good armor";
		price = rand() % 3000 + 3000;
		hp = (rand() % 6 + 1) * 100;
		stamina = (rand() % 10 + 1) * 20;
		baseDefence = (rand() % 5 + 1) * 15;
	}
	else
	{
		itemName = adjectivesGood[rand() % 5] + " " + "Cuirass";
		itemType = "Rare armor";
		price = rand() % 4000 + 8000;
		hp = (rand() % 6 + 1) * 250;
		stamina = (rand() % 10 + 1) * 15;
		baseDefence = (rand() % 5 + 5) * 15;
	}
}

Armor::~Armor()
{
}

void Armor::presentArmor()
{
	cout << "#########################" << endl;
	cout << "# Name: " << itemName <<endl;
	cout << "# Health Points: +" << hp << endl;
	cout << "# Stamina: +" << stamina  << endl;
	cout << "# Base defence: +" << baseDefence <<  endl;
	cout << "# Price: " << price <<  endl;
	cout << "# Description: " << itemType << endl;
	cout << "#########################" << endl;

}

int Armor::getPrice()
{
	return price;
}

string Armor::getName()
{
	return itemName;
}
int Armor::getDefence()
{
	return baseDefence;
}

string Armor::getDescr()
{
	return itemType;
}

int Armor::getStamina()
{
	return stamina;
}

int Armor::getHP()
{
	return hp;
}

Armor::Armor(string n, string d, int p, int h, int st, int def) :Item(n, d), price(p), hp(h), stamina(st), baseDefence(def)
{}