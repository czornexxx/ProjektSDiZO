#include "Biblioteki.h"
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


return start;
}

LARGE_INTEGER Time::endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);



QueryPerformanceFrequency(&freq);


return stop;
}

double Time::zwrocCzas(){

	return (( time / double(freq.QuadPart)  )*1000);
}


void Time::Print()
{	
	cout.setf(ios::fixed);
	cout<<setprecision(10)<<"\nCzas: "<<(time / double(freq.QuadPart)  )*1000<<endl;

}