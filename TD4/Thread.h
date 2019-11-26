#ifndef THREAD_H
#define THREAD_H

#include <signal.h>
#include <time.h>
#include "PosixThread.h"

class Thread : public PosixThread
{
	public :
		Thread();
		~Thread();
		bool start();
		static void sleep_ms(double delay_ms);
		double startTime_ms();
		double stopTime_ms();
		double execTime_ms();
		static bool started;

	protected :
		virtual void run() = 0;

	private :
		static void* call_run(void* v_thread);
		timespec startTime;
		timespec stopTime;
		pthread_attr_t posixAttr;
};

#endif
