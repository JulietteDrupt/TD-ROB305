/*!
 * \file IncrementThreadWithMutex.cpp
 * \brief IncrementThreadWithMutex class implementation
 * \author Juliette DRUPT
 */

#include "IncrementThreadWithMutex.h"
#include <iostream>
using namespace std;

IncrementThreadWithMutex::IncrementThreadWithMutex(Data* data, Mutex& mutex) : IncrementThread(data), mutex(mutex)
{}

IncrementThreadWithMutex::~IncrementThreadWithMutex()
{}

void IncrementThreadWithMutex::run()
{
	for (unsigned int i=0; i < (this -> data) -> nLoops; i++)
	{
		Mutex::Lock l = Mutex::Lock(mutex);
		(this -> data) -> counter += 1.0;
		l.~Lock();
	}
}
