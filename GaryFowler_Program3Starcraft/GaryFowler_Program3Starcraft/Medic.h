//Medic.h
//Class definition for Medic derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef MEDIC_HEADER
#define MEDIC_HEADER

#include <string>
#include "Infantry.h"


using namespace std;
//one of the 4 subclasses of infantry
class Medic: public Infantry
{
public:
	Medic();
	Medic(string, string, string);
	void setBoosterShot(int);
	int getBoosterShot();
	void speak();
	void display();
	void attack(Infantry*);
	void renderAid(Infantry*);
	void getAttacked(int);
	void receiveAid(int);
	void die();
	~Medic();

private:
	int boosterShot;	//holds the amount of ammo
	static int boosterAid;	//holds the amount the booster shot heals
	static int pistolDamage;
};
#endif

