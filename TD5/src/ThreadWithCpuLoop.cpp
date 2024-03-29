#include "ThreadWithCpuLoop.h"
#include "CpuLoop.h"
#include "Mutex.h"
#include "Calibrator.h"
#include <time.h>

double tick_to_ms(int ticks)
{
	double duration_ms = (double) ticks / CLOCKS_PER_SEC * 1e3;
	return duration_ms;
}

ThreadWithCpuLoop::ThreadWithCpuLoop(Mutex& mutex, CpuLoop& cpul, int tick_duration, int tick_delay, int tick_beginning, int tick_access_try, int tick_access_free) : Thread(), cpul(cpul), mutex(mutex)
{
	this -> duration = tick_to_ms(tick_duration);
	this -> delay = tick_to_ms(tick_delay);
	this -> beginning = tick_to_ms(tick_beginning);
	this -> access_try = tick_to_ms(tick_access_try);
	this -> access_free = tick_to_ms(tick_access_free);
}

ThreadWithCpuLoop::~ThreadWithCpuLoop()
{}


bool ThreadWithCpuLoop::start()
{
	this -> sleep_ms(this -> beginning);
	return Thread::start();
}

void ThreadWithCpuLoop::run()
{
	if (this -> access_try > 0 && this -> access_free > 0)
	{
		(this -> cpul).runTime(this -> access_try);
		Mutex::Lock ml = Mutex::Lock(this -> mutex, this -> access_free);
		(this -> cpul).runTime(this -> access_free);
		ml.~Lock();
		(this -> cpul).runTime(this -> duration - (this -> access_try + this -> access_free));
	}
	else
	{
		(this -> cpul).runTime(this -> duration);
	}
}
