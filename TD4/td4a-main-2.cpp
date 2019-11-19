#include "IncrementThread.h"
#include <signal.h>
#include <iostream>
using namespace std;

/*
This program tests all aspects of the Thread class. Since Thread class is virtual, because of its run method, we will use IncrementThread class to do so.
*/

int main()
{
	cout << "Testing Thread() and PosixThread() (called by IncrementThread's constructor), as well as the destructor" << endl;
	Data data = {2,0};
	IncrementThread* inct = new IncrementThread(data);

	cout << "Testing getScheduling on non active thread" << endl;
	int policy;
	int priority;
	cout << "isActive : " << inct -> getScheduling(&policy, &priority) << endl;
	cout << "policy : " << policy << " priority : " << priority << endl;

	cout << "Testing setScheduling on non active thread" << endl;
	cout << "isActive : " << inct -> setScheduling(policy + 1, priority + 1) << endl;
	inct -> getScheduling(&policy, &priority);
	cout << "policy : " << policy << " priority : " << priority << endl;

	cout << "Testing start, and thus call_run and run" << endl;
	inct -> start();

	cout << "Testing join without timeout" << endl;
	inct -> join();

	cout << "Testing sleep_ms for 3s" << endl;
	inct -> sleep_ms(3e3);
	cout << "Ok" << endl;

	cout << "Testing startTime, stopTime and esecTime" << endl;
	cout << "startTime : " << inct -> startTime_ms() << " stopTime : " << inct -> stopTime_ms() << " execTime : " << inct -> execTime_ms() << endl;

/*
Restent à tester :
	- exception
	- constructeur avec paramètre
	- join avec paramètre
	- setScheduling avec active thread
	- getScheduling avec active thread
*/

	return 0;
}

