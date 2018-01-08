//Infantry.cpp
//Class functions for Infantry class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include "Infantry.h"
#include <iostream>

//intialize pistol damage
int Infantry::pistolDamage = 5;

//initialize total infantry to 0
int Infantry::total_blue = 0;
int Infantry::total_red = 0;

Infantry::Infantry()
{
	setName("Unknown");
	setType("Unkown");


}

Infantry::Infantry(string tempName, string tempType, string tempTeam)
{
	setName(tempName);
	setType(tempType);
	setTeam(tempTeam);

	if (getTeam() == "Blue")
		total_blue++;
	else if (getTeam() == "Red")
		total_red++;


}

void Infantry::setName(string tempName)	//set the soldier name
{
	name = tempName;
}


string Infantry::getName()	//get the name of the soldier
{
	return name;
}

void Infantry::setHealth(int tempHealth)	//set the soldier health
{
	health = tempHealth;
}

int Infantry::getHealth()	//get the current health of the soldier
{
	return health;
}

void Infantry::setType(string tempType)	//set the soldier type
{
	type = tempType;
}

string Infantry::getType()	//get the type of the soldier
{
	return type;
}

void Infantry::setPistol(int tempPistol)	//set the ammount of ammo
{
	pistol = tempPistol;
}

int Infantry::getPistol()	//get the current ammo of the soldier
{
	return pistol;
}
void Infantry::setTeam(string iteam)
{
	team = iteam;
}


string Infantry::getTeam() const
{
	return team;
}



int Infantry::get_total_blue()
{
	return total_blue;
}


int Infantry::get_total_red()
{
	return total_red;
}

void Infantry::display()	//output Infantry's attributes (name, health, type, pistol)
{
	cout << endl;
	cout << left << setw(18) << getName()
		<< left << setw(8) << getType()
		<< right<< setw(6) << getHealth()
		<< right << setw(7) << getPistol();
}

//receives weapon damage from soldier as parameter
void Infantry::getAttacked(int damage)
{
	health = health - damage;
	if (health < 0)
	{
		die();
		health = 0;
		if (getTeam() == "Blue")
			total_blue--;
		else if (getTeam() == "Red")
			total_red--;
	}

}

void Infantry::receiveAid(int healthBoost)
{
	if (health > 0)
	{
		health = health + healthBoost;
	}
	else
		cout << endl << "That character is already dead!";
}

Infantry::~Infantry()
{
}
