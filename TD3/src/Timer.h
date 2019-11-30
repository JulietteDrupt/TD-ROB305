#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <signal.h>

class Timer
{
	public :
		// Constructeur et destructeur
		Timer();
		/*!
 		 *  \brief Destructeur
 	 	 *
 	 	 *  Destructeur de la classe CPlayer
 	 	 */
		~Timer();

		// Méthodes autres
		void start (double duration_ms);
		void stop();

	protected :
		timer_t tid;
		virtual void callback() = 0;
		struct sigaction sa;
		struct sigevent sev;

	private :
		static void call_callback (int sig, siginfo_t* si, void* user);

};

#endif
