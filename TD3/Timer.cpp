#include "Timer.h"
#include "TimeSpec.h"
#include <signal.h>

Timer::Timer()
{
	
	(this -> sa).sa_flags = SA_SIGINFO;
	(this -> sa).sa_sigaction = this -> callback;
	sigemptyset(&(this -> sa).sa_mask);
	sigaction(SIGRTMIN, &(this -> sa), NULL);

	(this -> sev).sigev_notify = SIGEV_SIGNAL;
	(this -> sev).sigev_notify = SIGRTMIN;
	(this -> sev).sigev_value.sival_ptr = (void*) &value;

	timer_create(CLOCK_REALTIME, &(this -> sev), &(this -> tid));	
}

void Timer::start (double duration_ms)
{
	

	(this -> its).it_value = timespec_from_ms(duration_ms);
	(this -> its).it_interval.tv_sec = 0;
	(this -> its).it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &(this -> its), NULL);
}

void Timer::stop (double duration_ms)
{
	

	(this -> its).it_value = timespec_from_ms(0.0);
	(this -> its).it_interval.tv_sec = 0;
	(this -> its).it_interval.tv_nsec = 0;

	timer_settime(this -> tid, 0, &(this -> its), NULL);
}


