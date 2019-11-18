#include "IncrementThread.h"
#include <signal.h>
#include <iostream>
using namespace std;

int main()
{
	IncrementThread inct = IncrementThread();
	inct.start();
	//inct.join();
	return 0;
}

