/**
 * \file td2b-main.cpp
 * \brief Measures the execution time of a multithread execution.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program runs increment function (similar to the one of TD1 c and d) on several threads without mutex, and measures the execution time. The number of loops, the number of threads and the scheduling (SCHED_RR, SCHED_FIFO or SCHED_OTHER ) to use are given in argument.
 *
 */

#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>
#include "TimeSpec.h"
using namespace std;

/**
 * \struct Data
 * \brief Object with 2 parameters : a number of loops and a counter.
 *
 */
struct Data
{
	volatile unsigned int nLoops; /*!< Number of loops. */
	volatile double counter; /*!< Counter. */
};

/**
 * \fn void incr(unsigned int nLoops, volatile double* pCounter)
 * \brief Adds 1.0 to a counter at each iteration of a loop.
 *
 * \param nLoops Number of loop iterations to run.
 * \param pCounter Pointer to the counter to be incremented.
 */
void incr(volatile unsigned int nLoops, volatile double* pCounter)
{
	for (unsigned int i=0; i<nLoops; i++)
	{
		*pCounter += 1.0;
	}
}

/**
 * \fn void* call_incr(void* v_data)
 * \brief Calls incr function.
 *
 * \param v_data Pointer void* to a Data struct that contains the parameters used by function incr.
 * \return Updated v_data.
 */
void* call_incr(void* v_data)
{
	Data* p_data = (Data*) v_data;
	incr(p_data -> nLoops, &p_data -> counter);
	return v_data;
}


int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		unsigned int nLoops = stoi(argv[1]);
		unsigned int nTasks = stoi(argv[2]);
		int schedPolicy = atoi(argv[3]);

		// Sets scheduling
		struct sched_param schedParam;
		schedParam.sched_priority = sched_get_priority_max(schedPolicy);
		pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
		pthread_attr_setschedpolicy(&attr, schedPolicy);
		sched_param schedParams;
		schedParams.sched_priority = 9;
		pthread_attr_setschedparam(&attr, &schedParams);

		Data data = {nLoops, 0.0};

		// Creates nTasks threads
		pthread_t incrementThread[nTasks];

		timespec time_begin = timespec_now();

		for (unsigned int i=0;i<nTasks;i++)
		{
			pthread_create(&incrementThread[i], &attr, call_incr, (void*)&data);
		}
		pthread_attr_destroy(&attr);

		// Join threads
		for (unsigned int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

		timespec time_end = timespec_now();

		// Computes execution duration
		timespec duration_ts = time_end - time_begin;
		double duration_s = timespec_to_ms(duration_ts) / 1e3;
		// Display execution duration and counter's final value
		cout << "Duration : " << duration_s << " s" << endl;

		cout << "Counter value: " << data.counter << endl;
	}
	else
	{
		cout << "Uncorrect number of arguments. 3 expected." << endl;
	}

	return 0;
}
