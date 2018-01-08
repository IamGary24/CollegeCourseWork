

#pragma once
#include <stdlib.h>
#include <string>
#ifndef PROCESSCONTROLBLOCK_HEADER
#define PROCESSCONTROLBLOCK_HEADER

using namespace std;
class ProcessControlBlock
{
private:
  int pid;
  int systemTimeStart;
  string processState;
  int blockingEvent;
  int timeSliceQuantums;

public:
  
  //initialize each value contained in the ProcessControlBlock object
  ProcessControlBlock();
  ProcessControlBlock(int id, int start, string state, int time);

  //setters for each individual value in the object
  void setPID(int id);
  void setStart(int start);
  void setState(string state);
  void setEvent(int event);
  void setTimeSliceQuantumsUsed(int time);

  //getters for each individual value in the object
  int getPID();
  int getStart();
  string getState();
  int getEvent();
  int getTimeSliceQuantumsUsed();

  //output the process information
  void outputProcess();

  ~ProcessControlBlock();
};

#endif