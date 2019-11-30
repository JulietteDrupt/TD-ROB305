/*!
 * \file Timer.cpp
 * \brief Timer class implementation
 * \author Juliette DRUPT
 */

#include "Timer.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;

Timer::Timer()
{
	cout << "Instanciating timer" << endl;

	(this -> sa).sa_flags = SA_SIGINFO;
	(this -> sa).sa_sigaction = Timer::call_callback;
	sigemptyset(&(this -> sa).sa_mask);
	sigaction(SIGRTMIN, &(this -> sa), NULL);

	(this -> sev).sigev_notify = SIGEV_SIGNAL;
	(this -> sev).sigev_signo = SIGRTMIN;
	(this -> sev).sigev_value.sival_ptr = this;

	timer_create(CLOCK_REALTIME, &(this -> sev), &(this -> tid));
}

Timer::~Timer()
{
	cout << "Deleting timer" << endl;
	timer_delete(this -> tid);
}

void Timer::start (double duration_ms)
{

	itimerspec its;
	its.it_value = timespec_from_ms(duration_ms);
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &its, NULL);

}

void Timer::stop ()
{

	cout << "Stopping timer" << endl;

	itimerspec its;
	its.it_value = timespec_from_ms(0.0);
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &its, NULL);
}

void Timer::call_callback (int sig, siginfo_t* si, void* user)
{
	Timer *timer = ((Timer *) si->si_value.sival_ptr) ;
	timer -> callback();
}
