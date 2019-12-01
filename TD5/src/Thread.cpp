/*!
 * \file Thread.cpp
 * \brief Thread class implementation
 * \author Juliette DRUPT
 */

#include "Thread.h"
#include "TimeSpec.h"
#include <time.h>
#include <pthread.h>
#include <iostream>
using namespace std;

bool Thread::started = false;

Thread::Thread() : PosixThread()
{}


Thread::~Thread()
{}

bool Thread::start()
{
	bool s = this -> started;
	this -> startTime = timespec_now();
	PosixThread::start(this -> call_run, (void*) this);
	this -> stopTime = timespec_now();
	this -> started = true;
	return !s;
}

void* Thread::call_run(void* v_thread)
{
	Thread *t = (Thread *) v_thread;
	t -> run();

	return v_thread;
}


void Thread::sleep_ms(double delay_ms)
{
	timespec delay_ts = timespec_from_ms(delay_ms);
	timespec_wait(delay_ts);
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
