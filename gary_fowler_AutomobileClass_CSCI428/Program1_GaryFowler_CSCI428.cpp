// Program1_GaryFowler_CSCI428.cpp : Defines the entry point for the console application.
/*
Author: Gary Fowler
for CSCI 428 Dr. Will McWhorter
*/

/*This is the test program for the AutomobileClass
*/

#include "stdafx.h"
#include <iostream>
#include "AutomobileClass.h"
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	//create three AutomobileClass objects
	string make = "make"; //placeholder variable for make
	string model = "model"; //placeholder variable for model

	AutomobileClass automobileOptionOne(make, model);
	AutomobileClass automobileOptionTwo(make, model);
	AutomobileClass automobileOptionThree(make, model);

	//open input file
	ifstream fin;
	fin.open("VehicleInput.txt");

	int counter = 1; //to hold the number of iterations for the loop
	while (fin.peek() != EOF)
	{
		string vehicleMake = " ";
		string vehicleModel = " ";

		getline(fin, vehicleMake);//read in the vehicle make
		getline(fin, vehicleModel);	//read in the vehicle model

		switch (counter)
		{
		case 1:
			automobileOptionOne.setMake(vehicleMake);
			automobileOptionOne.setModel(vehicleModel);
			break;
		case 2:
			automobileOptionTwo.setMake(vehicleMake);
			automobileOptionTwo.setModel(vehicleModel);
			break;
		case 3:
			automobileOptionThree.setMake(vehicleMake);
			automobileOptionThree.setModel(vehicleModel);
			break;
		}

		counter++;

	}

	fin.close(); //close input file


	automobileOptionOne.displayCars();
	automobileOptionTwo.displayCars();
	automobileOptionThree.displayCars();

	automobileOptionOne.outputFile();
	automobileOptionTwo.outputFile();
	automobileOptionThree.outputFile();

	cout << "\n\n" << "Press Any Key To Continue..."; //prompt user to input a key to end program
	_getch(); //receive input from keyboard, any key will close the program
	return 0;


	
}