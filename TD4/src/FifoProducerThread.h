#ifndef FIFO_PROD_THREAD_H
#define FIFO_PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Fifo.hpp"

class FifoProducerThread : public Thread
{
	public :
		FifoProducerThread(Fifo<int>& fifo, int n);
		~FifoProducerThread();

	protected :
		void run();
		Fifo<int>& fifo;
		int n;
};

#endif
