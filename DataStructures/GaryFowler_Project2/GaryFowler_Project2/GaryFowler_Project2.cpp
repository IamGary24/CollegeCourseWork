// GaryFowler_Project2.cpp : Defines the entry point for the console application.
//
/*
Gary Fowler III
CSCI 270 01E
Program 2
Microsoft Visual Studio Community 2015

This program will read census data from a file, the data is regarding populations. The program will
then identify and output to the user which city has gained the most pop, which city has lost the most pop,
which city gained the least pop, and which city lost the least pop.
*/

#include "stdafx.h"
#include <fstream> //include the library to work with i/o of files
#include <iostream> //include the library to use cout and cin
#include <conio.h> //include library to use getch();
#include <string> //library to manipulate strings
#include <iomanip> //library to manipulate output (format decimals)


using namespace std;

const int LIST_SIZE = 19; //constant to hold the array size

struct cityPopulation
{
	string city = " ";
	int population2000 = 0;
	int population2010 = 0;
	double populationChange = 0;
	double percentChange = 0.00;

};

//function to add values into the array from the file
void initializeArray(cityPopulation list[], int listSize)
{
	int index; //subscript to initialize each position of the array
	ifstream fIn;
	fIn.open("pops2000-10.txt");

	for (index = 0; index < listSize; index++)
	{
		getline(fIn, list[index].city); //get the whole city and state from file 
		fIn >> list[index].population2000; //read in the population as an int
		fIn.get(); //get the '\n' character from the file
		fIn >> list[index].population2010; //read in the population as an int
		fIn.get(); //get the '\n' character from the file

		//calculate the pop change from 2010 to 2000
		list[index].populationChange = list[index].population2010 - list[index].population2000;
		//calculate the percent loss/gain
		list[index].percentChange = (list[index].populationChange / list[index].population2000) * 100;
	}

}


void printArray(const cityPopulation list[], int listSize)
{
	int index; //subscript to hold the value from the array and output the information

	cout << "The cities in descending order by percent is: \n";

	for (index = 0; index < listSize; index++)
	{
		cout << list[index].city << "\n"; // << list[index].population2000 << "\n" << list[index].population2010 << "\n";	//format the output to add a space between each value

		//check to see if population change is accurate
		//cout << list[index].populationChange << "\n";

		//check to see if percent change is accurate, showpos forces to show the sign
		cout << showpos << list[index].percentChange << "\n";
	}
	cout << "\n"; //input a new line character
}

void BubbleSort(cityPopulation list[], int listSize) //the "bubble sort" where values "bubble" to their correct location 
{
	cityPopulation temp;		//used to hold an array element value in a swap of two elements 
	int iteration;	//controls how many times to pass through the array
	int index;		//subscript to look at the first of a pair of adjacent element values

	for (iteration = 1; iteration < listSize; iteration++)
	{//make one pass through the array - iteration counts how many times
		for (index = 0; index < listSize - iteration; index++)
		{//compare adjacent element values
			if (list[index].percentChange < list[index + 1].percentChange) //if they're out of order
			{
				temp = list[index]; //swap to put in order
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}//otherwise leave them as they are
		}	//end of outer loop to make one pass through the array
	}
}

//function to search for max pop gain, max pop loss, least pop gain, least pop loss
void populationData(const cityPopulation list[], int listSize)
{
	int location;
	bool found = false;
	
	location = 0;

	//while loop, when we reach the end of the array we stop
	while (location < listSize)
		if (list[location].percentChange >= 0) // if the percent change is positive
			location++; //move to the next location
		else //if the percent change is negative
		{
			//we have found the least loss in population, therefore
			// location - 1 is the least gain in population
			cout << "The city with the least gain in population is: " << list[location - 1].city << "\n";
			cout << "The city with the least loss in population is: " << list[location].city << "\n";
			break; //break out of the loop
		}

}




int main()
{
	//output to the user what the program does
	cout << "This program will read cities and populations from pops2000-10.txt,\n";
	cout <<	"sorts the cities and populations, determines certain data based on \nthe populations, and output them.\n\n";

	ifstream fIn; //variable for file input
	ifstream fOut; //variable for file output
	
	//set the decimal point for the whole program to be .x
	cout.precision(2);

	cityPopulation list[LIST_SIZE];
	fIn.open("pops2000-10.txt");

	//call the function initializeArray
	initializeArray(list, LIST_SIZE);

	//function call to sort the array  cityPopulation list[LIST_SIZE]
	BubbleSort(list, LIST_SIZE);


	//function call to output the list of cities after sorting
	printArray(list, LIST_SIZE);


	//output to the user which city gained the most, since our array is sorted, it is in position 0
	cout << "The city which gained the most population is: " << list[0].city << "\n";

	//output to the user which city lost the most, since our array is sorted, it is in the last position
	cout << "The city which lost the most population is: " << list[LIST_SIZE - 1].city << "\n";


	//function call to output least pop gain, least pop loss
	populationData(list, LIST_SIZE);





	fIn.close(); //close the input file


	cout << "\n\n" << "Press Any Key To Continue..."; //prompt user to input a key to end program
	_getch(); //receive input from keyboard, any key will close the program
	return 0;
}
