#include "Time.h"


Time::Time(void)
{
}


Time::~Time(void)
{
}
void Time::start1()
{
	performanceCountStart = startTimer(); 
}

long double Time::stop1()
{
	performanceCountEnd =endTimer();
	time=performanceCountEnd.QuadPart-performanceCountStart.QuadPart;
	return time;
}

LARGE_INTEGER Time::startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}


LARGE_INTEGER Time::endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}


void Time::Print()
{
	cout<<"\nCzas: "<<cout.setf(ios::fixed)<<time<<endl;
}