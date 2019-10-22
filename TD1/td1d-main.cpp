#include <time.h>
#include <iostream>
#include <string>
#include <climits>
#include <signal.h>
#include "TimeSpec.h"
using namespace std;

unsigned incr(unsigned int nLoops, double* pCounter, volatile bool* pStop)
{
	unsigned int i = 0;
	while (i < nLoops && not *pStop)
	{
		*pCounter += 1.0;
		i++;
	cout << *pCounter << endl;
	}
	return i;
}


void myHandler(int sig, siginfo_t* si, void*)
{
	cout << "je suis dans le handler" << endl;
	*((bool*)(si->si_value.sival_ptr)) = true;
}


int main(int argc, char* argv[])
{
	volatile bool stop = false;
	unsigned int nLoops = UINT_MAX;
	//nLoops = stoi(argv[1]);
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

	timer_t tid;
	timer_create(CLOCK_REALTIME, &sev, &tid);
	itimerspec its;
	its.it_value.tv_sec = 1;
	its.it_value.tv_nsec = 0;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;
	timer_settime(tid, 0, &its, NULL);
	
	
	timespec time_begin = timespec_now();
	incr(nLoops, &counter, &stop);
	timespec time_end = timespec_now();

	timer_delete(tid);



	timespec duration_ts = time_end - time_begin;
	double duration_s = timespec_to_ms(duration_ts) / 1e3;
	cout << "Duration : " << duration_s << " s" << endl;
	
	return 0;
}
