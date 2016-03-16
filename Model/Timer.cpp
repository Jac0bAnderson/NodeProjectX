/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: jand6944
 */

#include "Timer.h"
#include <iostream>
#include <iomanip>
using namespace std;
Timer :: Timer()
{
executionTime = 0;
}

Timer :: ~Timer()
{
cout << fixed;
cout << setprecision(8);

cout << executionTime << " μs (microseconds) for the code" << endl;
cout << "which is " << float(executionTime)/CLOCKS_PER_SEC << "seconds" << endl;
}

void Timer :: displayTimerInformation()
{

}
void Timer :: startTimer()
{
	executionTime = clock();
}
void Timer :: stopTimer()
{
	executionTime = clock()- executionTime;
}
void Timer :: resetTimer()
{
	executionTime = 0;
}
long Timer :: getExecutionTimeInMicroseconds()
{
	return executionTime;
}



