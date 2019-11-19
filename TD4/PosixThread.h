#ifndef POSIX_THREAD_H
#define PPSIX_THREAD_H

#include <signal.h>
#include <exception>
#include <string>
#include <iostream>
using namespace std;

class PosixThread
{
	public :
		PosixThread();
		PosixThread(pthread_t posixId);
		~PosixThread();

		void start(void* (*threadFunc)(void*), void* threadArg);
		void join();
		bool join(double timeout_ms);
		bool setScheduling(int schedPolicy, int priority);
		bool getScheduling(int* p_schedPolicy = nullptr, int* p_priority = nullptr);

		class Exception;

	protected :
		bool isActive;		

	private :
		pthread_t posixId;
		pthread_attr_t posixAttr;

};

class PosixThread::Exception : public exception
{
	public :
		Exception(const string& msg);
		const char* what() const noexcept override
		{
			return _msg.c_str();
		};
	private :
		string _msg;
		
};

#endif
