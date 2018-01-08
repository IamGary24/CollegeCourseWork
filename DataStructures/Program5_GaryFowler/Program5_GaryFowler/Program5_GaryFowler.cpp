// GaryFowler_Project2.cpp : Defines the entry point for the console application.
//
/*
Gary Fowler III
CSCI 270 01E
Program 5
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
#include <stack>	//standard template library stack class
#include <cctype>	//library to manipulate char variables
#include <queue> //standard template library queue class

using namespace std;




int main()
{
	stack <char>stack;	//create an empty stack named stack
	queue <char>queue;	//create an empty queue named queue
	ifstream fIn; //create a input from file
	fIn.open("pal.txt"); //open the inventory file

	string fileString = "";	//create a variable to hold the string
	string reverseString = ""; //create a variable to hold a reverse of the string
	string realInput = ""; //create a variable to hold the real input

	while (fIn.peek() != EOF) //add the line of the file to the stack and queue
	{
		char temp;	//create variable to temporarily hold the file input	
		fIn >> temp;		//read the entire line of the file and put into variable temp
		realInput = realInput + temp; //take the actual input from the file

		if (isalpha(temp))
		{
			stack.push(temp);	//push variable temp into the stack
			queue.push(temp);	//push variable temp into the queue	

			fileString = fileString + static_cast<char>(tolower(temp)); // add each character to create the string
		}

		if (fIn.peek() == '\n')
		{
			//cout << fileString << endl;
			cout << realInput;

			while (!stack.empty()) //if the stack is empty, stop the loop
			{
				reverseString = reverseString + static_cast<char>(tolower(stack.top())); //look at the top of the stack and add to reversestring
				stack.pop();	//remove the top item of the stack
			}
			//cout << reverseString << endl;

			if (fileString == reverseString)
				cout << " is a palindrome." << endl;	// the string is a palindrome 
			else
				cout << " is not a palindrome." << endl;

			fileString.clear();	//cleare the filestring
			reverseString.clear(); //clear the reverse string
			realInput.clear(); //clear the real input
			
		}

	}




	cout << "\n\n" << "Press Any Key To Continue..."; //prompt user to input a key to end program
	_getch(); //receive input from keyboard, any key will close the program
    return 0;
}

