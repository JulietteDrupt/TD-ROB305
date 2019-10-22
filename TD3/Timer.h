#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <signal.h>
#include <time.h>

class Timer
{
	public :
		// Constructeur et destructeur
		Timer();
		virtual ~Timer();

		// Méthodes autres
		void start (double duration_ms);
		void stop();

	protected :
		timer_t tid;
		virtual void callback() = 0;

	private :
		static void call_callback (int sig, siginfo_t* si, void* user);
		struct sigaction sa;
		struct sigevent sev;
		itimerspec its;
}

#endif
