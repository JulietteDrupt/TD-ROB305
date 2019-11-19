#include "IncrementThread.h"
#include <signal.h>
#include "../TimeSpec.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	unsigned int nLoops = stoi(argv[1]);
	unsigned int nTasks = stoi(argv[2]);

	Data data = {nLoops, 0.0};

	IncrementThread *incThreads[nTasks];

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] = new IncrementThread();
	}

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] -> start();
	}

	for (unsigned int i=0; i<nTasks; i++)
	{
		incThreads[i] -> join();
	}

	return 0;
}

