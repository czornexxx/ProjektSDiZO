#pragma once
#include <windows.h>
#include <time.h>
#include <iostream>;

using namespace std;
class Time
{
private:
	LARGE_INTEGER performanceCountStart,performanceCountEnd; 
	long double time; 
public:
	
	Time(void);
	~Time(void);
	void start1(void);
	long double stop1(void);
	void Print(void);
	LARGE_INTEGER startTimer(void);
	LARGE_INTEGER endTimer(void);
};

