#pragma once
#include "Character.h"
class Enemy :
	public Character
{
	int exp;
	bool defeated;
public:
	Enemy static Skeleton();
	Enemy static Zombie();
	Enemy static Ghost();
	Enemy static Vampire();
	Enemy static SkeletonDragon();
	Enemy static Lich();
	bool Enemy::ifDefeated();
	int Enemy::quickAttack();
	int Enemy::powerAttack();
	int Enemy::defend();
	int Enemy::checkStamina(int);
	int Enemy::checkHealth(int);
	//int Enemy::checkHealth(int);
	void Enemy::wait();
	bool Enemy::dogde();
	void Enemy::suffer(int);
	bool Enemy::isDefeated();
	friend ostream& operator<<(ostream &, Enemy &);
	friend class Dungeon;

	Enemy(string, int *);
	Enemy();
	~Enemy();
};

