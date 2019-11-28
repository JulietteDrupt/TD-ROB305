#include "SemConsumerThread.h"
#include <iostream>
using namespace std;

SemConsumerThread::SemConsumerThread(Semaphore& sem) : Thread(), sem(sem)
{}

SemConsumerThread::~SemConsumerThread()
{}

void SemConsumerThread::run()
{
	cout << "Taking !" << endl;
	(this -> sem).take();
}

