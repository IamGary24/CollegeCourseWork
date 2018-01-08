/** @file  Source.cpp
*
* @author Gary Fowler III
* @assg   Programming Assignment #4
* @date   July 2, 2017
*/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


// guarantee simulations have no more than this number of page references
// and we guarantee that you don't need to simulate a memory of more
// than this number of physical pages
const int MAX_PAGE_REFERENCES = 50;
const int MAX_PHYSICAL_PAGES = 10;

/** fifo page replacement simulation
*  Perform first-in first-out (FIFO) page replacement simulation.
*
* @arg framesize The number of physical frames of memory to simulate.
* @arg numref The number of page references in the simulated page address
*       stream.  There should be pagestream[0] to pagestream[numref-1]
*       pages in the pagestream.
* @arg pagestream An array of integers.  The value indicates a references
*       page, and the index is the time when the page was referenced.
*/
void fifo(int framesize, int numref, int* pagestream)
{
  // implement fifo (first-in-first-out) page replacement here

  int pageFaults = 0;
  list<int> frames;


  // an example of stepping through time and the pagestream to get
  // you going
  for (int time = 0; time < numref; time++)
  {
    if (frames.size() < framesize)    //if we have more frames
    {
      frames.push_back(pagestream[time]);   //put the page reference into the list
    }
    else
    {
      pageFaults++;
      frames.pop_front(); //remove the front most frame since this is FIFO
      frames.push_back(pagestream[time]); //put the page reference into the list
    }


    cout << "Time: " << time << endl;
    cout << "Page: " << pagestream[time] << endl;

    int size = frames.size();
    for (int i = 0; i < size; i++)
    {
      cout << "Frame" << i << ": " << frames.front();
      frames.pop_front(); //remove the front most frame, it is no longer needed
    }

    cout << "Hit ratio: " << pageFaults << " / " << numref << " (" << pageFaults / numref << ")";

    cout << endl;
  }
}

/** run through list and check if the frame is in the list, returns 1 if it exists, returns -1 if it does not
*@arg list the list that will be iterated through
*@arg frame the page reference we are looking for
*/

int checkFrame(list<int>& frameList, int frame)
{
  int size = frameList.size();

  for (int i = 0; i < size; i++ )
  {
    if (frame == frameList.front()) //check to see if frame is equal to the first value
    {
      return 1;
    }
    else  //if not then remove the first value and continue the loop
    {
      frameList.pop_front();
    }
  }

  return -1;  //we did not find a value that was equivalent, exit the function with -1
}


/** lru page replacement simulation
*  Perform least recently used (LRU) page replace simulation.
*
* @arg framesize The number of physical frames of memory to simulate.
* @arg numref The number of page references in the simulated page address
*       stream.  There should be pagestream[0] to pagestream[numref-1]
*       pages in the pagestream.
* @arg pagestream An array of integers.  The value indicates a references
*       page, and the index is the time when the page was referenced.
*/
void lru(int framesize, int numref, int* pagestream)
{
  // implement lru (least recently used) page replacement here
  int pageFaults;
  list<int> frames;
  int test; //used to hold the value returned from the check frame function
  // an example of stepping through time and the pagestream to get
  // you going
  for (int time = 0; time < numref; time++)
  {
    
    if (frames.size() < framesize)    //if we have more space for frames
    {
      frames.push_back(pagestream[time]);   //put the page reference into the list
    }
    else
    {
      test = checkFrame(frames, pagestream[time]);
      if (test == -1)  //the frame does not exist, and therefore fault occured
      {
        frames.pop_front(); //the least recently used should be at the front, since we add frames to the back
        pageFaults++; //fault occured, increment the pageFault tracker
        frames.push_back(pagestream[time]);
      }
      //the frame does exist, fault did not occur, continue the algorithm
    }

    cout << "Time: " << time << endl;
    cout << "Page: " << pagestream[time] << endl;

    int size = frames.size();
    for (int i = 0; i < size; i++)
    {
      cout << "Frame" << i << ": " << frames.front();
      frames.pop_front(); //remove the front most frame, it is no longer needed
    }

    cout << "Hit ratio: " << pageFaults << " / " << numref << " (" << pageFaults / numref << ")";

    cout << endl;
  }
}

/** Load page references from file
*  Load the stream of simulated page references from the indicate file.
*  return the references in a simple array of integers.
*
* @param simfilename  The name of the file to open and read page references
*           from.
* @param pagestream Should be a pointer to an array of integers.  The array
*           is filled with the page references on return.  The index of each
*           reference indicates time when the page references occurs in
*           simulation.
* @returns int The number of page references in the page stream.
*/
int loadPageStream(char* simfilename, int* pagestream)
{
  ifstream pagestreamfile(simfilename);
  int pageref;
  int time;

  // If we can't open file, abort and let the user know problem
  if (!pagestreamfile.is_open())
  {
    cout << "Error: could not open page simulation file: " << simfilename
      << endl;
    exit(1);
  }

  // Load simulated page references into integer array
  time = 0;
  while (!pagestreamfile.eof())
  {
    pagestreamfile >> pageref;
    pagestream[time] = pageref;
    time++;
    pagestreamfile >> ws;  // extract newlines from end of line
  }

  return time;
}

/** Main entry point of simulator
*  The main entry point of the page replacement simulator.  Process
*  command line arguments and call appropriate simulation.  We expect
*  three command line arguments: pageref.sim  [fifo|lru]  framesize
*
* @param argc The argument count
* @param argv The command line argument values. We expect argv[1] to be the
*              name of a file in the current directory holding page file
*              references, argv[2] to indicate [fifo|lru] and argv[3] to be
*              an integer indicating size of memory in frames.
*/
int main(int argc, char** argv)
{
  int framesize = 0;
  int pagestream[MAX_PAGE_REFERENCES];
  int numref;
  string scheme;

  // If not all parameters not provided, abort and let user know of problem
  if (argc != 4)
  {
    cout << "Usage: " << argv[0] << " pageref.sim [lru|fifo] framesize" << endl;
    exit(1);
  }

  // load page stream and parse command line arguments
  numref = loadPageStream(argv[1], pagestream);
  scheme.assign(argv[2]);
  framesize = atoi(argv[3]);

  // perform simulation of indicated replacement scheme
  if (scheme == "lru")
  {
    lru(framesize, numref, pagestream);
  }
  else if (scheme == "fifo")
  {
    fifo(framesize, numref, pagestream);
  }
  else
  {
    cout << "Error: unknown page replacement scheme: " << scheme << endl;
    exit(1);
  }
}