#include "IncrementThread.h"
#include <iostream>
using namespace std;

IncrementThread::IncrementThread() : Thread()
{}

void IncrementThread::run()
{
	int i = 1;
	cout << "ok" << endl;
}

