/**
 * \file td1d-main.c
 * \brief Mesures the execution time of a function.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program measures the execution time of a function that increments the value of a counter by executing a loop a given number of times.
 *
 */

#include <time.h>
#include <iostream>
#include <string>
#include <climits>
#include <signal.h>
#include "TimeSpec.h"
using namespace std;

/**
 * \fn unsigned incr(unsigned int nLoops, double* pCounter, volatile bool* pStop)
 * \brief Adds 1.0 to a counter at each iteration of a loop.
 *
 * \param nLoops Number of loop iterations to run.
 * \param pCounter Pointer to the counter to be incremented.
 * \param pStop Pointer to a boolean : the function runs while its value is false but ends if it turns to true.
 * \return Number of loops that were executed by the function.
 */
unsigned incr(unsigned int nLoops, double* pCounter, volatile bool* pStop)
{
	unsigned int iLoop = 0;
	while (iLoop < nLoops && not *pStop)
	{
		*pCounter += 1.0;
		iLoop++;
	}
	return iLoop;
}

/**
 * \fn void myHandler(int sig, siginfo_t* si, void*)
 * \brief Callback that turns a boolean value to true.
 *
 */
void myHandler(int sig, siginfo_t* si, void*)
{
	*((bool*)(si->si_value.sival_ptr)) = true;
}

/**
 * \fn void calib()
 * \brief Determines the equation of the number of loops depending on the time, l(t) = a*t+b, t being the time.
 *
 * This function uses two Posix timers to get two values of l(t) for two given values of time t (4 and 6 seconds), what allows to compute a and b. The timers used run myHandler at a given time to stop the loop and then get the number of loops executed. The computed values for a and b are displayed at the end of the function.
 *
 */
void calib()
{
	cout << "Starting calibration" << endl;

	volatile bool stop = false;
	unsigned int nLoops = UINT_MAX;
	double counter = 0.0;


	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = myHandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN, &sa, NULL);

	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr = (void*) &stop;

	// For t = 4s :
	cout << "For t = 4s :" << endl;

	timer_t tid;
	timer_create(CLOCK_REALTIME, &sev, &tid);
	itimerspec its;
	its.it_value.tv_sec = 4;
	its.it_value.tv_nsec = 0;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;
	timer_settime(tid, 0, &its, NULL);


	timespec time_begin = timespec_now();
	unsigned int l4 = incr(nLoops, &counter, &stop);
	timespec time_end = timespec_now();

	timer_delete(tid);

	timespec duration_ts = time_end - time_begin;
	double t4 = timespec_to_ms(duration_ts) / 1e3;
	cout << "Duration : " << t4 << " s" << endl;
	cout << "Number of loops executed : " << l4 << endl;

	// For t = 6s :
	stop = false;
	nLoops = UINT_MAX;
	counter = 0.0;
	cout << "For t = 6s :" << endl;

	timer_create(CLOCK_REALTIME, &sev, &tid);
	its.it_value.tv_sec = 6;
	its.it_value.tv_nsec = 0;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;
	timer_settime(tid, 0, &its, NULL);


	time_begin = timespec_now();
	unsigned int l6 = incr(nLoops, &counter, &stop);
	time_end = timespec_now();

	timer_delete(tid);

	duration_ts = time_end - time_begin;
	double t6 = timespec_to_ms(duration_ts) / 1e3;
	cout << "Duration : " << t6 << " s" << endl;
	cout << "Number of loops executed : " << l6 << endl;

	// Find a and b (l(t) = a*t + b)
	double a = (l6 - l4)/(t6 - t4);
	double b = l4 - a * t4;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}



int main()
{
	calib();
	return 0;
}
