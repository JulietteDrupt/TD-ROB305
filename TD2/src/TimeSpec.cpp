/**
 * \file TimeSpec.cpp
 * \brief Fonctions and operators to use timespec structures a simpler way.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This file implements the fonctions and operators defined in TimeSpec.h, that allow to use timespec structres a simpler way.
 *
 */

#include "TimeSpec.h"
#include <math.h>
#include <iostream>
using namespace std;

/**
 * \fn double timespec_to_ms(const timespec& time_ts)
 * \brief Converts a timespec structure to its double value in microseconds.
 *
 * \param time_ts Time to convert.
 * \return Time value in microseconds.
 */
double timespec_to_ms(const timespec& time_ts)
{
	double time_ms = time_ts.tv_sec * 1e3 + time_ts.tv_nsec / 1e6;
	return time_ms;
}

/**
 * \fn timespec timespec_from_ms(double time_ms)
 * \brief Converts a double time value in microseconds to a timespec structure.
 *
 * \param time_ms Time to convert.
 * \return Time value as a timespec structure.
 */
timespec timespec_from_ms(double time_ms)
{
	struct timespec time_ts;
	time_ts.tv_sec = (long) (time_ms / 1e3);
	time_ts.tv_nsec = (time_ms / 1e3 - time_ts.tv_sec) * 1e9;
	return time_ts;
}

/**
 * \fn timespec timespec_now()
 * \brief Gets current time.
 *
 * \return Current time value as a timespec structure.
 */
timespec timespec_now()
{
	struct timespec time_ts_now;
	clock_gettime(CLOCK_REALTIME, &time_ts_now);
	return time_ts_now;
}

/**
 * \fn timespec timespec_negate(const timespec& time_ts)
 * \brief Computes the opposite value of a time expressed as a timespec structure.
 *
 * \param time_ts Time to compute the opposite of.
 * \return Opposite time value as a timespec structure.
 */
timespec timespec_negate(const timespec& time_ts)
{
	struct timespec time_ts_neg;
	time_ts_neg.tv_sec = - time_ts.tv_sec;
	if (time_ts.tv_nsec != 0)
	{
		time_ts_neg.tv_sec -= 1;
		time_ts_neg.tv_nsec = 1e9 - time_ts.tv_nsec;
	}
	else
	{
		time_ts_neg.tv_nsec = 0;
	}
	return time_ts_neg;
}

/**
 * \fn timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
 * \brief Computes the sum of two values of time expressed as timespec structures.
 *
 * \param time1_ts One of the two times to be summed.
 * \param time1_ts The other of the two times to be summed.
 * \return Sum of the time values as a timespec structure.
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
	struct timespec time_ts_sum;
	time_ts_sum.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
	time_ts_sum.tv_sec += (time1_ts.tv_nsec + time2_ts.tv_nsec) / 1e9;
	if (time1_ts.tv_nsec + time2_ts.tv_nsec < 1e9)
	{
		time_ts_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
	}
	else
	{
		time_ts_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec - 1e9;
	}
	return time_ts_sum;
}

/**
 * \fn timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
 * \brief Computes the difference between two values of time expressed as timespec structures.
 *
 * \param time1_ts Initial time value.
 * \param time1_ts Time value to be subtracted from the initial time value.
 * \return Difference between the time values as a timespec structure.
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
	struct timespec time_ts_dif;
	time_ts_dif.tv_sec = time1_ts.tv_sec - time2_ts.tv_sec;
	if (time1_ts.tv_nsec < time2_ts.tv_nsec)
	{
		time_ts_dif.tv_sec -= 1;
		time_ts_dif.tv_nsec = time1_ts.tv_nsec + 1e9 - time2_ts.tv_nsec;
	}
        else
        {
		time_ts_dif.tv_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;
	}
	return time_ts_dif;
}

/**
 * \fn timespec timespec_wait(const timespec& delay_ts)
 * \brief Puts the calling thread to sleep for a given duration expressed as a timespec structure.
 *
 * \param delay_ts Sleep duration.
 * \return The difference between the time the thread was supposed to sleep and the time it really slept.
 */
timespec timespec_wait(const timespec& delay_ts)
{
	struct timespec time_ts_remaining;
	//cout << "Gonna wait" << endl;
	int test = nanosleep(&delay_ts, &time_ts_remaining);
	//cout << "Gonna wait" << endl;
	while (test != 0)
	{
		test = nanosleep(&time_ts_remaining,&time_ts_remaining);
	}
	return time_ts_remaining;
}

/**
 * \fn timespec operator- (const timespec& time_ts)
 * \brief Defines operator - for negating timespec structures.
 *
 * \param delay_ts Time to be negated.
 * \return The negated time value.
 */
timespec operator- (const timespec& time_ts)
{
	timespec time_res = timespec_negate(time_ts);
	return time_res;
}

/**
 * \fn timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator + for timespec structures.
 *
 * \param time1_ts First time in the addition.
 * \param time2_ts Second time in the addition.
 * \return The sum of the two time values.
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_res = timespec_add(time1_ts, time2_ts);
	return time_res;
}

/**
 * \fn timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator - for timespec structures.
 *
 * \param time1_ts First time in the subtraction.
 * \param time2_ts Second time in the subtraction.
 * \return The difference between the two time values.
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_res = timespec_subtract(time1_ts, time2_ts);
	return time_res;
}

/**
 * \fn timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
 * \brief Defines operator += for timespec structures.
 *
 * \param time_ts Initial time value.
 * \param delay_ts Time value to add to the initial one.
 * \return The new value of time_ts.
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_add(time_ts, delay_ts);
	return time_ts;
}

/**
 * \fn timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
 * \brief Defines operator -= for timespec structures.
 *
 * \param time_ts Initial time value.
 * \param delay_ts Time value to subtract to the initial one.
 * \return The new value of time_ts.
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_subtract(time_ts, delay_ts);
	return time_ts;
}

/**
 * \fn bool operator== (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator == for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the two time values are equal, false otherwise.
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
	return (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}

/**
 * \fn bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator != for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return false if the two time values are equal, true otherwise.
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
	return !(time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}

/**
 * \fn bool operator< (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator < for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the first time is strictly inferior to the second one, false otherwise.
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_dif = timespec_subtract(time1_ts, time2_ts);
	double time_dif_ms = timespec_to_ms(time_dif);
	return (time_dif_ms < 0);
}

/**
 * \fn bool operator> (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator > for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the first time is strictly superior to the second one, false otherwise.
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_dif = timespec_subtract(time1_ts, time2_ts);
	double time_dif_ms = timespec_to_ms(time_dif);
	return (time_dif_ms > 0);
}
