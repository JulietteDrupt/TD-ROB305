/**
 * \file td4b-main.cpp
 * \brief Tests IncrementThread class.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program reproduces TD4a with a mutex protection
 */

#include "IncrementThreadWithMutex.h"
#include "Mutex.h"
#include <signal.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 3)
	{

		unsigned int nLoops = stoi(argv[1]);
		unsigned int nTasks = stoi(argv[2]);

		Data data = {nLoops, 0.0};

		Mutex mutex;
		IncrementThreadWithMutex *incThreads[nTasks];

		for (unsigned int i=0; i<nTasks; i++)
		{
			incThreads[i] = new IncrementThreadWithMutex(&data, mutex);
		}

		for (unsigned int i=0; i<nTasks; i++)
		{
			incThreads[i] -> start();
		}

		for (unsigned int i=0; i<nTasks; i++)
		{
			incThreads[i] -> join();
		}

		cout << "Counter value : " << (incThreads[0] -> data) -> counter << endl;
	}
	else
	{
		cout << "Uncorrect number of arguments. 2 expected." << endl;
	}


	return 0;
}
