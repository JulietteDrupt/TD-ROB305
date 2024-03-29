/*!
 * \file Semaphore.cpp
 * \brief Semaphore class implementation
 * \author Juliette DRUPT
 */

#include "Semaphore.h"
#include "Mutex.h"
#include <pthread.h>
#include <iostream>
using namespace std;

Semaphore::Semaphore(unsigned int initCount, unsigned int maxCount) : counter(initCount), maxCount(maxCount)
{}

void Semaphore::give()
{
	if (this -> counter == 0)
	{
		Mutex::TryLock mtl = Mutex::TryLock(this -> mutex);
		mtl.notify();
		mtl.~TryLock();
	}
	if (this -> counter < maxCount)
	{
		this -> counter += 1;
	}
}

void Semaphore::take()
{
	if (counter == 0)
	{
		// si le compteur de jetons est à zéro, appel bloquant
		Mutex::Lock ml = Mutex::Lock(this -> mutex);
		ml.wait();
		ml.~Lock();
	}
	else
	{
		this -> counter -= 1;
	}
}

bool Semaphore::take(double timeout_ms)
{
	bool val = true;

	if (counter == 0)
	{
		// si le compteur de jetons est à zéro, appel bloquant
		Mutex::Lock ml = Mutex::Lock(this -> mutex);
		val = ml.wait(timeout_ms);
		ml.~Lock();
	}

	else
	{
		this -> counter -= 1;
	}

	return val;
}
