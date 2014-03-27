#pragma once
#include <windows.h>
#include <time.h>
#include <iostream>

using namespace std;
class Time
{
private:

	LARGE_INTEGER performanceCountStart,performanceCountEnd,freq; 
	double time;
public:
	
	Time(void);
	~Time(void);
	void start1(void);
	double stop1(void);
	void Print(void);
	double zwrocCzas();
	LARGE_INTEGER startTimer(void);
	LARGE_INTEGER endTimer(void);
};

