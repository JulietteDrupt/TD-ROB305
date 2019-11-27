#include "ProductorThread.h"
#include <iostream>
using namespace std;

ProductorThread::ProductorThread(Semaphore& sem) : Thread(), sem(sem)
{}

ProductorThread::~ProductorThread()
{}

void ProductorThread::run()
{
	cout << "Giving !" << endl;
	(this -> sem).give();
}

