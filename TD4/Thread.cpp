#include "Thread.h"
#include "../TimeSpec.h"
#include <time.h>
#include <pthread.h>
#include <iostream>
using namespace std;

Thread::Thread() : PosixThread()
{}


Thread::~Thread()
{}

void Thread::start()
{
	//cout << "timespec now" << endl;
	this -> startTime = timespec_now();
	//cout << "start PosixThread" << endl;
	PosixThread::start(this -> call_run, (void*) this);
	//cout << "sleep" << endl;
	//Thread::sleep_ms(300.0);
	//cout << "slept";
	this -> stopTime = timespec_now();
}

void* Thread::call_run(void* v_thread)
{
	Thread *t = (Thread *) v_thread;
	t -> run();
	return v_thread;
}


void Thread::sleep_ms(double delay_ms)
{
//Problème avec la fonction wait de TimeSpec : pk ?
	timespec delay_ts = timespec_from_ms(delay_ms);
	timespec_wait(delay_ts);

	cout << "sleeping ?" << endl;
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

