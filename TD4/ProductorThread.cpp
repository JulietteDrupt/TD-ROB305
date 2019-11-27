#include "ProductorThread.h"

ProductorThread::ProductorThread(Semaphore& sem) : Thread(), sem(sem)
{}

ProductorThread::~ProductorThread()
{}

void IncrementThread::run()
{
	(this -> sem).give();
}

