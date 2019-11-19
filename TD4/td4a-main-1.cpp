#include "IncrementThread.h"
#include <signal.h>
#include <iostream>
using namespace std;

/*
This program reproduces TD2a with an object-oriented architecture.
*/

int main(int argc, char* argv[])
{
	cout << "Reproducing TD-2a" << endl;

	unsigned int nLoops = stoi(argv[1]);
	unsigned int nTasks = stoi(argv[2]);

	Data data = {nLoops, 0.0};

	IncrementThread *incThreads[nTasks];

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] = new IncrementThread(data);
	}

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] -> start();
	}

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] -> join();
	}

	for (unsigned int i=0; i<nTasks; i++)
	{
		cout << (incThreads[i] -> data).counter << endl;
	}

	return 0;
}

