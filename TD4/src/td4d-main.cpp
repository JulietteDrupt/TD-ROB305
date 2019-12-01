/**
 * \file td4d-main.cpp
 * \brief Tests Fifo class
 * \author Juliette DRUPT
 * \date December 1st 2020
 *
 * This program tests Fifo class using threads that produce and consume elements of a Fifo
 */

#include "Fifo.hpp"
#include "FifoProducerThread.h"
#include "FifoConsumerThread.h"

int main()
{
	Fifo<int> fifo;
	int n = 5;

	FifoProducerThread *prodThreads[n];
	FifoConsumerThread *consThreads[n];

	for (int i=0; i<n; i++)
	{
		prodThreads[i] = new FifoProducerThread(fifo,n);
		consThreads[i] = new FifoConsumerThread(fifo,n);
	}

	for (int i=0; i<n; i++)
	{
		prodThreads[i] -> start();
		consThreads[i] -> start();
	}

	for (int i=0; i<n; i++)
	{
		prodThreads[i] -> join();
		consThreads[i] -> join();
	}

	return 0;
}
