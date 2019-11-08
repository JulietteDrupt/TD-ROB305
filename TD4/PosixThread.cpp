#include "PosixThread.h"
#include <signal.h>

PosixThread::PosixThread()
{
	// Initialize Posix attribute
	pthread_attr_init(this.posixAttr);
	pthread_attr_setinheritsched(this.posixAttr, PTHREAD_EXCPLICIT_SCHED);
}

PosixThead::PosixThread(pthread_p posixId)
{
	this -> posixId = posixId;
	pthread_attr_init(this.posixAttr);
	pthread_attr_setinheritsched(this.posixAttr, PTHREAD_EXCPLICIT_SCHED);
}


bool PosixThread::setScheduling(int schedPolicy, int priority)
{
	// Set policy
	pthread_attr_setschedpolicy(this.posixAttr, schedPolicy);
	// Set priority
	sched_param schedParams;
	schedParams.sched_priority = priority;
	pthread_attr_setschedparam(this.posixAttr, &schedParams);

	// Si le thread est déjà lancé, on va devoir modifier les params direct ds le thread avec pthread_setschedparam()
	if (this -> isActive())
	{
		pthread_setschedparam(this -> posixId, schedPolicy, &schedParam);
	}

	return true;
}

bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
	sched_param schedParams;

	// Si le thread est déjà lancé, on récupère ses paramètres directement
	if (this -> isActive())
	{
		pthread_getschedparam(this -> posixId, p_schedPolicy, &schedParams);
	}
	else
	{
		pthread_attr_setschedparam(this.posixAttr, &schedParams);
		pthread_attr_getschedpolicy(this.posixAttr, p_schedPolicy);
	}
	*p_priority = schedParams.sched_priority;

	return true;
}

bool PosixThread::isActive()
{
	sched_param schedParams;
	int* p_schedPolicy;
	return (pthread_getschedparam(this -> posixId, p_schedPolicy, &schedParams) == 0);	
}

