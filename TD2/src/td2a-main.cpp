/**
 * \file td2a-main.cpp
 * \brief Runs function on several threads without mutex.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program runs increment function (similar to the one of TD1 c and d) on several threads without mutex. The number of loops and the number of threads to use are given in argument.
 *
 */

#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>
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
	for (unsigned i=0; i<nLoops; i++)
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
	if (argc == 3)
	{
		unsigned int nLoops = stoi(argv[1]);
		unsigned int nTasks = stoi(argv[2]);

		Data data = {nLoops, 0.0};

		// Creates nTasks threads
		pthread_t incrementThread[nTasks];

		for (unsigned int i=0;i<nTasks;i++)
		{
			pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
		}
		// Joins threads
		for (unsigned int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

		cout << "Counter value: " << data.counter << endl;
	}
	else
	{
		cout << "Uncorrect number of arguments. 2 expected." << endl;
	}

	return 0;
}
