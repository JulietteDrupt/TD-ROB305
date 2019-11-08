#ifndef POSIX_THREAD_H
#define PPSIX_THREAD_H

#include <signal.h>
#include <iostream>
using namespace std;

class PosixThread
{
	public :
		PosixThread();
		PosixThead(pthread_t posixId);
		~PosixThread();

		void start(void* (*threadFunc)(void*), void* threadArg);
		void join();
		bool join(double timeout_ms);
		bool setScheduling(int schedPolicy, int priority);
		bool getScheduling(int* p_schedPolicy = nullptr, int* p_priority = nullptr);

		bool isActive();

		class Exception;
		

	private :
		pthread_t posixId;
		pthread_attr_t posixAttr;
		
};

class PosixThread::Exception
{};

#endif
