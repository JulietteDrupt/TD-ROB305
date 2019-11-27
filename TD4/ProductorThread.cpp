#include "ProductorThread.h"

ProductorThread::ProductorThread(Semaphore& sem) : Thread(), sem(sem)
{}

ProductorThread::~ProductorThread()
{}

void ProductorThread::run()
{
	(this -> sem).give();
}

