#include "Mutex.h"
#include "../Timespec.h"
#include <pthread.h>

Mutex::Mutex()
{
	pthread_mutexattr_t mutexAttribute,
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
	pthread_mutex_timedlock(&(this -> posixId), timeout_ts);

	return true;
}


bool Mutex::trylock()
{
	try
	{
		pthread_mutex_lock(&(this -> posixId));
	} catch (Mutex::Monitor::TimeoutException e)
	{
		throw(e);
		return false;
	}
	return true;
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&(this -> posixId));
}



Mutex::Monitor::Monitor(Mutex& m) : mutex(m){}
{}

void Mutex::Monitor::wait()
{
	while (true)
	{
		pthread_cond_wait(&(this -> posixCondId), &(this -> posixId));
	}
}


bool Mutex::Monitor::wait(double timeout_ms)
{
	bool ok = true;
	timespec timeout_ts = timespec_from_ms(timeout_ms);
	while (ok)
	{
		pthread_cond_timedwait(&(this -> posixCondId), &(this -> posixId), &timeout_ts);
	}
	return ok;
}


void Mutex::Monitor::notify()
{
	pthread_cond_signal(&(this -> posixCondId));
}


void Mutex::Monitor::notifyAll()
{
	pthread_cond_broadcast(&(this -> posixCondId));
}


