#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "PeriodicTimer.h"

class Calibrator : public PeriodicTimer
{
	public :
		Calibrator(double samplingPeriod_ms, unsigned int nSamples);
		double nLoops(double duration);
		int getA();
		int getB();

	protected :
		void callback();

	private :
		double a;
		double b;	
};

#endif
