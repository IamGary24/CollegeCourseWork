// GaryFowler_Program3Starcraft.cpp
//Created by: Gary Fowler
//for Dr. McWhorter CSCI 428 Program 3

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <vector>
using std::vector;

using namespace std;

//include class definition files
#include "Firebat.h"
#include "Ghost.h"
#include "Infantry.h"
#include "Marine.h"
#include "Medic.h"
#include "SuperSoldier.h"

//function prototypes
void display_infantry(Infantry* firebat, Infantry* ghost, Infantry* marine,
	Infantry* medic, Infantry* super);



int main()
{
	//declare new infantry units for red team
	Firebat rf("Mary", "Firebat", "Red");
	Ghost rg("Frodo", "Ghost", "Red");
	Marine rmar("Pippin", "Marine", "Red");
	Medic rmed("Sam", "Medic", "Red");
	SuperSoldier rsup("Aragorn", "Super", "Red");

	//declare new infantry unites for blue team
	Firebat bf("Tychus", "Firebat", "Blue");
	Ghost bg("Nova", "Ghost", "Blue");
	Marine bmar("Jim", "Marine", "Blue");
	Medic bmed("Morales", "Medic", "Blue");
	SuperSoldier bsup("Kerrigan", "Super", "Blue");

	//declare pointers for units
	Infantry* red_firebat;
	Infantry* red_ghost;
	Infantry* red_marine;
	Infantry* red_medic;
	Infantry* red_super;

	Infantry* blue_firebat;
	Infantry* blue_ghost;
	Infantry* blue_marine;
	Infantry* blue_medic;
	Infantry* blue_super;

	//point the base class pointers at their corresponding derived class objects
	red_firebat = &rf;
	red_ghost = &rg;
	red_marine = &rmar;
	red_medic = &rmed;
	red_super = &rsup;

	blue_firebat = &bf;
	blue_ghost = &bg;
	blue_marine = &bmar;
	blue_medic = &bmed;
	blue_super = &bsup;
	
	//start of main game processes

	//set up stuff needed by game
	int turn;
	bool invalid;
	bool invalidAidOrAttack;
	int choice;
	int attackOrAid = 0;
	rg.setCloak(false);
	bg.setCloak(false);
	rsup.setCloak(false);
	bsup.setCloak(false);
	Infantry* attacking_infantry = blue_firebat;	//initialize to a value in case of error
	Infantry* infantry_attacked = blue_firebat;    //initialize to a value in case of error
	Infantry* aiding_infantry = blue_firebat;
	Infantry* infantry_aided = blue_firebat;


	turn = 0;

	display_infantry(red_firebat,red_ghost,red_marine,red_medic,red_super);
	display_infantry(blue_firebat,blue_ghost,blue_marine,blue_medic,blue_super);

	//for loop to control the turn
	for (turn = 0; turn < 40; turn++)
	{
		if (turn % 2 == 0)	//if blue team's turn
		{
			display_infantry(red_firebat, red_ghost, red_marine, red_medic, red_super);
			display_infantry(blue_firebat, blue_ghost, blue_marine, blue_medic, blue_super);

			invalid = true; //reset bad selection flag
			invalidAidOrAttack = true; //reset bad selection flag for turn choice

			cout << "Blue Team, would you like to attack or aid? (1 = attack, 2 = aid)";
			cin >> attackOrAid;

			while (invalidAidOrAttack)
			{
				invalidAidOrAttack = false;

			if (attackOrAid == 1) //if they want to attack
			{
				while (invalid)
				{
					invalid = false;


					cout << "Blue Team, Enter your attacking infantry. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
					cin >> choice;

					switch (choice)
					{
					case 1:
					{
						attacking_infantry = blue_firebat;
						break;
					}
					case 2:
					{
						attacking_infantry = blue_ghost;
						break;
					}
					case 3:
					{
						attacking_infantry = blue_marine;
						break;
					}
					case 4:
					{
						attacking_infantry = blue_medic;
						break;
					}
					case 5:
					{
						attacking_infantry = blue_super;
						break;
					}
					default:
					{
						invalid = true;
						cout << endl;
						cout << "Invalid entry.";
					}
					}//end switch for choosing who is attacking

					attacking_infantry->speak();

				}//end while for choosing who is attacking


				invalid = true; //reset bad selection flag

				while (invalid)
				{
					invalid = false;

					cout << "Blue Team, Enter your infantry to be attacked. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
					cin >> choice;

					switch (choice)
					{
					case 1:
					{
						infantry_attacked = red_firebat;
						break;
					}
					case 2:
					{
						infantry_attacked = red_ghost;
						break;
					}
					case 3:
					{
						infantry_attacked = red_marine;
						break;
					}
					case 4:
					{
						infantry_attacked = red_medic;
						break;
					}
					case 5:
					{
						infantry_attacked = red_super;
						break;
					}
					default:
					{
						invalid = true;
						cout << endl;
						cout << "Invalid entry.";
					}
					}//end switch for infantry attacked
				}//end while for choosing who to attack


				attacking_infantry->attack(infantry_attacked);
			} //end attacking if

			//begin aid
			else if (attackOrAid == 2) //the user would like to aid
			{
				while (invalid)
				{
					invalid = false;


					cout << "Blue Team, Enter your aiding infantry. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
					cin >> choice;

					switch (choice)
					{
					case 1:
					{
						aiding_infantry = blue_firebat;
						break;
					}
					case 2:
					{
						aiding_infantry = blue_ghost;
						break;
					}
					case 3:
					{
						aiding_infantry = blue_marine;
						break;
					}
					case 4:
					{
						aiding_infantry = blue_medic;
						break;
					}
					case 5:
					{
						aiding_infantry = blue_super;
						break;
					}
					default:
					{
						invalid = true;
						cout << endl;
						cout << "Invalid entry.";
					}
					}//end switch of choosing who is aiding

					aiding_infantry->speak();

				}//end while of choosing who is aiding


				invalid = true; //reset bad selection flag

				while (invalid)
				{
					invalid = false;

					cout << "Blue Team, Enter your infantry to be aided. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
					cin >> choice;

					switch (choice)
					{
					case 1:
					{
						infantry_aided = blue_firebat;
						break;
					}
					case 2:
					{
						infantry_aided = blue_ghost;
						break;
					}
					case 3:
					{
						infantry_aided = blue_marine;
						break;
					}
					case 4:
					{
						infantry_aided = blue_medic;
						break;
					}
					case 5:
					{
						infantry_aided = blue_super;
						break;
					}
					default:
					{
						invalid = true;
						cout << endl;
						cout << "Invalid entry.";
					}
					}//end switch for infantry aided
				}//end while for choosing who to aid

				aiding_infantry->renderAid(infantry_aided);

			} //end if for aiding
			else
			{
				invalidAidOrAttack = true;
				cout << endl;
				cout << "Invalid entry.";
			}
		}

			if (Infantry::get_total_red() == 0)
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                        ";
				cout << "*********************************" << endl;
				cout << "                        ";
				cout << "        BLUE TEAM WINS!!!!!      " << endl;
				cout << "                        ";
				cout << "*********************************" << endl;
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << endl << endl << endl << endl << endl;
			}
		}//end if for turn

		if (turn % 2 == 1)	//if red team's turn
		{
			display_infantry(red_firebat, red_ghost, red_marine, red_medic, red_super);
			display_infantry(blue_firebat, blue_ghost, blue_marine, blue_medic, blue_super);

			invalid = true; //reset bad selection flag
			invalidAidOrAttack = true; //reset bad selection flag for turn choice

			cout << "Red Team, would you like to attack or aid? (1 = attack, 2 = aid)";
			cin >> attackOrAid;

			while (invalidAidOrAttack)
			{
				invalidAidOrAttack = false;

				if (attackOrAid == 1) //if they want to attack
				{
					while (invalid)
					{
						invalid = false;


						cout << "Red Team, Enter your attacking infantry. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
						cin >> choice;

						switch (choice)
						{
						case 1:
						{
							attacking_infantry = red_firebat;
							break;
						}
						case 2:
						{
							attacking_infantry = red_ghost;
							break;
						}
						case 3:
						{
							attacking_infantry = red_marine;
							break;
						}
						case 4:
						{
							attacking_infantry = red_medic;
							break;
						}
						case 5:
						{
							attacking_infantry = red_super;
							break;
						}
						default:
						{
							invalid = true;
							cout << endl;
							cout << "Invalid entry.";
						}
						}//end switch for choosing who is attacking

						attacking_infantry->speak();

					}//end while for choosing who is attacking


					invalid = true; //reset bad selection flag

					while (invalid)
					{
						invalid = false;

						cout << "Red Team, Enter your infantry to be attacked. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
						cin >> choice;

						switch (choice)
						{
						case 1:
						{
							infantry_attacked = blue_firebat;
							break;
						}
						case 2:
						{
							infantry_attacked = blue_ghost;
							break;
						}
						case 3:
						{
							infantry_attacked = blue_marine;
							break;
						}
						case 4:
						{
							infantry_attacked = blue_medic;
							break;
						}
						case 5:
						{
							infantry_attacked = blue_super;
							break;
						}
						default:
						{
							invalid = true;
							cout << endl;
							cout << "Invalid entry.";
						}
						}//end switch for infantry attacked
					}//end while for choosing who to attack


					attacking_infantry->attack(infantry_attacked);
				} //end attacking if

				  //begin aid
				else if (attackOrAid == 2) //the user would like to aid
				{
					while (invalid)
					{
						invalid = false;


						cout << "Red Team, Enter your aiding infantry. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
						cin >> choice;

						switch (choice)
						{
						case 1:
						{
							aiding_infantry = red_firebat;
							break;
						}
						case 2:
						{
							aiding_infantry = red_ghost;
							break;
						}
						case 3:
						{
							aiding_infantry = red_marine;
							break;
						}
						case 4:
						{
							aiding_infantry = red_medic;
							break;
						}
						case 5:
						{
							aiding_infantry = red_super;
							break;
						}
						default:
						{
							invalid = true;
							cout << endl;
							cout << "Invalid entry.";
						}
						}//end switch of choosing who is aiding

						aiding_infantry->speak();

					}//end while of choosing who is aiding


					invalid = true; //reset bad selection flag

					while (invalid)
					{
						invalid = false;

						cout << "Red Team, Enter your infantry to be aided. (1 = Firebat, 2 = Ghost, 3 = Marine, 4 = Medic, 5 = Super): ";
						cin >> choice;

						switch (choice)
						{
						case 1:
						{
							infantry_aided = red_firebat;
							break;
						}
						case 2:
						{
							infantry_aided = red_ghost;
							break;
						}
						case 3:
						{
							infantry_aided = red_marine;
							break;
						}
						case 4:
						{
							infantry_aided = red_medic;
							break;
						}
						case 5:
						{
							infantry_aided = red_super;
							break;
						}
						default:
						{
							invalid = true;
							cout << endl;
							cout << "Invalid entry.";
						}
						}//end switch for infantry aided
					}//end while for choosing who to aid

					aiding_infantry->renderAid(infantry_aided);

				} //end if for aiding
				else
				{
					invalidAidOrAttack = true;
					cout << endl;
					cout << "Invalid entry.";
				}
			}//end while for turn

			if (Infantry::get_total_red() == 0)
			{
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "                        ";
				cout << "*********************************" << endl;
				cout << "                        ";
				cout << "         RED TEAM WINS!!!!!      " << endl;
				cout << "                        ";
				cout << "*********************************" << endl;
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << endl << endl << endl << endl << endl;
			}
		}//end if for turn
	}//end loop for game
	

	/*
	//display infantry units
	f1.display();
	g1.display();
	mar1.display();
	med1.display();

	ss1.display();

	//have each infantry unit attack each other
	f1.attack(&g1);
	g1.display();
	g1.attack(&mar1);
	mar1.display();
	mar1.attack(&med1);
	med1.display();
	med1.attack(&f1);
	f1.display();

	ss1.attack(&med1);
	med1.display();
	ss1.display();

	//have each infantry unit aid each other
	med1.renderAid(&mar1);
	mar1.display();
	mar1.renderAid(&g1);
	g1.display();
	g1.renderAid(&f1);
	f1.display();
	f1.renderAid(&med1);
	med1.display();

	ss1.renderAid(&g1);
	g1.display();
	ss1.display();

	//cloak and attack the ghost
	g1.setCloak(true);
	f1.attack(&g1);
	g1.display();
	f1.display();

	//kill each unit
	f1.die();
	g1.die();
	mar1.die();
	med1.die();

	ss1.die();

	//display each unit to test death algorithm
	f1.display();
	g1.display();
	mar1.display();
	med1.display();

	ss1.display();
	
	//try to attack with one
	f1.attack(&g1);
	f1.display();
	g1.display();
	*/



	cout << endl << "Press any key to continue...";
	_getch();
    return 0;
}

void display_infantry(Infantry* firebat, Infantry* ghost, Infantry* marine,
	Infantry* medic, Infantry* super)
{
	cout << endl;
	cout << left
		<< setw(18) << "Name"
		<< setw(8) << "Type"
		<< setw(8) << "Health"
		<< setw(8) << "Pistol"
		<< setw(8) << "ARifle"
		<< setw(8) << "FThrow"
		<< setw(8) << "SRifle"
		<< setw(7) << "Cloak"
		<< setw(7) << "BShot"
		<< endl;

	cout << "------------------------------------------------------------------------------" << endl;

	firebat->display();
	ghost->display();
	marine->display();
	medic->display();
	super->display();

	cout << endl;

	if (firebat->getTeam() == "Blue")
		cout << "Total Blue Infantry Remaining: " << Infantry::get_total_blue() << endl << endl;
	else if (firebat->getTeam() == "Red")
		cout << "Total Red Infantry Remaining: " << Infantry::get_total_red() << endl << endl;

}

