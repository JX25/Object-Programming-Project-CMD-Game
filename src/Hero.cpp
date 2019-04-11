#include "Hero.h"
#include "Error.h"

Hero::Hero()
{
	cout << "Type your hero name: ";
	while (true)
	{
		try
		{
			cin.clear();
			cin.ignore(100, '\n');
			getline(cin, name, '\n');
			if (name.length() < 2) throw Error(Error::errTooShort);
			for (int i = 0; i < name.length(); i++)
			{
				if ((name[i] == ' ' && name[i + 1] == ' ') || (name[i] == '-' && name[i + 1] == '-')) throw Error(Error::errSign);
				if (name[i] == ' ' || name[i] == '-') continue;
				if (!isalpha(static_cast<int>(name[i]))) throw Error(Error::errName);
			}
			break;
		}
		catch (Error &err)
		{
			system("cls");
			cout << err.errorWhat() << endl;
			cout << "Type your hero name again: " << endl;
		}
	}
	cout << endl;
	cout << "Name set: " << name << endl;
	cout << endl;

	cout << "Choose hero's race: (Type race name)" << endl;
	string choice;
	while (true)
	{
		try
		{

			cout << "1. Human (every lvl: +100HP +100ST)" << endl;
			cout << "2. Orc (every lvl: +150HP +50ST)" << endl;
			cout << "3. Elf (every lvl: +50HP +150ST)" << endl;
			cout << "Your choose: ";
			cin >> choice;
			if (choice[0] == '1' || choice[0] == '2' || choice[0] == '3') break;
			else throw Error(Error::errChoice);
		}
		catch (Error &err)
		{
			system("cls");
			cout << err.errorWhat() << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Choose your race again: " << endl;
		}
	}
	int choiceINT = stoi(choice);
	switch (choiceINT)
	{
	case 1:
		race = "Human";
		health = 250;
		stamina = 100;
		attack = 25;
		defence = 35;
		dexterity = 25;
		hpEveryLVL = 100;
		stEveryLVL = 100;
		experience_points = 0;
		level = 1;
		break;
	case 2:
		race = "Orc";
		health = 350;
		stamina = 80;
		attack = 45;
		defence = 25;
		dexterity = 5;
		hpEveryLVL = 150;
		stEveryLVL = 50;
		experience_points = 0;
		level = 1;
		break;
	case 3: 
		race = "Elf";
		health = 150;
		stamina = 300;
		attack = 25;
		defence = 25;
		dexterity = 45;
		hpEveryLVL = 50;
		stEveryLVL = 150;
		experience_points = 0;
		level = 1;
		break;
	default:
		break;
	}
	cout << endl;
	cout << "Race set: " << race << endl;
	cout << endl;
	maxHealth = health;
	maxStamina = stamina;
	EQ.buy(-1000);
	weapon = Weapon(0);
	armor = Armor(0);
}

void Hero::lvlEXP(int exp)
{
	experience_points += exp;
	if ((experience_points) >= (level * 100))
	{
		health = maxHealth;
		stamina = maxStamina;
		cout << "Level up!" << endl;
		int exp_left = experience_points - level * 100;
		++level;
		experience_points = exp_left;
		attack += 2;
		defence += 2;
		health += hpEveryLVL;
		maxHealth = health;
		stamina += stEveryLVL;
		maxStamina = stamina;
	}
}

void Hero::wait()
{
	checkStamina(100);
}

int Hero::checkStamina(int points)
{
	if (stamina + points > maxStamina) {
		stamina = maxStamina;
		return maxStamina;
	}
	return (stamina += points);
}

int Hero::checkHealth(int points)
{
	if (health + points > maxHealth)
	{
		health = maxHealth;
		return maxHealth;
	}
	return (health += points);
}

int Hero::quickAttack()
{
	if (stamina < 20) wait();
	else {
		int damage = attack + weapon.baseAttack*1.5;
		stamina -= 20;
		return damage;
	}
}

int Hero::powerAttack()
{
	if (stamina < 50) wait();
	else {
		int damage = attack + weapon.baseAttack*2;
		stamina -= 50;
		return damage;
	}
}

int Hero::defend()
{
	int def = defence + armor.baseDefence;
	return def;
}

