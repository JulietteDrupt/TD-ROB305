#include "TimeSpec.h"
#include "Chrono.h"
#include <iostream>
using namespace std;

int main()
{
	Chrono chrono;
	cout << "test isActive : " << chrono.isActive() << endl;
	cout << "test startTime : " << chrono.startTime() << endl;
	cout << "test lap : " << chrono.lap() << endl;
	chrono.stop();
	cout << "stop" << endl;
	cout << "test lap : " << chrono.lap() << endl;
	cout << "test stopTime : " << chrono.stopTime() << endl;
	cout << "test lap : " << chrono.lap() << endl;
	cout << "test isActive : " << chrono.isActive() << endl;
	chrono.restart();
	cout << "restart" << endl;
	cout << "test isActive : " << chrono.isActive() << endl;

	return 0;
}
