#include "SemProducerThread.h"
#include "SemConsumerThread.h"
#include "Semaphore.h"
#include "Mutex.h"
#include <signal.h>

int main()
{
	Semaphore sem;
	unsigned int nCons = 5;
	unsigned int nProd = 5;
	SemProducerThread *prodThreads[nProd];
	SemConsumerThread *consThreads[nProd];

	for (unsigned int i=0; i<nProd; i++)
	{
		prodThreads[i] = new SemProducerThread(sem);
	}

	for (unsigned int i=0; i<nCons; i++)
	{
		consThreads[i] = new SemConsumerThread(sem);
	}

	for (unsigned int i=0; i<nProd; i++)
	{
		prodThreads[i] -> start();
	}

	for (unsigned int i=0; i<nCons; i++)
	{
		consThreads[i] -> start();
	}

	for (unsigned int i=0; i<nProd; i++)
	{
		prodThreads[i] -> join();
	}

	for (unsigned int i=0; i<nCons; i++)
	{
		consThreads[i] -> join();
	}

	return 0;
}

