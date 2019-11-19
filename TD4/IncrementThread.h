#ifndef INC_THREAD_H
#define INC_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "data.h"

class IncrementThread : public Thread
{
	public :
		IncrementThread(Data data);
		~IncrementThread();
		Data data;

	protected :
		void run();
};

#endif
