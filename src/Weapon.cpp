#include "Weapon.h"



Weapon::Weapon(int stop)
{
	string adjectives[] = { "wooden","jagged","rusted","broken","damaged" };
	string adjectivesGood[] = { "silver","steel","iron","gleaming","fortified" };
	string adjectivesBetter[] = { "ruby","devilish","heavenly","bloody","dark" };


	if (stop == 0)
	{
		itemName = adjectives[rand() % 5] + " " + "sword";
		itemType = "Common sword";
		price = rand() % 1500 + 500;
		baseAttack = rand() % 10 + 5;
		weight = static_cast<double>((rand() % 10 + 1) / 10)+0.1;
	}
	else if (stop == 1)
	{
		itemName = adjectivesGood[rand() % 5] + " " + "1h sword";
		itemType = "Universal sword";
		price = rand() % 2500 + 2000;
		baseAttack = rand() % 60 + 15;
		weight = (rand() % 20 + 10) / 10;
	}
	else
	{
		itemName = adjectivesGood[rand() % 5] + " " + "2h sword";
		itemType = "Powerful sword";
		price = rand() % 4000 + 7000;
		baseAttack = rand() % 120 + 50;
		weight = (rand() % 50 + 30) / 10;
	}
}


Weapon::~Weapon()
{
}

void Weapon::presentWeapon()
{
	cout << "#########################" << endl;
	cout << "# Name: " << itemName << endl;
	cout << "# Attack: +" << baseAttack << endl;
	cout << "# Weight: " << weight << endl;
	cout << "# Price: " << price << endl;
	cout << "# Description: " << itemType << endl;
	cout << "#########################" << endl;
}

int Weapon::getPrice()
{
	return price;
}

string Weapon::getName()
{
	return itemName;
}

int Weapon::getAttack()
{
	return baseAttack;
}

string Weapon::getDescr()
{
	return itemType;
}

double Weapon::getWeight()
{
	return weight;
}

Weapon::Weapon(string n, string d, int a, int p, double w):Item(n,d),price(p),baseAttack(a),weight(w)
{}