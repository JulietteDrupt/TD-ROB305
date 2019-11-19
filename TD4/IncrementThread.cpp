#include "IncrementThread.h"
#include <iostream>
using namespace std;

IncrementThread::IncrementThread(Data data) : Thread()
{
	this -> data = data;
}

void IncrementThread::run()
{
	for (unsigned i=0; i < (this -> data).nLoops; i++)
	{
		(this -> data).counter += 1.0;
	}
}

