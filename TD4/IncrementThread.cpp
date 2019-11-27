#include "IncrementThread.h"
#include <iostream>
using namespace std;

IncrementThread::IncrementThread(Data data) : Thread(), data(data)
{}

IncrementThread::~IncrementThread()
{}

void IncrementThread::run()
{
	for (unsigned int i=0; i < (this -> data).nLoops; i++)
	{
		(this -> data).counter += 1.0;
	}
}

