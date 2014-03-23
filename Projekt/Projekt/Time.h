#pragma once
#include <windows.h>
#include <time.h>
#include <iostream>

using namespace std;
class Time
{
private:
<<<<<<< HEAD
	LARGE_INTEGER performanceCountStart,performanceCountEnd, freq; 
=======
	LARGE_INTEGER performanceCountStart,performanceCountEnd,freq; 
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b
	double time;
public:
	
	Time(void);
	~Time(void);
	void start1(void);
	double stop1(void);
	void Print(void);
	LARGE_INTEGER startTimer(void);
	LARGE_INTEGER endTimer(void);
};

