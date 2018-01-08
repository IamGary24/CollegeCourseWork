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
#include <string>

using namespace std;

const int LIST_SIZE = 20; //constant to hold the array size

struct cityPopulation
{
	string city;
	int population2000;
	int population2010;

};

void intializeArray();
void printArray(const int list[], int listSize);
void BubbleSort(int list[], int length);
int binarySearch(const int list[], int listLength, int searchItem);

//function to add values into the array from the file
void initializeArray(cityPopulation list[], int listSize)
{
	int index; //subscript to initialize each position of the array
	ifstream fIn;
	fIn.open("pops2000-10.txt");

	for (index = 0; index < listSize; index++)
	{
		fIn >> list[index].city >> list[index].population2000 >> list[index].population2010;
	}

	fIn.close();
}


void printArray(const cityPopulation list[], int listSize)
{
	int index; //subscript to hold the value from the array and output the information

	for (index = 0; index < listSize; index++)
		cout << list[index].city << "\n" << list[index].city << "\n" << list[index].population2010;	//format the output to add a space between each value

	cout << "\n"; //input a new line character
}

void BubbleSort(int list[], int length) //the "bubble sort" where values "bubble" to their correct location 
{
	int temp;		//used to hold an array element value in a swap of two elements 
	int iteration;	//controls how many times to pass through the array
	int index;		//subscript to look at the first of a pair of adjacent element values

	for (iteration = 1; iteration < length; iteration++)
	{//make one pass through the array - iteration counts how many times
		for (index = 0; index < length - iteration; index++)
		{//compare adjacent element values
			if (list[index] > list[index + 1]) //if they're out of order
			{
				temp = list[index]; //swap to put in order
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}//otherwise leave them as they are
		}	//end of outer loop to make one pass through the array
		cout << "pass " << iteration; //output to the user...
		cout << ": ";				//...pass #; array contents

		for (index = 0; index < LIST_SIZE; index++) //loop to print out the array of the current pass
			cout << list[index] << " ";
		cout << "\n"; //print out one new line character
	}
}


int binarySearch(const int list[], int listLength, int searchItem)
{
	int first = 0; //initialize to first valid subscript
	int last = listLength - 1; //initialize to last valid subscript
							   // first and last will bracket the section of the array where searchItem may yet be found
	int mid;
	int count = 0; //int value to count how many times passes through the search function

	bool found = false; //assume searchItem is not in the list
	while (first <= last && !found)
	{
		mid = (first + last) / 2; //find the midpt of the array

		count++; //increment count for checking if mid is the item
		if (list[mid] == searchItem) //is what we're looking for
			found = true;
		else if (list[mid] > searchItem)//is what were looking for to the left of this one
		{
			count++; //increment for checking if it is the right half
			last = mid - 1; //if so ignore the right half of the array
		}
		else
		{
			count++; //increment for checking if it is the left half
			first = mid + 1; //else ignore the left half of the array
		}

	}

	if (found)
	{
		cout << "\n" << searchItem << ": # of binary comparisons: " << count; //output to the user how many times it went through the loop
		return mid; //if found return the value
	}
	else
	{
		cout << "\n" << searchItem << ": # of binary comparisons: " << count; //output to the user how many times it went through the loop
		return -1; //if not found return -1
	}
}



int main()
{
	//output to the user what the program does
	cout << "This program will read values from unsorted.txt, sort the values and then search for the values.";

	ifstream fIn; //variable for file input
	ifstream fOut; //variable for file output

	fIn.open("unsorted.txt"); //open the file
	cityPopulation list[LIST_SIZE];

	initializeArray(list, LIST_SIZE);
	printArray(list, LIST_SIZE);



	fIn.close(); //close the input file


	cout << "\n\n" << "Press Any Key To Continue..."; //prompt user to input a key to end program
	_getch(); //receive input from keyboard, any key will close the program
	return 0;
}
