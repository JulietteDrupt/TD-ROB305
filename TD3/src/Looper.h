#ifndef LOOPER_H
#define LOOPER_H
#include <cfloat>
#include <limits>

class Looper
{
	public :
		double runLoop(double nLoops=DBL_MAX);
		double getSample();
		double stopLoop();

	private :
		bool doStop;
		volatile double iLoop;
};

#endif
