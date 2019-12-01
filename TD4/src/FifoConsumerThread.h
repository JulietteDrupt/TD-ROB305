#ifndef FIFO_CONS_THREAD_H
#define FIFO_CONS_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Fifo.hpp"

class FifoConsumerThread : public Thread
{
	public :
		FifoConsumerThread(Fifo<int>& fifo, int n);
		~FifoConsumerThread();

	protected :
		void run();
		Fifo<int>& fifo;
		int n;
};

#endif
