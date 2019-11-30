/**
 * \file td1c-main.c
 * \brief Increments of a counter by executing a loop a given number of times.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program increments the value of a counter by executing a loop a given number of times. The counter starts at 0.0. The number of loops is given in argument to the programm. The value of the counter and the duration of the incrementation are displayed at the end of the programm.
 *
 */

#include <time.h>
#include <iostream>
#include <string>
#include "TimeSpec.h"
using namespace std;

/**
 * \fn void incr(unsigned int nLoops, volatile double* pCounter)
 * \brief Adds 1.0 to a counter at each iteration of a loop.
 *
 * \param nLoops Number of loop iterations to run.
 * \param pCounter Pointer to the counter to be incremented.
 */
void incr(unsigned int nLoops, volatile double* pCounter)
{
	for (unsigned i=0; i<nLoops; i++)
	{
		*pCounter += 1.0;
	}
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		unsigned int nLoops = stoi(argv[1]);
		volatile double counter = 0.0;

		timespec time_begin = timespec_now();
		incr(nLoops, &counter);
		timespec time_end = timespec_now();

		// Computes the duration of the execution of incr function.
		timespec duration_ts = time_end - time_begin;
		double duration_s = timespec_to_ms(duration_ts) / 1e3;
		cout << "Counter: " << counter << endl;
		cout << "Duration : " << duration_s << " s" << endl;
	}
	else
	{
		cout << "Uncorrect number of arguments. 1 expected." << endl;
	}

	return 0;
}