void Hero::eat()
{
	health = checkHealth(EQ.useFood());
}

void Hero::heal()
{
	health = checkHealth( EQ.usePotion() );
}

bool Hero::dogde()
{
	int dogde=rand() % 100 + 1;
	if (dogde >= dexterity) return false;
	return true;
}

void Hero::suffer(int points)
{
	health -= points;
}

bool Hero::isDefeated(int health)
{
	if (health <= 0) return true;
	else return false;
}


int Hero::goldAmount()
{
	int gold=EQ.goldAmount();
	return gold;
}

void Hero::buy(int price)
{
	EQ.buy(price);
}

void Hero::changeArmor(Armor a)
{
	armor = a;
}

void Hero::changeWeapon(Weapon w)
{
	weapon=w;
}

void Hero::buyPotion(Potion p)
{
	EQ.buy(100);
	EQ.addPotion(p);
}
void Hero::buyFood(Food f)
{
	EQ.buy(25);
	EQ.addFood(f);
}

void Hero::sleepInInn()
{
	health = maxHealth;
	stamina = maxStamina;	
}

void Hero::sleepInCity()
{
	checkHealth(50);
	checkStamina(50);
}

bool Hero::maxHPandST()
{
	if (health == maxHealth && stamina == maxStamina) return true;
	else return false;
}

int Hero::potionsCounter()
{
	return (EQ.sizeOfPotionPack());
}

int Hero::foodCounter()
{
	return (EQ.sizeOfFoodPack());
}


ostream & operator<<(ostream &out, Hero &H)
{
	out << "##################################" << endl;
	out << "Name: " << H.name;
	out << ", Race: " << H.race << endl;
	out << "lvl: " << H.level << ", exp: " << H.experience_points << "/" << 100*H.level << endl;
	out << "HP: " << H.health << "/" << H.maxHealth << " ST: " << H.stamina << "/" << H.maxStamina << endl;
	out << "Armor: " << H.armor.getName() << "\nWeapon: " << H.weapon.getName() << endl;
	out << "Attack: " << H.attack <<"+"<< H.weapon.getAttack() << " Defence: " << H.defence<<"+"<<H.armor.getDefence() << endl;
	out << "Dexterity: " << H.dexterity << " Gold: "<< H.goldAmount() << endl;
	out << "Potions: "<< H.potionsCounter() <<" Food: " << H.foodCounter() << endl;
	out << "##################################" << endl;
	return out;
}

Hero::Hero(string na, string ra, int h, int s, int at, int def, int dex, int ex, int hlv, int slv, int lv, int mh, int ms, Equipment eq, Weapon we, Armor ar)
{
	name = na;
	race = ra;
	health = h;
	stamina = s;
	attack = at;
	defence = def;
	dexterity = dex;
	experience_points = ex;
	hpEveryLVL = hlv;
	stEveryLVL = slv;
	level = lv;
	maxHealth = mh;
	maxStamina = ms;
	EQ = eq;
	weapon = we;
	armor = ar;
}

Hero::Hero(Hero &H)
{
	name = H.name;
	race = H.race;
	health = H.health;
	stamina = H.stamina;
	attack = H.attack;
	defence = H.defence;
	dexterity = H.dexterity;
	experience_points = H.experience_points;
	hpEveryLVL = H.hpEveryLVL;
	stEveryLVL = H.stEveryLVL;
	level = H.level;
	maxHealth = H.maxHealth;
	maxStamina = H.maxStamina;
	EQ = H.EQ;
	weapon = H.weapon;
	armor = H.armor;
}

Hero & Hero::operator=(const Hero &H)
{
	name = H.name;
	race = H.race;
	health = H.health;
	stamina = H.stamina;
	attack = H.attack;
	defence = H.defence;
	dexterity = H.dexterity;
	experience_points = H.experience_points;
	hpEveryLVL = H.hpEveryLVL;
	stEveryLVL = H.stEveryLVL;
	level = H.level;
	maxHealth = H.maxHealth;
	maxStamina = H.maxStamina;
	EQ = H.EQ;
	weapon = H.weapon;
	armor = H.armor;
	return *this;
}

Hero::~Hero()
{
}

