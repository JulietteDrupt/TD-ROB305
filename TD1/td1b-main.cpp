#include <signal.h>
#include <time.h>
#include <iostream>
using namespace std;

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
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 500000000;
	timer_settime(tid, 0, &its, NULL);
	while (value < 15)
		continue;
	timer_delete(tid);
	return 0;
}
