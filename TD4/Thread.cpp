#include "Thread.h"
#include "TimeSpec.h"

Thread::Thread() : PosixThread()
{}


Thread::~Thread()
{
	pthread_attr_destroy(&(this -> posixAttr));
}

void Thread::start()
{
	this -> startTime = timespec_now();
	PosixThread::start(this -> call_run, (void*) this);
	this -> sleep_ms(3e3);
	this -> stopTime = timespec_now();
}

void* Thread::call_run(void* v_thread)
{
	Thread *t = (Thread *) v_thread;
	t -> run();
}


void Thread::sleep_ms(double delay_ms)
{
	timespec_wait(timespec_from_ms(delay_ms));
}


double Thread::startTime_ms()
{
	return timespec_to_ms(this -> startTime);
}


double Thread::stopTime_ms()
{
	return timespec_to_ms(this -> stopTime);
}


double Thread::execTime_ms()
{
	return timespec_to_ms(this -> stopTime - this -> startTime);
}

