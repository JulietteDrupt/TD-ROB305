#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "Mutex.h"
#include <signal.h>
#include <climits>

class Semaphore
{
	public :
		Semaphore(unsigned int initCount = 0, unsigned int masCount = UINT_MAX);
		void give();
		void take();
		bool take(double timeout_ms);

	private :
		unsigned int counter;
		unsigned int maxCount;
		Mutex mutex;
};

#endif
