#ifndef THREAD_CPU_LOOP_H
#define THREAD_CPU_LOOP_H

#include "../TD3/CpuLoop.h"
#include "../TD4/Thread.h"
#include "../TD4/Mutex.h"
#include "../TD3/Calibrator.h"
#include <signal.h>

class ThreadWithCpuLoop : public Thread
{
	public :
		ThreadWithCpuLoop(Mutex& mutex, CpuLoop& cpul);
		~ThreadWithCpuLoop();
		CpuLoop& cpul;

	protected :
		void run();

	private :
		Mutex& mutex;
		
};

#endif
