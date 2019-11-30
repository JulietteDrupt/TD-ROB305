/*!
 * \file Chrono.cpp
 * \brief Chrono class implementation
 * \author Juliette DRUPT
 */

#include "Chrono.h"
#include "TimeSpec.h"
#include <time.h>

Chrono::Chrono() : start_time(timespec_now()), stop_time(timespec_now()), active(true)
{}

void Chrono::stop()
{
	this -> stop_time = timespec_now();
	this -> active = false;
}

void Chrono::restart()
{
	this -> start_time = timespec_now();
	this -> active = true;
}

bool Chrono::isActive()
{
	return this -> active;
}

double Chrono::startTime()
{
	return timespec_to_ms(this -> start_time);
}

double Chrono::stopTime()
{
	return timespec_to_ms(this -> stop_time);
}

double Chrono::lap()
{
	double lap;
	if (this -> active)
	{
		timespec current_time = timespec_now();
		lap = timespec_to_ms(current_time - this -> start_time);
	}
	else
	{
		lap = timespec_to_ms(this -> stop_time - this -> start_time);
	}
	return lap;
}
