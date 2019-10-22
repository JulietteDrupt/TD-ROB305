#include "Chrono.h"
#include "TimeSpec.h"
#include <time.h>

Chrono::Chrono()
{
	this -> startTime_ = timespec_now();
	this -> stopTime_ = timespec_now();
	this -> active = true;
}

void Chrono::stop()
{
	this -> stopTime_ = timespec_now();
	this -> active = false;
}

void Chrono::restart()
{
	this -> startTime_ = timespec_now();
	this -> active = true;
}

bool Chrono::isActive()
{
	return this -> active;
}

double Chrono::startTime()
{
	return timespec_to_ms(this -> startTime_);
}

double Chrono::stopTime()
{
	return timespec_to_ms(this -> stopTime_);
}

double Chrono::lap()
{
	double lap;
	if (this -> active)
	{
		timespec current_time = timespec_now();
		lap = timespec_to_ms(current_time - this -> startTime_);
	}
	else
	{
		lap = timespec_to_ms(this -> stopTime_ - this -> startTime_);
	}
	return lap;
}
