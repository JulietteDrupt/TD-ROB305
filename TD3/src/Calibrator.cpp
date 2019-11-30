/*!
 * \file Calibrator.c
 * \brief Calibrator class implementation
 * \author Juliette DRUPT
 */

#include "Calibrator.h"
#include "Looper.h"
#include <signal.h>
#include <vector>
#include <iostream>
using namespace std;

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples) : PeriodicTimer(), nSamples(nSamples)
{
	Looper looper;
	this -> start(samplingPeriod_ms);
	(this -> looper).runLoop();


	while ((this -> samples).size() < nSamples)
	{
		continue;
	}

	this -> stop();

	// Linear regression

	long double sumx = nSamples * (nSamples + 1) / 2 * samplingPeriod_ms ;
	long double sumy=0;
	long double sumxx = nSamples * (nSamples + 1) * (2 * nSamples + 1) / 6 * samplingPeriod_ms * samplingPeriod_ms ;
	long double sumxy = 0;

	for (int i=0; i< nSamples; i++)
	{
		sumy += this -> samples[i];
		sumxy += this -> samples[i] * (i + 1) * samplingPeriod_ms;
	}

	this -> a = (double) (nSamples * sumxy - sumx * sumy) / (nSamples * sumxx - sumx * sumx);
	this -> b = (double) sumy / nSamples - (this -> a) * sumx / nSamples;

	cout << "a = " << this -> a << endl;
	cout << "b = " << this -> b << endl;
	cout << "test : " << this -> nLoops(samplingPeriod_ms) << endl;
}

void Calibrator::callback()
{
	double sample = (this -> looper).getSample();
	cout << "sample : " << sample << endl;
	(this -> samples).push_back(sample);

	if ((this -> samples).size() == this -> nSamples)
	{
		(this -> looper).stopLoop();
	}
}

int Calibrator::getA()
{
	return this -> a;
}

int Calibrator::getB()
{
	return this -> b;
}

double Calibrator::nLoops(double duration_ms)
{
	return ((this -> a) * duration_ms + (this -> b));
}
