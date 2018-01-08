// GaryFowler_Project2.cpp : Defines the entry point for the console application.
//
/*
Gary Fowler III
CSCI 270 01E
Program 4
Microsoft Visual Studio Community 2015

This program will read input from Inventory.txt and created a linked list, then read the inventory changes file 
and apply the transactions to the items in the linked list.
*/

#include "stdafx.h"
#include <fstream> //include the library to work with i/o of files
#include <iostream> //include the library to use cout and cin
#include <conio.h> //include library to use getch();
#include <string> //library to manipulate strings
#include <iomanip> //library to manipulate output

using namespace std;

const int INVENTORY_SIZE = 10;


struct inventory		//struct for the inventory information given by the file
{
	string UPC;	//to hold the UPC
	string productDescription; //the description of the product
	double chargePrice; //to hold the charge price
	char taxStatus; //to hold the tax status (T = taxable, N = non-taxable)
	double regularPrice; //to hold the regular price
	int quantity; //to hold how many the store has
};


struct nodeType;			//struct to be used with a linked list
typedef nodeType* nodePtr;	//a typedef for a pointer to it
struct nodeType
{
	inventory info;
	nodePtr link;
};

void CreateList(nodePtr &first); //function to create the list
void PrintList(nodePtr first); //funciton to print the list
void AddItem(nodePtr &first, nodePtr current, nodePtr trailCurrent, inventory inputData); //prototype of function to add item to list
bool Search(nodePtr first, nodePtr &current, nodePtr &trailCurrent, string searchItem); // prototype of function to find a node in the list
void DeleteItem(nodePtr &first, nodePtr &current, nodePtr trailCurrent); //prototype of function to delete an item from the list
void ChangeRegularPrice(nodePtr &current, double inputData); //prototype of function to change the regular price of an item
void ChangeChargePrice(nodePtr &current, double inputData); //prototype of function to change the charge price of an item
void TakeOffSale(nodePtr &current); //prototype of function to take an item off sale
int GetString(ifstream & fn, string & s, int length); //prototype for the getstring function

int main()
{
	nodePtr first,		//points to the first item of the list
			current,	//points to the current node
			trailCurrent;	//points one node behind current
	inventory inputData; //create a new struct 
	bool found; //create a bool value for searching
	string temp; //variable to hold the remainder of the file input

	CreateList(first); //call function to create the list

	ifstream fIn;
	fIn.open("Inv-Changes.txt");
	char transactionCode; //variable to hold the transaction code

	while (fIn.peek() != EOF)
	{
		fIn >> transactionCode;		//read the transaction code

		switch (transactionCode)
		{
		case 'A': //add an item
			fIn.get(); //grab the space before upc
			GetString(fIn, inputData.UPC, 12);
			//cout << inputData.UPC;
			GetString(fIn, inputData.productDescription, 20);
			fIn >> inputData.chargePrice;
			fIn >> inputData.taxStatus;
			fIn >> inputData.regularPrice;
			fIn >> inputData.quantity;
			//getline(fIn, temp); //get the unnecessary stuff from the file input

			found = Search(first, current, trailCurrent, inputData.UPC);
			if (!found)
				AddItem(first, current, trailCurrent, inputData);
			//else
				//cout << "-1";

			//PrintList(first);
			break;
		case 'D':	//delete a discontinued item
			fIn.get(); //grab the space before upc
			GetString(fIn, inputData.UPC, 12);
			//cout << inputData.UPC;
			//getline(fIn, temp); //get the unnecessary stuff from the file input

			found = Search(first, current, trailCurrent, inputData.UPC);
			if (found)
				DeleteItem(first, current, trailCurrent);
			//else
				//cout << "-1";

			//PrintList(first);
			break;
		case 'R':			//change the regular price of an item
			fIn.get(); //grab the space before upc
			GetString(fIn, inputData.UPC, 12);
			fIn >> inputData.regularPrice;

			found = Search(first, current, trailCurrent, inputData.UPC);
			if (found)
				ChangeRegularPrice(current, inputData.regularPrice);
			//else
				//cout << "-1";

			//PrintList(first);
			break;
		case 'S':			//put an item on sale
			fIn.get(); //grab the space before upc
			GetString(fIn, inputData.UPC, 12);
			fIn >> inputData.chargePrice;

			found = Search(first, current, trailCurrent, inputData.UPC);
			if (found)
				ChangeChargePrice(current, inputData.chargePrice);
			//else
			//cout << "-1";

			//PrintList(first);
			break;
		case 'T':			//take an item off sale
			fIn.get(); //grab the space before upc
			GetString(fIn, inputData.UPC, 12);

			found = Search(first, current, trailCurrent, inputData.UPC);
			if (found)
				TakeOffSale(current);

			//PrintList(first);
			break;
		}
		getline(fIn, temp);
	}

	PrintList(first);


	cout << "\n\n" << "Press Any Key To Continue..."; //prompt user to input a key to end program
	_getch(); //receive input from keyboard, any key will close the program
	return 0;
}

