//AutomobileClass.h
/*Author: Gary Fowler
for CSCI 428 Dr. Will McWhorter
*/

/*This class will be used to store information about possible vehicle choices for someone
buying a new car.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class AutomobileClass
{
public:
	//Constructor for the automobile class
	AutomobileClass(string make, string model)
	{
		setModel(model);
		setMake(make);
	}

	//setters
	void setModel(string model)
	{
		vehicleModel = model;
	}

	void setMake(string make)
	{
		vehicleMake = make;
	}

	//getters
	string getModel()
	{
		return vehicleModel;
	}

	string getMake()
	{
		return vehicleMake;
	}

	//display message to the user
	void displayCars()
	{
		cout << "A possible vehicle choice is: " << getMake() << " " << getModel() << "." << endl;
	
	}

	void outputFile()
	{

		ofstream fout;
		fout.open("VehicleOutput.txt", fout.app);
		fout << "A possible choice is: " << getMake() << " " << getModel() << "." << endl;
		cout << getMake() << getModel() << endl;
	}
private:
	string vehicleModel;
	string vehicleMake;
};
