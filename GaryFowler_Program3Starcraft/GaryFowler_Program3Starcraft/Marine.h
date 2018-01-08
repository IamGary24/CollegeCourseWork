//Marine.h
//Class definition for Marine derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef MARINE_HEADER
#define MARINE_HEADER

#include <string>
#include "Infantry.h"

using namespace std;
//one of the four subclasses of Infantry
class Marine: public Infantry
{
public:
	Marine();
	Marine(string, string, string);

	void setAssaultRifle(int);
	int getAssaultRifle();

	void speak();
	void display();

	void attack(Infantry*);
	void renderAid(Infantry*);
	void getAttacked(int);
	void receiveAid(int);
	void die();
	~Marine();
	
private:
	int assaultRifle;	//holds the amount of ammo
	static int arDamage; //holds the damage number for the Assault Rifle
	static int marineAid;	//holds the healing amount the marine does
};

#endif

