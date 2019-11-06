#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "PeriodicTimer.h"
#include "Looper.h"
#include <vector>

class Calibrator : public PeriodicTimer
{
	public :
		Calibrator(double samplingPeriod_ms, unsigned int nSamples);
		double nLoops(double duration);
		int getA();
		int getB();
		Looper looper;

	protected :
		void callback();

	private :
		double a;
		double b;
		std::vector<double> samples;
};

#endif
