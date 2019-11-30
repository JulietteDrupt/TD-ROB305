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

double timespec_to_ms(const timespec& time_ts);
timespec timespec_from_ms(double time_ms);

timespec timespec_now();
timespec timespec_negate(const timespec& time_ts);

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

timespec timespec_wait(const timespec& delay_ts);

timespec  operator- (const timespec& time_ts);
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);
bool operator== (const timespec& time1_ts, const timespec& time2_ts);
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);
bool operator< (const timespec& time1_ts, const timespec& time2_ts);
bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif
