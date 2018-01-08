//Firebat.h
//Class definition for Firebat derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef FIREBAT_HEADER
#define	FIREBAT_HEADER

#include <string>
#include "Infantry.h"

using namespace std;

class Firebat: public Infantry
{
public:
	Firebat();
	Firebat(string, string, string);

	void setFlameThrower(int);
	int getFlameThrower();

	void speak();
	void display();

	virtual void attack(Infantry*);
	void renderAid(Infantry*);
	void getAttacked(int);
	void receiveAid(int);
	void die();
	~Firebat();

private:
	int flameThrower;	//holds the amount of ammo
	static int ftDamage; //flamethrower damage
};
#endif FIREBAT_HEADER

