#ifndef CONS_THREAD_H
#define CONS_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

class ConsumerThread : public Thread
{
	public :
		ConsumerThread(Semaphore& sem);
		~ConsumerThread();
	protected :
		void run();
		Semaphore& sem;
		
};


#endif
