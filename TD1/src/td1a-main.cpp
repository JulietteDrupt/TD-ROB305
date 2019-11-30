/**
 * \file td1a-main.c
 * \brief Test programm for TimeSpec functions.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program tests all the functions that are defined in file TimeSpec.h and implement in file TimeSpec.cpp.
 *
 */

#include "TimeSpec.h"
#include <iostream>
using namespace std;


int main()
{
	// Test of timespec_now()
	timespec t = timespec_now();
	cout << "Current time t: " << t.tv_sec << "." << t.tv_nsec << endl;
	// Test of timespec_to_ms(const timespec& time_ts)
	double tms = timespec_to_ms(t);
	cout << "t from timespec to ms: " << tms << " ms" << endl;
	// Test of timespec_from_ms(double time_ms)
	timespec t2 = timespec_from_ms(tms);
	cout << "t from ms to timespec: " << t2.tv_sec << "." << t2.tv_nsec << endl;
	// Tes of timespec_negate(const timespec& time_ts)
	timespec t3 = timespec_negate(t2);
	cout << "Negative t: " << t3.tv_sec << "." << t3.tv_nsec << endl;
	// Test of timespec_add(const timespec& time1_ts, const timespec& time2_ts)
	timespec t4 = timespec_now();
	cout << "Current time t4: " << t4.tv_sec << "." << t4.tv_nsec << endl;
	timespec t5 = timespec_add(t3,t3);
	// Test of timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
	cout << "Adding t to t: " << t5.tv_sec << "." << t5.tv_nsec << " = t5" << endl;
	timespec t6 = timespec_subtract(t4,t3);
	cout << "Subtracting t to t4: " << t6.tv_sec << "." << t6.tv_nsec << " = t6" << endl;
	// Test of + operator
	timespec t7 = t + t6;
	cout << "t + t6 = " << t7.tv_sec << "." << t7.tv_nsec << " = t7" << endl;
	// Test of - operator
	timespec t8 = t - t6;
	cout << "t - t6 = " << t8.tv_sec << "." << t8.tv_nsec << " = t8" << endl;
	// Test of += operator
	t8 += t7;
	cout << "t8 += t7: " << t8.tv_sec << "." << t8.tv_nsec << endl;
	// Test of -= operator
	t8 -= t7;
	cout << "t8 -= t7: " << t8.tv_sec << "." << t8.tv_nsec << endl;
	// Test of == operator
	cout << "t5 == t8: " << (t5 == t8) << endl;
	//Test of < operator
	cout << "t5 < t8: " << (t5 < t8) << endl;
	// Test of > operator
	cout << "t5 > t8: " << (t5 > t8) << endl;

	timespec t9 = timespec_from_ms(10e3);
	cout << "Waiting for 10 seconds" << endl;
	timespec_wait(t9);
	cout << "ok!" << endl;

	timespec t11 = - t9;
	cout << "t11 = - t9: " << t11.tv_sec << "." << t11.tv_nsec << " (t9 corresponding to 10 second)" << endl;

	return 0;
}
