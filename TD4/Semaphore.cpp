#include "Semaphore.h"
#include <pthread.h>
#include <climits>

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount) : counter(initCount), maxCount(maxCount)
{}

void give()
{
	if (counter < UINT_MAX)
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
}

