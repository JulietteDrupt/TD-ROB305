#include "IncrementThreadWithMutex.h"
#include "Mutex.h"
#include <signal.h>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	unsigned int nLoops = stoi(argv[1]);
	unsigned int nTasks = stoi(argv[2]);

	Data data = {nLoops, 0.0};

	Mutex mutex;
	Mutex::Lock l = Mutex::Lock(mutex);
	Mutex::TryLock l2 = Mutex::TryLock(mutex);

	IncrementThreadWithMutex* inct = new IncrementThreadWithMutex(data, l);

	return 0;
}


