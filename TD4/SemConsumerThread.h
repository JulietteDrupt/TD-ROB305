#ifndef SEM_CONS_THREAD_H
#define SEM_CONS_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

class SemConsumerThread : public Thread
{
	public :
		SemConsumerThread(Semaphore& sem);
		~SemConsumerThread();
	protected :
		void run();
		Semaphore& sem;
		
};


#endif
