#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}

int Character::quickAttack() { return -1; };
int Character::powerAttack() { return -1; };
int Character::defend() { return -1; };
void Character::wait() {};
bool Character::dogde() { return false; };
void Character::suffer() {};
bool Character::isDefeated(int = 3) { return false; };