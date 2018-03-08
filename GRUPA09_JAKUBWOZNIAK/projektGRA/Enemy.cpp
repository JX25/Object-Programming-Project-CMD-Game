#include "Enemy.h"



Enemy::Enemy(string n,int *tab)
{
	name = n;
	race = "undead";
	health	= tab[0];
	stamina = tab[1];
	attack	= tab[2];
	defence = tab[3];
	dexterity= tab[4];
	exp		= tab[5];
	defeated = false;
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

Enemy Enemy::Skeleton()
{
	int stats[6];
	stats[0] = 80;
	stats[1] = (rand()%4+1)*60;
	stats[2] = (rand()%10+1)*2;
	stats[3] = 20;
	stats[4] = 10;
	stats[5] = 20;
	Enemy *en = new Enemy("Skeleton",stats);
	return (*en);
}

Enemy Enemy::Zombie()
{
	int stats[6];
	stats[0] = 160;
	stats[1] = (rand() % 4 + 1) * 20;
	stats[2] = (rand() % 5 + 1) * 5;
	stats[3] = 45;
	stats[4] = 1;
	stats[5] = 40;
	Enemy *en = new Enemy("Zombie", stats);
	return (*en);
}

Enemy Enemy::Ghost()
{
	int stats[6];
	stats[0] = 120;
	stats[1] = (rand() % 4 + 1) * 100;
	stats[2] = (rand() % 6 + 1) * 7;
	stats[3] = 15;
	stats[4] = 50;
	stats[5] = 80;
	Enemy *en = new Enemy("Ghost", stats);
	return (*en);
}

Enemy Enemy::Vampire()
{
	int stats[6];
	stats[0] = 280;
	stats[1] = (rand() % 2 + 1) * 150;
	stats[2] = (rand() % 40 + 20) * 3;
	stats[3] = 80;
	stats[4] = 30;
	stats[5] = 160;
	Enemy *en = new Enemy("Vampire", stats);
	return (*en);
}

Enemy Enemy::SkeletonDragon()
{
	int stats[6];
	stats[0] = 900;
	stats[1] = (rand() % 3 + 1) * 200;
	stats[2] = (rand() % 5 + 6) * 30;
	stats[3] = 120;
	stats[4] = 5;
	stats[5] = 300;
	Enemy *en = new Enemy("Skeleton Dragon", stats);
	return (*en);
}

Enemy Enemy::Lich()
{
	int stats[6];
	stats[0] = 1100;
	stats[1] = (rand() % 4 + 1) * 75;
	stats[2] = (rand() % 30 + 1) * 15;
	stats[3] = 100;
	stats[4] = 15;
	stats[5] = 400;
	Enemy *en = new Enemy("Lich", stats);
	return (*en);
}

int Enemy::quickAttack()
{
	if (stamina < 20)
	{
		wait();
		return 0;
	}
	else
	{
		int damage = attack;
		stamina -= 20;
		return damage;
	}
}
int Enemy::powerAttack()
{
	if (stamina < 50)
	{
		wait();
		return 0;
	}
	else
	{
		int damage = attack*2;
		stamina -= 50;
		return damage;
	}
};
int Enemy::defend()
{
	int def = defence *1.5;
	return def;
}
void Enemy::wait()
{
	stamina += 50;
}
bool Enemy::dogde()
{
	int dogde = rand() % 100 + 1;
	if (dogde >= dexterity) return false;
	return true;
}
void Enemy::suffer(int points)
{
	health -= points;
}
bool Enemy::isDefeated()
{
	if (health <= 0) return true;
	else return false;
}

bool Enemy::ifDefeated()
{
	return defeated;
}

int Enemy::checkStamina(int points)
{
	return (stamina += points);
}

int Enemy::checkHealth(int points)
{
	return (health += points);
}

ostream& operator<<(ostream &out, Enemy &H)
{
	out << "##################################" << endl;
	out << "Name: " << H.name;
	out << ", Race: " << H.race << endl;
	out << "HP: " << H.health  << " ST: " << H.stamina  << endl;
	out << "Attack: " << H.attack  << " Defence: " << H.defence << endl;
	out << "Dexterity: " << H.dexterity << endl;
	out << "##################################" << endl;
	return out;
}