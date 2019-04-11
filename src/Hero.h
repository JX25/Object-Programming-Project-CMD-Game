#pragma once
#include "Character.h"
#include "Equipment.h"
#include "Weapon.h"
#include "Armor.h"
#include "Enemy.h"
class Hero :
	public Character
{
protected:
	int experience_points;
	int hpEveryLVL;
	int stEveryLVL;
	int level;
	Equipment EQ;
	int maxHealth;
	int maxStamina;
	Weapon weapon;
	Armor armor;
public:
	void lvlEXP(int);
	int quickAttack();
	int powerAttack();
	int defend();
	int checkStamina(int);
	int checkHealth(int);
	void wait();
	bool dogde();
	void suffer(int);
	bool isDefeated(int);
	void eat();
	void heal();
	void buy(int);
	int goldAmount();
	void changeArmor(Armor);
	void changeWeapon(Weapon);
	void buyPotion(Potion);
	void buyFood(Food);
	void sleepInInn();
	void sleepInCity();
	bool maxHPandST();
	int potionsCounter();
	int foodCounter();
	friend class Dungeon;
	friend class Town;
	friend ostream& operator<<(ostream &, Hero &);
	Hero & operator=(const Hero &);
	explicit Hero();
	Hero(Hero&);
	Hero(string,string,int,int,int,int,int,int,int,int,int,int,int,Equipment,Weapon,Armor);
	~Hero();

};

