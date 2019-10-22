#include "TimeSpec.h"
#include <iostream>
using namespace std;


int main()
{
	timespec t = timespec_now();
	cout << t.tv_sec << "." << t.tv_nsec << endl;
	double tms = timespec_to_ms(t);
	cout << tms << " ms" << endl;
	timespec t2 = timespec_from_ms(tms);
	cout << t2.tv_sec << "." << t2.tv_nsec << endl;
	timespec t3 = timespec_negate(t2);
	cout << t3.tv_sec << "." << t3.tv_nsec << endl;
	timespec t4 = timespec_now();
	cout << t4.tv_sec << "." << t4.tv_nsec << endl;
	timespec t5 = timespec_add(t3,t3);
	cout << t5.tv_sec << "." << t5.tv_nsec << endl;
	timespec t6 = timespec_subtract(t4,t3);
	cout << t6.tv_sec << "." << t6.tv_nsec << endl;

	timespec t7 = t + t6;
	cout << t7.tv_sec << "." << t7.tv_nsec << endl;
	timespec t8 = t - t6;
	cout << t8.tv_sec << "." << t8.tv_nsec << endl;
	t8 += t7;
	cout << t8.tv_sec << "." << t8.tv_nsec << endl;
	t8 -= t7;
	cout << t8.tv_sec << "." << t8.tv_nsec << endl;
	cout << (t5 == t8) << endl;
	cout << (t5 < t8) << endl;
	cout << (t5 > t8) << endl;

	timespec t9 = timespec_from_ms(10e3);
	timespec t10 = timespec_wait(t9);
	cout << "ok!" << endl;

	timespec t11 = - t9;
	cout << t11.tv_sec << "." << t11.tv_nsec << endl;

	return 0;
}
    
