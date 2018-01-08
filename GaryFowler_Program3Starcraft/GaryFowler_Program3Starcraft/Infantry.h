//Infantry.h
//Class definition for Infantry base class
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#ifndef INFANTRY_HEADER
#define INFANTRY_HEADER

#include <string>
#include <iomanip>
using namespace std;

//superclass with 4 subclasses (marine, firebat, medic, ghost)
class Infantry
{
public:
	Infantry();
	Infantry(string, string, string);

	void setName(string);	//set the soldier name
	string getName();	//get the name of the soldier

	void setHealth(int);	//set the soldier health
	int getHealth();	//get the current health of the soldier

	void setType(string);	//set the soldier type
	string getType();	//get the type of the soldier

	void setTeam(string);
	string getTeam() const;

	static int get_total_red();
	static int get_total_blue();

	void setPistol(int);	//set the ammount of ammo
	int getPistol();	//get the current ammo of the soldier

	virtual void display();	//output Infantry's attributes (name, health, type, pistol)
	virtual void speak()=0;	//abstract method implemented by subclasses
	virtual void attack(Infantry*)=0;	//abstract method implemented by subclasses
	virtual void renderAid(Infantry*)=0;	//abstract method
	virtual void getAttacked(int);	//abstract method
	virtual void receiveAid(int);	//abstract method
	virtual void die()=0;
	~Infantry();

private:
	string name;	//soldier's name
	int health = 100;	//soldier's health
	int pistol;	//amount of ammo
	string type;	//soldier type
	static int pistolDamage; //damage pistol does by default
	string team;

	static int total_red;
	static int total_blue;
};
#endif

