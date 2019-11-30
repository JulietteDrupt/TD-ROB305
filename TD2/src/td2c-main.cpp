/**
 * \file td2c-main.c
 * \brief Runs function on several threads with mutex.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program runs increment function (similar to the one of TD1 c and d) on several threads with mutex. The number of loops and the number of threads to use are given in argument. A third argument "protected" can be specified : in this case, the incrementaion of counter will be protected by a mutex, otherwise it won't.
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
 * \brief Object with 4 parameters : a number of loops, a counter, a boolean protect that indicates wether the threads should use a mutex, and a mutex.
 *
 */
struct Data
{
	volatile unsigned int nLoops;
	volatile double counter;
	bool protect;
	pthread_mutex_t mutex;
};

/**
 * \fn void incr(unsigned int nLoops, volatile double* pCounter)
 * \brief Adds 1.0 to a counter at each iteration of a loop.
 *
 * \param p_data Pointer to Data struct.
 */
void incr(Data* p_data)
{

	for (unsigned int i=0; i < p_data -> nLoops; i++)
	{
		// If protected is true, uses the mutex
		if (p_data -> protect)
		{
			pthread_mutex_lock(&p_data -> mutex);
			p_data -> counter += 1.0;
			pthread_mutex_unlock(&p_data -> mutex);
		}
		else
		{
			p_data -> counter += 1.0;
		}

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

	incr(p_data);

	return v_data;
}


int main(int argc, char* argv[])
{
	if (argc == 4 || argc == 3)
	{
		unsigned int nLoops = stoi(argv[1]);
		unsigned int nTasks = stoi(argv[2]);
		bool protect = false;
		pthread_mutex_t mutex;

		// Set protected
		if (argc == 4)
		{
			string test = argv[3];
			if (test == "protected")
			{
				protect = true;
			}
		}

		Data data = {nLoops, 0.0, protect, mutex};
		if (protect)
		{
			// Initialize mutex
			pthread_mutex_init(&data.mutex, NULL);
		}

		// Create nTasks threads
		pthread_t incrementThread[nTasks];

		timespec time_begin = timespec_now();

		for (unsigned int i=0;i<nTasks;i++)
		{
			pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
		}

		// Join threads
		for (unsigned int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

		// Compute execution duration
		timespec time_end = timespec_now();
		timespec duration_ts = time_end - time_begin;
		double duration_s = timespec_to_ms(duration_ts) / 1e3;
		// Display execution duration
		cout << "Duration : " << duration_s << " s" << endl;

		if (protect)
		{
			// Destroy mutex
			pthread_mutex_destroy(&data.mutex);
		}

		// Display counter value
		cout << "Counter value: " << data.counter << endl;
	}
	else
	{
		cout << "Uncorrect number of arguments. 2 or 3 expected." << endl;
	}

	return 0;
}
