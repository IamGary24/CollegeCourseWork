//the cpp for the ProcessControlBlock.h header file
//author: Gary Fowler III

#include "ProcessControlBlock.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

ProcessControlBlock::ProcessControlBlock(int id, int start, string state, int time)
{
  setPID(id);
  setStart(start);
  setState(state);
  setTimeSliceQuantumsUsed(time);
  int blockingEvent = 0;  //blocking event only needs to be called if an event is blocking the process
}

//setters
void ProcessControlBlock::setPID(int id)
{
  pid = id;
}
void ProcessControlBlock::setStart(int start)
{
  systemTimeStart = start;
}
void ProcessControlBlock::setState(string state)
{
  processState = state;
}
void ProcessControlBlock::setEvent(int event)
{
  blockingEvent = event;
}
void ProcessControlBlock::setTimeSliceQuantumsUsed(int time)
{
  timeSliceQuantums = time;
}


//getters
int ProcessControlBlock::getPID()
{
  return pid;
}
int ProcessControlBlock::getStart()
{
  return systemTimeStart;
}
string ProcessControlBlock::getState()
{
  return processState;
}
int ProcessControlBlock::getEvent()
{
  return blockingEvent;
}
int ProcessControlBlock::getTimeSliceQuantumsUsed() 
{
  return timeSliceQuantums;
}



void ProcessControlBlock::outputProcess() 
{
  cout << "pid=" << pid << ", ";
  cout << "state=" << processState << ", ";
  cout << "start=" << systemTimeStart << ", ";
  cout << "slice=" << timeSliceQuantums << ", ";

  if (blockingEvent > 0) 
  {
    cout << "event=" << blockingEvent << endl;
  }
  else
  {
    cout << endl;
  }
}


ProcessControlBlock::~ProcessControlBlock()
{
}
