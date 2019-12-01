#ifndef SEM_PROD_THREAD_H
#define SEM_PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

class SemProducerThread : public Thread
{
	public :
		SemProducerThread(Semaphore& sem);
		~SemProducerThread();
	protected :
		void run();
		Semaphore& sem;
		
};


#endif
