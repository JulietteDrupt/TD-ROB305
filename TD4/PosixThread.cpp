#include "PosixThread.h"
#include "../TimeSpec.h"
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <iostream>
using namespace std;

PosixThread::PosixThread()
{
	cout << "Creating PosixThread" << endl;

	// Initialize Posix attribute
	pthread_attr_init(&(this -> posixAttr));
	pthread_attr_setinheritsched(&(this -> posixAttr), PTHREAD_EXPLICIT_SCHED);
	this -> isActive = false;
}


PosixThread::PosixThread(pthread_t posixId)
{
	if (posixId != '\0')
	{
		cout << "Creating PosixThread" << endl;

		sched_param schedParams;
		int p_schedPolicy = SCHED_RR;
		int test = (pthread_getschedparam(this -> posixId, &p_schedPolicy, &schedParams) == 0);
		if (test != ESRCH)
		{
			this -> posixId = posixId;
			this -> isActive = true;
		}
	}
	else
	{
		throw(Exception("pb"));
	}
}


PosixThread::~PosixThread()
{
	cout << "Destructing PosixThread" << endl;
	pthread_attr_destroy(&(this -> posixAttr));
	/*pthread_join(this->posixId,NULL);
    delete &this->posixAttr;
    delete &this->posixId;*/
	
}


bool PosixThread::setScheduling(int schedPolicy, int priority)
{

	// Set policy
	pthread_attr_setschedpolicy(&(this -> posixAttr), schedPolicy);
	// Set priority
	sched_param schedParams;
	schedParams.sched_priority = priority;
	pthread_attr_setschedparam(&(this -> posixAttr), &schedParams);

	// Si le thread est déjà lancé, on va devoir modifier les params direct ds le thread avec pthread_setschedparam()
	if (isActive)
	{
		pthread_setschedparam(this -> posixId, schedPolicy, &schedParams);
	}

	return isActive;
}

bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{

	sched_param schedParams;

	// Si le thread est déjà lancé, on récupère ses paramètres directement
	if (isActive)
	{
		pthread_getschedparam(this -> posixId, p_schedPolicy, &schedParams);
	}
	else
	{
		pthread_attr_setschedparam(&(this -> posixAttr), &schedParams);
		pthread_attr_getschedpolicy(&(this -> posixAttr), p_schedPolicy);
	}
	*p_priority = schedParams.sched_priority;

	return isActive;
}



void PosixThread::start(void* (*threadFunc)(void*), void* threadArg)
{
	pthread_create(&(this -> posixId), &(this -> posixAttr), threadFunc, threadArg);
}

void PosixThread::join()
{
	pthread_join(this -> posixId, NULL);
}

bool PosixThread::join(double timeout_ms)
{
	timespec t = timespec_from_ms(timeout_ms);
	return pthread_timedjoin_np((this -> posixId), NULL, &t);
}

PosixThread::Exception::Exception(const string& msg)
{
	this -> _msg = msg;
}

