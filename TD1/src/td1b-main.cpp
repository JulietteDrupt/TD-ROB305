/**
 * \file td1b-main.cpp
 * \brief Posix timer with callback implementation.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program implements a Posix periodic timer that prints a message with the value of a counter at a 2 Hz frequency for 15 iterations.
 *
 */

#include <signal.h>
#include <time.h>
#include <iostream>
using namespace std;

/**
 * \fn void myHandler(int sig, siginfo_t* si, void*)
 * \brief Callback that prints "coucou i", i being a value that is incremented each time the callback is executed.
 *
 */
void myHandler(int sig, siginfo_t* si, void*)
{
	*((int*)(si->si_value.sival_ptr)) += 1;
	cout << "coucou " << *((int*)(si->si_value.sival_ptr)) << endl;
}

int main()
{
	volatile int value = 0;

	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = myHandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN, &sa, NULL);

	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr = (void*) &value;

	timer_t tid;
	timer_create(CLOCK_REALTIME, &sev, &tid);
	itimerspec its;
	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = 500000000;
	// Sets 2 Hz frequency
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 500000000;
	timer_settime(tid, 0, &its, NULL);
	// Stop timer after 15 periods (value being incremented of 1 at each period)
	while (value < 15)
		continue;
	timer_delete(tid);
	return 0;
}
