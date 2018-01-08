//Medic.cpp
//Class functions for Medic derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include "Medic.h"

#include <iostream>

//intialize
int Medic::boosterAid = 30;
int Medic::pistolDamage = 5;


Medic::Medic()
{
}

Medic::Medic(string tempName, string tempType, string tempTeam) : Infantry(tempName, tempType, tempTeam)
{
	setBoosterShot(10);
	setPistol(10);
}

void Medic::setBoosterShot(int tempBoosterShot)
{
	boosterShot = tempBoosterShot;
}

int Medic::getBoosterShot()
{
	return boosterShot;
}

void Medic::speak()
{
	cout << endl;
	cout << Infantry::getName() << ": Prepped and ready." << endl;
}

void Medic::display()
{
	Infantry::display();
	cout << right << setw(39) << getBoosterShot();
}

void Medic::attack(Infantry* inoutbeingAttacked)
{
	int pistol = getPistol();

	if (pistol != 0 && this->getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		pistol--;
		setPistol(pistol);
		inoutbeingAttacked->getAttacked(pistolDamage);
	}
	else if (this->getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He needs help.";
	}
	else if (pistol == 0)
	{
		cout << endl;
		cout << "No more bullets.";
	}
}

void Medic::renderAid(Infantry* inoutbeingHelped)
{

	if (boosterShot != 0 && this->getHealth() != 0 && inoutbeingHelped->getHealth() != 0)
	{
		boosterShot--;
		inoutbeingHelped->receiveAid(boosterAid);
		cout << endl;
		cout << "Good and patched up!";
	}
}

void Medic::getAttacked(int damage)
{
	Infantry::getAttacked(damage);
}

void Medic::receiveAid(int healthBoost)
{
	Infantry::receiveAid(healthBoost);
}

void Medic::die()
{
	this->setHealth(0);
	boosterShot = 0;
	setPistol(0);

	cout << endl;
	cout << this->getName() << ": has died.";
}


Medic::~Medic()
{
}
