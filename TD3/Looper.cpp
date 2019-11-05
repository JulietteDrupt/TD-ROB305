#include "Looper.h"
#include <climits>

double Looper::runLoop(double nLoops=DBL_MAX)
{
	this -> iLoop = 0.0;
	while (this -> iLoop < nLoops && not (this -> doStop))
	{
		this -> iLoop += 1.0;
	}
	return this -> iLoop;
}

double Looper::getSample()
{
	return this -> iLoop;
}

double Looper::stopLoop()
{
	this -> doStop = true;
	return this -> iLoop;
}

