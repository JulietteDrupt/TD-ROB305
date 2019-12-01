/*!
 * \file PeriodicTimer.cpp
 * \brief PeriodicTimer class implementation
 * \author Juliette DRUPT
 */

#include "PeriodicTimer.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;

void PeriodicTimer::start(double duration_ms)
{

	cout << "Starting timer" << endl;

	itimerspec its;
	its.it_value = timespec_from_ms(duration_ms);
	its.it_interval = timespec_from_ms(duration_ms);;

	timer_settime(this -> tid, 0, &its, NULL);

}
