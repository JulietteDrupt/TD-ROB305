#include "ProductorThread.h"
#include "ConsumerThread.h"
#include "Semaphore.h"
#include "Mutex.h"
#include <signal.h>

int main()
{
	Semaphore sem;
	unsigned int nCons = 5;
	unsigned int nProd = 5;
	ProductorThread *prodThreads[nProd];
	ConsumerThread *consThreads[nProd];

	for (unsigned int i=0; i<nProd; i++)
	{
		prodThreads[i] = new ProductorThread(sem);
	}

	for (unsigned int i=0; i<nCons; i++)
	{
		consThreads[i] = new ConsumerThread(sem);
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

