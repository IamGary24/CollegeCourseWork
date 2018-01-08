#pragma once
//This class will add ways to receive monetary values from a client and do a number of calculations on that value.
//It also holds a default value of 0 for monetary values.
#include <iostream>
#include "stdafx.h"
#include <iomanip>
#include <string>
using namespace std;

class Program3
{
public:
	void defaultMoney(); //set default values for the monetary values.
	void setMoney(); //function to set monetary values as user defined, or default to 0.
	void inputMoney(int d, int c); //function to input a monetary value.
	void outputMoney(int d, int c); //funciton to output a monetary value.
	int dollarValue(int d); //function to output the dollar value from outputMoney and inputMoney
	int centsValue(int c); //function to output the cents value from outputMoney and inputMoney
	int moneySum(int d, int c); //function that returns a sum of two monetary amounts.
	int moneyDifference(int d, int c); //function that returns a difference of two monetary amounts.
	int moneyProduct(int d, int c); //function that returns a product of a monetary value and integer amount.
	//functions that compare two monetary values and return the result as a boolean
	int lessThan(); 
	int equalTo();
	int greaterThan();

private:
	int dollar; //variable to hold the dollar amount
	int cents; //variable to hold the cents amount

~Program3();
};

//definitions of the member functions

//default money values
void Program3::defaultMoney()
{
	dollar = 0;
	cents = 0;
}

//function to receive user input or default to 0 for monetary values
void Program3::setMoney()
{
	double amount; //variable to hold the floating pt from user
	int d; //placeholder for dollar
	int c; //placeholder for cents

	cin >> amount; //receive input from user

	d = amount; //set d to the amount entered but as an int to drop off the decimal.

	c = (amount - d) * 100; //set c to the amount on the right side of the decimal.


	if (d >= 0) //make sure non-negative
		dollar = d; //set dollar = to user defined amount

	if (c >= 0) //make sure non-negative
		cents = c; //set cents = to user defined amount

}
