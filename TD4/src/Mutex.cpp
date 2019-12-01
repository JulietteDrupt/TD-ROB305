/*!
 * \file Mutex.cpp
 * \brief Mutex class implementation
 * \author Juliette DRUPT
 */

#include "Mutex.h"
#include "TimeSpec.h"
#include <pthread.h>

Mutex::Mutex()
{
	pthread_mutexattr_t mutexAttribute;
	pthread_mutexattr_init(&mutexAttribute);
	pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&(this -> posixId), &mutexAttribute);
	pthread_cond_init(&(this -> posixCondId), NULL);
	pthread_mutexattr_destroy(&mutexAttribute);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&(this -> posixId));
	pthread_cond_destroy(&(this -> posixCondId));
}

void Mutex::lock()
{
	pthread_mutex_lock(&(this -> posixId));
}

bool Mutex::lock(double timeout_ms)
{
	timespec timeout_ts = timespec_from_ms(timeout_ms);
	int val = pthread_mutex_timedlock(&(this -> posixId), &timeout_ts);

	return (val == 0);
}


bool Mutex::trylock()
{
	int val = pthread_mutex_trylock(&(this -> posixId));
	return (val == 0);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&(this -> posixId));
}



Mutex::Monitor::Monitor(Mutex& m) : mutex(m){}

void Mutex::Monitor::wait()
{
	pthread_cond_wait(&((this -> mutex).posixCondId), &((this -> mutex).posixId));
}


bool Mutex::Monitor::wait(double timeout_ms)
{
	timespec timeout_ts = timespec_from_ms(timeout_ms);
	int val = pthread_cond_timedwait(&((this -> mutex).posixCondId), &((this -> mutex).posixId), &timeout_ts);

	return (val == 0);
}


void Mutex::Monitor::notify()
{
	pthread_cond_signal(&((this -> mutex).posixCondId));
}


void Mutex::Monitor::notifyAll()
{
	pthread_cond_broadcast(&((this -> mutex).posixCondId));
}


Mutex::Lock::Lock(Mutex& m) : Mutex::Monitor(m)
{
	(this -> mutex).lock();
}

Mutex::Lock::Lock(Mutex& m, double timeout_ms) : Mutex::Monitor(m)
{

	bool val = (this -> mutex).lock(timeout_ms);
	if (!val)
	{
		throw Mutex::Monitor::TimeoutException();
	}
}


Mutex::Lock::~Lock()
{
	(this -> mutex).unlock();
}


Mutex::TryLock::TryLock(Mutex& m) : Mutex::Monitor(m)
{
	bool val = (this -> mutex).trylock();
	if (!val)
	{
		throw Mutex::Monitor::TimeoutException();
	}
}


Mutex::TryLock::~TryLock()
{
	(this -> mutex).unlock();
}
