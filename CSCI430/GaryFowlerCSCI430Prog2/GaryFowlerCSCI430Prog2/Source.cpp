/** @file  Source.cpp
*
* @author Gary Fowler III
*
* @assg   Programming Assignment #2
*
* @date   June 18, 2017
*/
#include <stdlib.h>
#include "ProcessControlBlock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int nextProcessID = 1;
int currentSystemTime = 1;
bool processRunning = false;

list<ProcessControlBlock> processList;  //list to hold the ready processes

/**The process dispatcher
*See if anything in ready queue, make next process run, pop running process from ready queue
*
*/
ProcessControlBlock dispatcher()
{
  if (!processRunning) //if there is no process running, set a new process running
  {
    ProcessControlBlock nextProcessToRun = processList.front();
    processRunning = true;
    return nextProcessToRun;
  }
}

/**Output the simulation
*Output the current timestamp as well as all information about the processes
*
*
*/
void simulationOutput(ProcessControlBlock process)
{
  cout << "Time: " << currentSystemTime << endl;
  cout << "CPU (currently running): " << endl;
  process.outputProcess();
  cout << "Ready Queue: " << endl;
  //ready queue
  cout << "Blocked Queue: " << endl;
  //blocked queue
  cout << endl;
}

/** The process simulator.
* The main loop for running a simulation.  We read simulation
* events from a file
*
* @param simfilename The name of the file (e.g. simulaiton-01.sim) to open
*     and read simulated event sequence from.
* @param timeSliceQuantum The value to be used for system time slicing preemption
*     for this simulation.
*/
void runSimulation(char* simfilename, int timeSliceQuantum)
{
  ifstream simeventsfile(simfilename);
  string command;
  int eventnum;

  if (!simeventsfile.is_open())
  {
    cout << "Error: could not open simulator events file: " << simfilename << endl;
    exit(1);
  }

  while (!simeventsfile.eof())
  {
    simeventsfile >> command;

    // Handle the next simulated event we just read from the
    // simulation event file
    if (command == "cpu")
    {
      ProcessControlBlock nextProcess = dispatcher();
      if (nextProcess.getTimeSliceQuantumsUsed() < timeSliceQuantum)
      {
        simulationOutput(nextProcess);
      }
      else
      {
        processList.push_back(nextProcess);
      }
      currentSystemTime++;
    }
    else if (command == "new")
    {
      ProcessControlBlock newProcess(nextProcessID, currentSystemTime, "NEW", 1);   //process is new, timeSliceQuantums used is default 1
      nextProcessID++;
      processList.push_back(newProcess);
      simulationOutput(newProcess);
      currentSystemTime++;
    }
    else if (command == "done")
    {
      cout << "   done: simulate termination of currently running process here" << endl;
      processList.pop_front();
      currentSystemTime++;
    }
    else if (command == "wait")
    {
      simeventsfile >> eventnum;
      cout << "   wait: eventnum: " << eventnum <<
        " simulate event blocked and waiting" << endl;

      currentSystemTime++;
    }
    else if (command == "event")
    {
      simeventsfile >> eventnum;
      cout << "   event: eventnum: " << eventnum <<
        " simulate event occurring possibly making some processes ready" << endl;

      currentSystemTime++;
    }
    else if (command == "exit")
    {
      // we use an explicit indicator to ensure simulation exits correctly
      break;
    }
    else
    {
      cout << "    ERROR: unknown command: " << command << endl;
      exit(0);
    }

  }

  simeventsfile.close();
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
*/
int main(int argc, char** argv)
{
  int timeSliceQuantum = 0;

  // validate command line arguments
  if (argc != 3)
  {
    cout << "Error: expecting event file as first command line parameter and time slice quantum as second" << endl;
    cout << "Usage: " << argv[0] << " simeventfile.sim time_slice" << endl;
    exit(1);
  }

  // Assume second command line argument is the time slice quantum and parse it
  timeSliceQuantum = atoi(argv[2]);
  if (timeSliceQuantum <= 0)
  {
    cout << "Error: invalid time slice quantum received: " << timeSliceQuantum << endl;
    exit(1);
  }

  // Invoke the function to actually run the simulation
  runSimulation(argv[1], timeSliceQuantum);

  // if don't want to use command line do following.
  // need to recompile by hand since file 
  // name to get simulated events from is hard coded
  //runSimulation("simulation-01.sim", 5);

  return 0;
}
