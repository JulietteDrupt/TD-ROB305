#include "ConsumerThread.h"
#include <iostream>
using namespace std;

ConsumerThread::ConsumerThread(Semaphore& sem) : Thread(), sem(sem)
{}

ConsumerThread::~ConsumerThread()
{}

void ConsumerThread::run()
{
	cout << "Taking !" << endl;
	(this -> sem).take();
}

