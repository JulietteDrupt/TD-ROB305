#include "ConsumerThread.h"

ConsumerThread::ConsumerThread(Semaphore& sem) : Thread(), sem(sem)
{}

ConsumerThread::~ConsumerThread()
{}

void IncrementThread::run()
{
	(this -> sem).take();
}

