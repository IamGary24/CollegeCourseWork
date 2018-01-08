//Ghost.cpp
//Class functions for Ghost derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include <iostream>
#include "Ghost.h"

using namespace std;

int Ghost::snipeDamage = 30;
int Ghost::snipeAid = 5;

Ghost::Ghost()
{
}

Ghost::Ghost(string tempName, string tempType, string tempTeam) : Infantry(tempName, tempType, tempTeam)
{
	setSniperRifle(10);


}

void Ghost::setSniperRifle(int tempSniperRifle)
{
	setPistol(10);
	sniperRifle = tempSniperRifle;
}

int Ghost::getSniperRifle()
{
	return sniperRifle;
}

void Ghost::setCloak(bool tempCloak)
{
	cloak = tempCloak;
}

bool Ghost::getCloak()
{
	return cloak;
}

void Ghost::speak()
{
	cout << endl;
	cout << Infantry::getName() << ": Somebody call for an exterminator?" << endl;
}

void Ghost::display()
{
	Infantry::display();
	bool cloak;
	string cloakon;
	if (getCloak())
	{
		cloakon = "on";
	}
	else
	{
		cloakon = "off";
	}
	cout << right << setw(24) << getSniperRifle() << setw(8) << cloakon;
}

void Ghost::attack(Infantry* inoutbeingAttacked)
{
	

	if (sniperRifle != 0 && this->getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		sniperRifle--;
		setPistol(sniperRifle);
		inoutbeingAttacked->getAttacked(snipeDamage);
	}
	else if (this->getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He has been exterminated already.";
	}
	else if (sniperRifle == 0)
	{
		cout << endl;
		cout << "I have done all I can do.";
	}
}

void Ghost::renderAid(Infantry* inoutbeingHelped)
{

	if (this->getHealth() != 0 && inoutbeingHelped->getHealth() != 0)
	{
		inoutbeingHelped->receiveAid(snipeAid);
		cout << endl;
		cout << "You don't see me... I was never here.";
	}
}

void Ghost::getAttacked(int damage)
{
	if (!cloak)
	{
		Infantry::getAttacked(damage);
	}
	else
	{
		cout << endl;
		cout << "Missed me, wish you could see me?";
	}
}

void Ghost::receiveAid(int healthBoost)
{
	Infantry::receiveAid(healthBoost);
}

void Ghost::die()
{
	this->setHealth(0);
	sniperRifle = 0;
	setPistol(0);

	cout << endl;
	cout << this->getName() << ": has died.";
}

Ghost::~Ghost()
{
}
