//Ghost.h
//Class definition for Ghost derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef GHOST_HEADER
#define GHOST_HEADER

#include <string>
#include "Infantry.h"

using namespace std;
//one of the 4 subclasses of infantry
class Ghost: public Infantry
{
public:
	Ghost();
	Ghost(string, string, string);

	void setSniperRifle(int);
	void setCloak(bool);	//ghost can cloak, while cloaked does not take damage
	int getSniperRifle();
	bool getCloak();

	void speak();
	void display();

	virtual void attack(Infantry*);
	void renderAid(Infantry*);
	void getAttacked(int);
	void receiveAid(int);
	void die();
	~Ghost();

private:
	int sniperRifle;	//holds the sniper ammo
	bool cloak;	//determines if the ghost is cloaked or not
	static int snipeDamage;	//sniper damage
	static int snipeAid;
};
#endif

