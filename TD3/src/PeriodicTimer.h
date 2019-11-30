#ifndef PERIODIC_TIMER_H
#define PERIODIC_TIMER_H

#include "Timer.h"

class PeriodicTimer : public Timer
{
	public :
		void start (double duration_ms);
};

#endif
