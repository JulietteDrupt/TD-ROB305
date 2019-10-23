#include "PeriodicTimer.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;

void PeriodicTimer::start(double duration_ms)
{

	cout << "Starting timer" << endl;

	(this -> its).it_value = timespec_from_ms(duration_ms);
	(this -> its).it_interval = timespec_from_ms(duration_ms);
	timer_settime(this -> tid, 0, &(this -> its), NULL);

}

