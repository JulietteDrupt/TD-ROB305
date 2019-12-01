/*!
 * \file SemProducerThread.cpp
 * \brief SemProducerThread class implementation
 * \author Juliette DRUPT
 */

#include "SemProducerThread.h"
#include <iostream>
using namespace std;

SemProducerThread::SemProducerThread(Semaphore& sem) : Thread(), sem(sem)
{}

SemProducerThread::~SemProducerThread()
{}

void SemProducerThread::run()
{
	cout << "Giving !" << endl;
	(this -> sem).give();
}
