#include "Looper.h"
#include <cfloat>
#include <limits>
#include <iostream>
using namespace std;

double Looper::runLoop(double nLoops)
{
	this -> iLoop = 0.0;

	while (this -> iLoop < nLoops && not (this -> doStop))
	{
		this -> iLoop += 1.0;
		//cout << this -> iLoop << endl;
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

