#include "CountDown.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;


void CountDown::callback()
{
	cout << "coucou" << endl;
}

