#include "SemProductorThread.h"
#include <iostream>
using namespace std;

SemProductorThread::SemProductorThread(Semaphore& sem) : Thread(), sem(sem)
{}

SemProductorThread::~SemProductorThread()
{}

void SemProductorThread::run()
{
	cout << "Giving !" << endl;
	(this -> sem).give();
}

