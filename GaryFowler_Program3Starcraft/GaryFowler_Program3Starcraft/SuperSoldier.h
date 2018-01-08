//SuperSoldier.h
//Class definition for SuperSoldier derived class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef SUPERSOLDIER_HEADER
#define	SUPERSOLDIER_HEADER

#include <string>
#include "Infantry.h"
#include "Firebat.h"
#include "Ghost.h"
#include "Marine.h"
#include "Medic.h"

using namespace std;

class SuperSoldier : public Infantry, public Firebat, public Ghost, public Marine, public Medic
{
public:
	SuperSoldier();
	SuperSoldier(string, string, string);

	void setStickyGrenade(int);
	int getStickyGrenade();

	void setRocketLauncher(int);
	int getRocketLauncher();

	virtual void speak();
	virtual void display();

	virtual void attack(Infantry*);
	void renderAid(Infantry*);
	void getAttacked(int);
	void receiveAid(int);
	void die();
	~SuperSoldier();

private:
	int stickyGrenade;	//holds the amount of ammo
	static int grenadeDamage; //grenade damage
	int rocketLauncher;	//holds ammo amount
	static int launcherDamage;
	static int superAid;
};
#endif SUPERSOLDIER_HEADER