#ifndef SEM_PROD_THREAD_H
#define SEM_PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

class SemProductorThread : public Thread
{
	public :
		SemProductorThread(Semaphore& sem);
		~SemProductorThread();
	protected :
		void run();
		Semaphore& sem;
		
};


#endif
