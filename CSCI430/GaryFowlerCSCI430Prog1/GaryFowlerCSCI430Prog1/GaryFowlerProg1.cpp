/**
* @author Gary Fowler
* @cwid 501 60 960
* @class CSci 430, Summer 2017
* @ide Visual Studio Community 2015
* @date June 11, 2017
* @assg Programming Assignment #0
*
* @descrption Implement a basic queue data structure.
*/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

list<int> queue;

/** Initialize queue
* Create a global queue data structure.  Perform any necessary
* initialization to create an initially empty but working queue.
*/
void initQueue()
{
  // Perform any necessary initialization for the queue data
  // structure you create here.  You should simply use global
  // variable(s) for any queue items and data you need to manipulate
  // in the enqueue()/dequeue() functions.
}


/** Display queue
* Display all of the values currently in the queue.
*/
void displayQueue()
{
  cout << "Head: ";

  for (list<int>::const_iterator iterator = queue.begin(), end = queue.end(); iterator != end; iterator++)
  {
    cout << *iterator << " ";
  }

  cout << ":Tail" << endl;
}


/** enqueue
* Add item to the end of the queue.
*
* @param item An integer value, the value we are to enqueue
*/
void enqueue(int item)
{
  // Add the indicated integer value to the end of your queue here
  queue.push_back(item);
}


/** dequeue
* Remove head item from queue and return it.  This function
* should print an error message and exit if a dequeue()
* operation is performed on an empty queue.
*
* @returns int The item that was removed from head of queue.
*/
int dequeue()
{
  int frontNumber;

  if (queue.front() == NULL)
  {
    cout << "Error: dequeue from empty queue" << endl;
    exit(1);
  }
  else
  {
    frontNumber = queue.front();  //access the first element
    queue.pop_front();  //pop the first element
  }

  return frontNumber; // should be returning the item you dequeue here as last step
}


/** The queue tester.
* The main loop for running tests of the queue data type.
* The file contains commands to enqueue and deque items
* from the queue.
*
* @param testfilename The name of the file (e.g. testfile.tst) to open
*     and read commands to test the queue data type from.
*/
void runTests(char* testfilename)
{
  ifstream testfile(testfilename);
  string command;
  int item;

  cout << "Processing queue test file: " << testfilename << endl;
  if (!testfile.is_open())
  {
    cout << "Error: could not open queue test file: " << testfilename << endl;
    exit(1);
  }

  initQueue();

  while (!testfile.eof())
  {
    testfile >> command;

    if (command == "enqueue")
    {
      testfile >> item;
      cout << "Enqueuing item: " << item << endl;
      enqueue(item);
    }
    else if (command == "dequeue")
    {
      item = dequeue();
      cout << "Dequeued item: " << item << endl;
    }
    else
    {
      cout << "ERROR: unknown command: " << command << endl;
      exit(1);
    }

    displayQueue();
  }
}


/** Main entry point of simulator
*  The main entry point of the process simulator.  We simply set up
*  and initialize the environment, then call the appropriate function
*  to begin the simulation.  We expect a single command line argument
*  which is the name of the simulation event file to process.
*
* @param argc The argument count
* @param argv The command line argument values. We expect argv[1] to be the
*              name of a file in the current directory holding process events
*              to simulate.
*
* @returns int Returns 0 to OS to indicate successful completion, or non zero
*              value to indicate an error.
*/
int main(int argc, char** argv)
{
  //cout << "Number of commands: " << argc << endl;
  //cout << "argv[0] " << argv[0] << endl;
  //cout << "argv[1] " << argv[1] << endl;
  //cout << "argv[2] " << argv[2] << endl;
  //cout << "argv[3] " << argv[3] << endl;
  //cout << "argv[4] " << argv[4] << endl;
  //exit(1);

  // validate command line arguments
  if (argc != 2)
  {
    cout << "Error: expecting test file as first command line parameter" << endl;
    cout << "Usage: " << argv[0] << " testfile.tst" << endl;
    exit(1);
  }

  // Invoke the function to actually run the simulation
  runTests(argv[1]);
  //runTests("testfile1.tst");

  // return status 0 to indicate successful program completion
  return 0;
}