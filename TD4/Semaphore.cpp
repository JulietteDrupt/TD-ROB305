#include "Semaphore.h"
#include "Mutex.h"
#include <pthread.h>

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount) : counter(initCount), maxCount(maxCount)
{}

void give()
{
	if (this -> counter == 0)
	{
		Mutex::TryLock mtl = Mutex::TryLock(this -> mutex);
		mtl.notify()
		mtl.~TryLock();
	}
	if (this -> counter < maxCount)
	{
		this -> counter += 1;
	}
}

void take()
{
	if (counter > 0)
	{
		this -> counter -= 1;
	}

	if (counter == 0)
	{
		// si le compteur de jetons est à zéro, appel bloquant
		Mutex::Lock ml = Mutex::Lock(this -> mutex);
		ml.wait();
		ml.~Lock();
	}
}

bool take(double timeout_ms)
{
	if (counter > 0)
	{
		this -> counter -= 1;
	}

	if (counter == 0)
	{
		// si le compteur de jetons est à zéro, appel bloquant
		Mutex::Lock ml = Mutex::Lock(this -> mutex);
		bool val = ml.wait(timeout_ms);
		ml.~Lock();
		return val;
	}
}

