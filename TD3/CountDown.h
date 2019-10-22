#ifndef COUNT_DOWN_H
#define COUNT_DOWN_H

#include "PeriodicTimer.h"

class CountDown : public PeriodicTimer
{

	protected :
		void callback();
};

#endif
