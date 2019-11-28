#include "FifoProducerThread.h"
#include <iostream>
using namespace std;

FifoProducerThread::FifoProducerThread(Fifo<int>& fifo, int n) : Thread(), fifo(fifo), n(n)
{}

FifoProducerThread::~FifoProducerThread()
{}

void FifoProducerThread::run()
{
	for (int i = 0; i < (this -> n); i++)
	{
		(this -> fifo).push(i);
	}
}

