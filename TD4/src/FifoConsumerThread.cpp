/*!
 * \file FifoConsumerThread.cpp
 * \brief FifoConsumerThread class implementation
 * \author Juliette DRUPT
 */

#include "FifoConsumerThread.h"
#include <iostream>
using namespace std;

FifoConsumerThread::FifoConsumerThread(Fifo<int>& fifo, int n) : Thread(), fifo(fifo), n(n)
{}

FifoConsumerThread::~FifoConsumerThread()
{}

void FifoConsumerThread::run()
{
	for (int i = 0; i < (this -> n); i++)
	{
		cout << (this -> fifo).pop() << endl;
	}
}
