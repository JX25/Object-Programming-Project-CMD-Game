#include "Food.h"



Food::Food():Item("Bread","Prepared from a dough of flour and water"),price(10),healthRecover(20)
{
}

Food::Food(int p, int rH, string fN, string fD) : Item(fN, fD), price(p), healthRecover(rH)
{
}

Food::~Food()
{
}

int Food::eatFood()
{
	cout << "You have just eaten something!" << endl;
	return healthRecover;
}