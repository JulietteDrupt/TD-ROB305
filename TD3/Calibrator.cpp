#include "Calibrator.h"
#include "Looper.h"
#include <signal.h>
#include <vector>

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples) : PeriodicTimer()
{
	// On crée un timer de period samplingPeriod_ms qui va utiliser le callback pour déterminer le nombre de boucles effectuées entre le début (t=0) et le moment d'échantillonage. Ces valeurs sont stockées dans samples. On fait ensuite une régression linéaire pour trouver a et b.
	Looper looper;
	(this -> looper).runLoop;
	this -> start(samplingPeriod_ms);
	while ((this -> samples).size < nSamples)
	{
		continue;
	}
	(this -> looper).stopLoop;
	this -> stop();
}

void Calibrator::callback()
{
	double sample = (this -> looper).getSample();
	(this -> samples).push_back(sample);
}

