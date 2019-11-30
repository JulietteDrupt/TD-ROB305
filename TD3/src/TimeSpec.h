/**
 * \file TimeSpec.h
 * \brief Fonctions and operators to use timespec structures a simpler way.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This file defines the fonctions and operators implemented in TimeSpec.cpp, that allow to use timespec structres a simpler way.
 *
 */

#ifndef TimeSpec_h_INCLUDED
#define TimeSpec_h_INCLUDED

#include <time.h>

/**
 * \fn double timespec_to_ms(const timespec& time_ts)
 * \brief Converts a timespec structure to its double value in microseconds.
 *
 * \param time_ts Time to convert.
 * \return Time value in microseconds.
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * \fn timespec timespec_from_ms(double time_ms)
 * \brief Converts a double time value in microseconds to a timespec structure.
 *
 * \param time_ms Time to convert.
 * \return Time value as a timespec structure.
 */
timespec timespec_from_ms(double time_ms);

/**
 * \fn timespec timespec_now()
 * \brief Gets current time.
 *
 * \return Current time value as a timespec structure.
 */
timespec timespec_now();

/**
 * \fn timespec timespec_negate(const timespec& time_ts)
 * \brief Computes the opposite value of a time expressed as a timespec structure.
 *
 * \param time_ts Time to compute the opposite of.
 * \return Opposite time value as a timespec structure.
 */
timespec timespec_negate(const timespec& time_ts);

/**
 * \fn timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
 * \brief Computes the sum of two values of time expressed as timespec structures.
 *
 * \param time1_ts One of the two times to be summed.
 * \param time1_ts The other of the two times to be summed.
 * \return Sum of the time values as a timespec structure.
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
 * \brief Computes the difference between two values of time expressed as timespec structures.
 *
 * \param time1_ts Initial time value.
 * \param time1_ts Time value to be subtracted from the initial time value.
 * \return Difference between the time values as a timespec structure.
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn timespec timespec_wait(const timespec& delay_ts)
 * \brief Puts the calling thread to sleep for a given duration expressed as a timespec structure.
 *
 * \param delay_ts Sleep duration.
 * \return The difference between the time the thread was supposed to sleep and the time it really slept.
 */
timespec timespec_wait(const timespec& delay_ts);

/**
 * \fn timespec operator- (const timespec& time_ts)
 * \brief Defines operator - for negating timespec structures.
 *
 * \param delay_ts Time to be negated.
 * \return The negated time value.
 */
timespec  operator- (const timespec& time_ts);

/**
 * \fn timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator + for timespec structures.
 *
 * \param time1_ts First time in the addition.
 * \param time2_ts Second time in the addition.
 * \return The sum of the two time values.
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator - for timespec structures.
 *
 * \param time1_ts First time in the subtraction.
 * \param time2_ts Second time in the subtraction.
 * \return The difference between the two time values.
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
 * \brief Defines operator += for timespec structures.
 *
 * \param time_ts Initial time value.
 * \param delay_ts Time value to add to the initial one.
 * \return The new value of time_ts.
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

/**
 * \fn timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
 * \brief Defines operator -= for timespec structures.
 *
 * \param time_ts Initial time value.
 * \param delay_ts Time value to subtract to the initial one.
 * \return The new value of time_ts.
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

/**
 * \fn bool operator== (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator == for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the two time values are equal, false otherwise.
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator != for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return false if the two time values are equal, true otherwise.
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn bool operator< (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator < for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the first time is strictly inferior to the second one, false otherwise.
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

/**
 * \fn bool operator> (const timespec& time1_ts, const timespec& time2_ts)
 * \brief Defines operator > for timespec structures.
 *
 * \param time1_ts First time in the comparison.
 * \param time2_ts Second time in the comparison.
 * \return true if the first time is strictly superior to the second one, false otherwise.
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif
