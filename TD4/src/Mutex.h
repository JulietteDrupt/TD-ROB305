/*!
 * \file Mutex.h
 * \brief Encapsulation of the functionalities of a posix mutex.
 * \author Juliette DRUPT
 */

#ifndef MUTEX_H
#define MUTEX_H

#include <signal.h>

class Mutex
{
	public :
		class Lock;
		class TryLock;
		class Monitor;
		Mutex();
		~Mutex();

	private :
		pthread_mutex_t posixId;
		pthread_cond_t posixCondId;
		void lock();
		bool lock(double timeout_ms);
		bool trylock();
		void unlock();
};

class Mutex::Monitor
{
	public :
		class TimeoutException;
		void wait();
		bool wait(double timeout_ms);
		void notify();
		void notifyAll();
		Mutex& mutex;

	protected :
		Monitor(Mutex& m);

};

class Mutex::Monitor::TimeoutException
{
	virtual const char* what() const throw()
	{
		return "Timeout exception";
	}
};

class Mutex::Lock : public Mutex::Monitor
{
	public :
		Lock(Mutex& m);
		Lock(Mutex& m, double timeout_ms);
		~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
	public :
		TryLock(Mutex& m);
		~TryLock();
};

#endif
