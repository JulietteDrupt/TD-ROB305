#include "ConsumerThread.h"

ConsumerThread::ConsumerThread(Semaphore& sem) : Thread(), sem(sem)
{}

ConsumerThread::~ConsumerThread()
{}

void ConsumerThread::run()
{
	(this -> sem).take();
}

