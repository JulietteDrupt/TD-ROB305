#include "Calibrator.h"
#include "Looper.h"
#include <signal.h>
#include <vector>
#include <iostream>
using namespace std;

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples) : PeriodicTimer()
{
	// On crée un timer de period samplingPeriod_ms qui va utiliser le callback pour déterminer le nombre de boucles effectuées entre le début (t=0) et le moment d'échantillonage. Ces valeurs sont stockées dans samples. On fait ensuite une régression linéaire pour trouver a et b.
	Looper looper;
	this -> nSamples = nSamples;
	this -> start(samplingPeriod_ms);
	(this -> looper).runLoop();


	while ((this -> samples).size() < nSamples)
	{
		continue;
	}

	this -> stop();

	// Régression linéaire :

	double sumx = (double) nSamples * (nSamples + 1) / 2 * samplingPeriod_ms ;
	double sumy=0;
	double sumxx = (double) nSamples * (nSamples + 1) * (2 * nSamples + 1) / 6 * samplingPeriod_ms * samplingPeriod_ms ;
	double sumxy = 0;

	for (int i=0; i< nSamples; i++)
	{
		sumy += this -> samples[i];
		sumxy += this -> samples[i] * (i + 1) * samplingPeriod_ms;
	}

	this -> b = (double) (nSamples * sumxy - sumx * sumy) / (nSamples * sumxx - sumx * sumx);
	this -> a = sumy / nSamples - (this -> b) * sumx / nSamples;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//cout << "test : " << a * samplingPeriod_ms + b << endl;
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

