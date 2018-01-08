//Marine.cpp
//Class functions for Marine derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include "Marine.h"

#include <iostream>

//initialize AR damage
int Marine::arDamage = 10;
int Marine::marineAid = 10;


Marine::Marine()
{
}

Marine::Marine(string tempName, string tempType, string tempTeam) : Infantry(tempName, tempType, tempTeam)
{
	setAssaultRifle(10);
}

void Marine::setAssaultRifle(int tempAssaultRifle)
{
	setPistol(10);
	assaultRifle = tempAssaultRifle;
}

int Marine::getAssaultRifle()
{
	return assaultRifle;
}

void Marine::speak()
{
	cout << endl;
	cout << Infantry::getName() << ": You wanna piece of me, boy?" << endl;
}

void Marine::display()
{
	Infantry::display();
	cout << right << setw(8) << getAssaultRifle();
}

void Marine::attack(Infantry* inoutbeingAttacked)
{

	if (assaultRifle != 0 && this->getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		assaultRifle--;
		setPistol(assaultRifle);
		inoutbeingAttacked->getAttacked(arDamage);
	}
	else if (this->getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He ain't breathing.";
	}
	else if (assaultRifle == 0)
	{
		cout << endl;
		cout << "Can't do that, boy.";
	}
}

void Marine::renderAid(Infantry* inoutbeingHelped)
{
	if (this->getHealth() != 0 && inoutbeingHelped->getHealth() != 0)
	{
		if (inoutbeingHelped->getHealth() > 75)
		{
			cout << endl;
			cout << "You ain't hurt boy! Get up and fight!";
		}
		else if (inoutbeingHelped->getHealth() > 25)
		{
			cout << endl;
			cout << "Let me patch you up boy.";
			inoutbeingHelped->receiveAid(marineAid);
		}
		else if (inoutbeingHelped->getHealth() < 25)
		{
			cout << endl;
			cout << "Sorry boy... You ain't gonna make it.";

			//give the soldier 50% of dying
			int x;
			x = (rand() % 10);
			if (x <= 5)
			{
				inoutbeingHelped->die();
			}
		}
	}
}

void Marine::getAttacked(int damage)
{
	Infantry::getAttacked(damage);
}

void Marine::receiveAid(int healthBoost)
{
	Infantry::receiveAid(healthBoost);
}

void Marine::die()
{
	this->setHealth(0);
	assaultRifle = 0;
	setPistol(0);

	cout << endl;
	cout << this->getName() << ": has died.";
}


Marine::~Marine()
{
}
