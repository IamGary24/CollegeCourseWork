//SuperSoldier.cpp
//Class functions for Supersoldier derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include <iostream>

//included class definition files
#include "SuperSoldier.h"

//initialize flamethrower damage and ammo
int SuperSoldier::grenadeDamage = 40; //grenade damage
int SuperSoldier::launcherDamage = 30; //launcher damage
int SuperSoldier::superAid = 20;

SuperSoldier::SuperSoldier()
{
}

SuperSoldier::SuperSoldier(string tempName, string tempType, string tempTeam) : Infantry(tempName, tempType, tempTeam),
Firebat(tempName, tempType, tempTeam), Ghost(tempName, tempType, tempTeam), Marine(tempName, tempType, tempTeam), Medic(tempName, tempType, tempTeam)
{
	setStickyGrenade(10);
	setRocketLauncher(10);


}

void SuperSoldier::setStickyGrenade(int tempStickyGrenade)
{
	stickyGrenade = 5;
}

int SuperSoldier::getStickyGrenade()
{
	return stickyGrenade;
}

void SuperSoldier::setRocketLauncher(int tempRocketLauncher)
{
	Infantry::setPistol(tempRocketLauncher);
	rocketLauncher = Infantry::getPistol();
}

int SuperSoldier::getRocketLauncher()
{
	return rocketLauncher;
}

void SuperSoldier::speak()
{
	cout << endl;
	cout << Infantry::getName() << ": I am ready" << endl;
}

void SuperSoldier::display()
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
	cout << right << setw(8) << getAssaultRifle()
		<< setw(8) << getFlameThrower()
		<< setw(8) << getSniperRifle()
		<< setw(8) << cloakon
		<< setw(7) << getBoosterShot();
}

void SuperSoldier::attack(Infantry* inoutbeingAttacked)
{
	//attack first with grenade
	if (stickyGrenade != 0 && this->Infantry::getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		stickyGrenade--;
		inoutbeingAttacked->getAttacked(grenadeDamage);
	}
	else if (this->Infantry::getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He has been vanguished.";
	}
	else if (stickyGrenade == 0)
	{
		cout << endl;
		cout << "It cannot be done, I have no more grenades.";
	}
	//attack second with rocket launcher
	if (rocketLauncher != 0 && this->Infantry::getHealth() != 0 && inoutbeingAttacked->getHealth() != 0)
	{
		rocketLauncher--;
		Infantry::setPistol(rocketLauncher);
		inoutbeingAttacked->getAttacked(launcherDamage);
	}
	else if (this->Infantry::getHealth() <= 0)
	{
		cout << endl;
		cout << Infantry::getName() << " is dead.";
	}
	else if (inoutbeingAttacked->getHealth() <= 0)
	{
		cout << endl;
		cout << "He has been vanguished.";
	}
	else if (stickyGrenade == 0)
	{
		cout << endl;
		cout << "It cannot be done, I have no more rockets.";
	}
}

void SuperSoldier::renderAid(Infantry* inoutbeingHelped)
{
	if (this->Infantry::getHealth() != 0 && inoutbeingHelped->getHealth() != 0)
	{
		if (inoutbeingHelped->getHealth() > 50)
		{
			cout << endl;
			cout << "I will not, they should fight";
		}
		else if (inoutbeingHelped->getHealth() <= 50)
		{
			cout << endl;
			cout << "Let me aid him.";
			inoutbeingHelped->receiveAid(superAid);
		}
	}

}

void SuperSoldier::getAttacked(int damage)
{
	Infantry::getAttacked(damage);
}

void SuperSoldier::receiveAid(int healthBoost)
{
	Infantry::receiveAid(healthBoost);
}

void SuperSoldier::die()
{
	this->Infantry::setHealth(0);
	stickyGrenade = 0;
	rocketLauncher = 0;
	Infantry::setPistol(0);

	cout << endl;
	cout << this->Infantry::getName() << ": has died.";


}

SuperSoldier::~SuperSoldier()
{
}
