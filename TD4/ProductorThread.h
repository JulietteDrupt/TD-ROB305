#ifndef PROD_THREAD_H
#define PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

class ProductorThread : public Thread
{
	public :
		ProductorThread(Semaphore& sem);
		~ProductorThread();
	protected :
		void run();
		Semaphore& sem;
		
};


#endif
