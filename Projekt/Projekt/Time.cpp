#include "Biblioteki.h"


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

double Time::stop1()
{
	performanceCountEnd =endTimer();
	
	time=double(performanceCountEnd.QuadPart-performanceCountStart.QuadPart);
	
	return time;
}

LARGE_INTEGER Time::startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
<<<<<<< HEAD

=======
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b

return start;
}

LARGE_INTEGER Time::endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
<<<<<<< HEAD


QueryPerformanceFrequency(&freq);

=======
QueryPerformanceCounter(&freq);
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b
return stop;
}


void Time::Print()
{	
	cout.setf(ios::fixed);
<<<<<<< HEAD
	cout<<setprecision(10)<<"\nCzas: "<<(time / double(freq.QuadPart)  )*1000<<endl;
=======
	cout<<"\nCzas: "<<(time/freq.QuadPart)*1000<<endl;
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b
}