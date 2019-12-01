#ifndef THREAD_CPU_LOOP_H
#define THREAD_CPU_LOOP_H

#include "CpuLoop.h"
#include "Thread.h"
#include "Mutex.h"
#include "Calibrator.h"
#include <signal.h>

class ThreadWithCpuLoop : public Thread
{
	public :
		ThreadWithCpuLoop(Mutex& mutex, CpuLoop& cpul, int tick_duration, int tick_delay, int tick_beginning, int tick_access_try = -1, int tick_access_free = -1);
		~ThreadWithCpuLoop();
		CpuLoop& cpul;
		bool start();
		bool delay_respected();

	protected :
		void run();

	private :
		Mutex& mutex;
		double duration;
		double delay;
		double beginning;
		double access_try;
		double access_free;
};

#endif
