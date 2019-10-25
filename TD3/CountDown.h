#ifndef COUNT_DOWN_H
#define COUNT_DOWN_H

#include "PeriodicTimer.h"

class CountDown : public PeriodicTimer
{
	public :
		CountDown(int n);
		volatile int n;

	protected :
		void callback();
};

#endif
