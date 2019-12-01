/**
 * \file td4a-main.cpp
 * \brief Tests IncrementThread class.
 * \author Juliette DRUPT
 * \date December 1st 2020
 *
 * This program reproduces TD2a with an object-oriented architecture
 */

#include "IncrementThread.h"
#include <signal.h>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		cout << "Reproducing TD-2a" << endl;

		unsigned int nLoops = stoi(argv[1]);
		unsigned int nTasks = stoi(argv[2]);

		Data data = {nLoops, 0.0};

		// Creates nTasks IncrementThreads
		IncrementThread *incThreads[nTasks];

		for (unsigned int i=0; i<nTasks; i++)
		{
			incThreads[i] = new IncrementThread(&data);
		}

		for (unsigned int i=0; i<nTasks; i++)
		{
			incThreads[i] -> start();
		}

		// Joins IncrementThreads
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