void CreateList(nodePtr &first)
{
	inventory inputData;
	nodePtr newNode;
	nodePtr last = NULL;
	string temp; //to hold the return character

	first = NULL; //to test later to see if the first is pointing to a real node

	ifstream fIn; //create a input from file
	fIn.open("Inventory.txt"); //open the inventory file

	

	while (fIn.peek() != EOF)
	{
		GetString(fIn, inputData.UPC, 12);
		fIn.get(); //grab the space after upc
		GetString(fIn, inputData.productDescription, 20);
		fIn >> inputData.chargePrice;
		fIn >> inputData.taxStatus;
		fIn >> inputData.regularPrice;
		fIn >> inputData.quantity;
		getline(fIn, temp);

		newNode = new nodeType;		//create a new struct
		newNode->info = inputData;	//assign its info value
		newNode->link = NULL;		//make a new node the end of the list
		if (first == NULL)			//if this is the first node in the list
			first = newNode;		//make first point to it
		else                        //otherwise, make the last node
			last->link = newNode;	//point to this new last node
		last = newNode;				//remember where the last node is
		//PrintList(first);
		
	} 
}

void PrintList(nodePtr first)
{
	nodePtr temp = first;	//temp will traverse the list, make temp point to the first node

	if (temp == NULL)
		cout << "The list is empty\n";
	else
		cout << "The list contains:\n";

	while (temp != NULL)	//while there are still more nodes
	{
		cout << fixed << showpoint << setprecision(2);
		//output data for the node
		cout << setw(13) << temp->info.UPC
			 << setw(22) << temp->info.productDescription 
			 << setw(6) << temp->info.chargePrice
			 << setw(4) << temp->info.taxStatus 
			 << setw(6) << temp->info.regularPrice 
			 << setw(6) << temp->info.quantity << endl;
		temp = temp->link;		//and move to the next node
	}
}

void AddItem(nodePtr &first, nodePtr current, nodePtr trailCurrent, inventory inputData)
{
	nodePtr newNode;

	newNode = new nodeType;		//create a new node
	newNode->info = inputData;	//assign its info value
	newNode->link = current;	//make the new node point to the next one in order.

	if (current == first)	//if this is the first node, 
		first = newNode;	//make the first point to this node;
	else
		trailCurrent->link = newNode;	//otherwise make the previous node point to this one.
}

void DeleteItem(nodePtr &first, nodePtr &current, nodePtr trailCurrent)
{
	if (first == current)			//if the first node is to be deleted, 
		first = current->link;		//make it point to the second node
	else                            //else make the previous node point to the
		trailCurrent->link = current->link; //one after this one

	delete current;	//get rid of the current node
	current = NULL;
}
bool Search(nodePtr first, nodePtr &current, nodePtr &trailCurrent, string searchItem)
{
	current = first;		//set current point to the first node
	trailCurrent = NULL;	//will track one node behind the current

	while (current != NULL) //while there are nodes to look at
	{
		if ((current->info.UPC).compare(searchItem) == 0)		//if this is what we want, stop searching
			return true;
		
		if ((current->info.UPC).compare(searchItem) == 1)			//if this value is greate, then the one we want does not exist, stop searching
			return false;

		trailCurrent = current;		//otherwise advance to next node
		current = current->link;	
	}

	return false;		//if loop ended without returning, then the value we're searching for is not there
}

void ChangeRegularPrice(nodePtr &current, double inputData)
{
	current->info.regularPrice = inputData;
}

void ChangeChargePrice(nodePtr &current, double inputData)
{
	current->info.chargePrice = inputData;
}

void TakeOffSale(nodePtr &current)
{
	current->info.chargePrice = current->info.regularPrice;
}


int GetString(ifstream & fn, string & s, int length)
{
	int  charCount;
	char ch;

	s.erase();             // Start with an empty string

	for (charCount = 0; charCount < length; charCount++)
	{
		// Stop if there are fewer chars to be read than expected
		if (fn.peek() == '\n' || fn.peek() == EOF)
			break;
		else
		{
			ch = fn.get();   // Read next char (including blanks)
			s = s + ch;      // and append it to the string
		}
	}
	return charCount;      // Return actual count of chars read
}
