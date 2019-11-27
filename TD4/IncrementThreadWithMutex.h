#ifndef INC_THREAD_MUTEX_H
#define INC_THREAD_MUTEX_H

#include "IncrementThread.h"
#include "Mutex.h"
#include "data.h"
#include <signal.h>

class IncrementThreadWithMutex : public IncrementThread
{
	public :
		IncrementThreadWithMutex(Data data, Mutex::Monitor& monitor);
		~IncrementThreadWithMutex();
	protected :
		Mutex::Monitor& monitor;
};

#endif