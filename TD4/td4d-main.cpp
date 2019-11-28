#include "Fifo.hpp"
#include "FifoProducerThread.h"
#include "FifoConsumerThread.h"

int main()
{
	Fifo<int> fifo;
	int n = 5;
	FifoProducerThread fpt = FifoProducerThread(fifo,n);
	FifoConsumerThread fct = FifoConsumerThread(fifo,n);
	return 0;
}
