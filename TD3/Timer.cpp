#include "Timer.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;

Timer::Timer()
{
	cout << "Instanciating timer" << endl;
	
	(this -> sa).sa_flags = SA_SIGINFO;
	(this -> sa).sa_sigaction = this -> call_callback;
	sigemptyset(&(this -> sa).sa_mask);
	sigaction(SIGRTMIN, &(this -> sa), NULL);

	(this -> sev).sigev_notify = SIGEV_SIGNAL;
	(this -> sev).sigev_notify = SIGRTMIN;
	(this -> sev).sigev_value.sival_ptr = NULL; //(void*) &value;

	timer_create(CLOCK_REALTIME, &(this -> sev), &(this -> tid));	
}

Timer::~Timer()
{
	cout << "Deleting timer" << endl;
	timer_delete(this -> tid);
}

void Timer::start (double duration_ms)
{
	cout << "Starting timer" << endl;

	(this -> its).it_value = timespec_from_ms(duration_ms);
	(this -> its).it_interval.tv_sec = 0;
	(this -> its).it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &(this -> its), NULL);
}

void Timer::stop ()
{
	cout << "Stopping timer" << endl;

	(this -> its).it_value = timespec_from_ms(0.0);
	(this -> its).it_interval.tv_sec = 0;
	(this -> its).it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &(this -> its), NULL);
}

void Timer::call_callback (int sig, siginfo_t* si, void* user)
{
	cout << "In the call callback" << endl;
	Timer *parent = static_cast<Timer *>(user);
	parent -> callback();
}


