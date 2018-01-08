//Firebat.cpp
//Class functions for Firebat derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include <iostream>

//included class definition files
#include "Firebat.h"

//initialize flamethrower damage and ammo
int Firebat::ftDamage = 20; //flamethrower damage

Firebat::Firebat()
{
}

Firebat::Firebat(string tempName, string tempType, string tempTeam) : Infantry(tempName, tempType, tempTeam)
{
	setFlameThrower(10);

}

void Firebat::setFlameThrower(int tempFlameThrower)
{
	setPistol(10);
	flameThrower = tempFlameThrower;
}

int Firebat::getFlameThrower()
{
	return flameThrower;
}

void Firebat::speak()
{
	cout << endl;
	cout << Infantry::getName() << ": Need a light?" << endl;
}

void Firebat::display()
{
	Infantry::display();
	cout << right << setw(16) << getFlameThrower();
}

void Firebat::attack(Infantry* inoutbeingAttacked)
{
	
	if (flameThrower != 0 && this->getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		flameThrower--;
		setPistol(flameThrower);
		inoutbeingAttacked->getAttacked(ftDamage);
	}
	else if (this->getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He already burned up.";
	}
	else if (flameThrower == 0)
	{
		cout << endl;
		cout << "I'm all out.";
	}
}

void Firebat::renderAid(Infantry* inoutbeingHelped)
{
	cout << endl;
	cout << "Sorry dude, I only burn things!";
}

void Firebat::getAttacked(int damage)
{
	Infantry::getAttacked(damage);
}

void Firebat::receiveAid(int healthBoost)
{
	Infantry::receiveAid(healthBoost);
}

void Firebat::die()
{
	this->setHealth(0);
	flameThrower = 0;
	setPistol(0);

	cout << endl;
	cout << this->getName() << ": has died.";


}

Firebat::~Firebat()
{
}
