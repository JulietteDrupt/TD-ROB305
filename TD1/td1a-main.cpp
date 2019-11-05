#include "TimeSpec.h"
#include <iostream>
using namespace std;


int main()
{
	timespec t = timespec_now();
	cout << "Current time t: " << t.tv_sec << "." << t.tv_nsec << endl;
	double tms = timespec_to_ms(t);
	cout << "t from timespec to ms: " << tms << " ms" << endl;
	timespec t2 = timespec_from_ms(tms);
	cout << "t from ms to timespec: " << t2.tv_sec << "." << t2.tv_nsec << endl;
	timespec t3 = timespec_negate(t2);
	cout << "Negative t: " << t3.tv_sec << "." << t3.tv_nsec << endl;
	timespec t4 = timespec_now();
	cout << "Current time t4: " << t4.tv_sec << "." << t4.tv_nsec << endl;
	timespec t5 = timespec_add(t3,t3);
	cout << "Adding t to t: " << t5.tv_sec << "." << t5.tv_nsec << " = t5" << endl;
	timespec t6 = timespec_subtract(t4,t3);
	cout << "Subtracting t to t4: " << t6.tv_sec << "." << t6.tv_nsec << " = t6" << endl;

	timespec t7 = t + t6;
	cout << "t + t6 = " << t7.tv_sec << "." << t7.tv_nsec << " = t7" << endl;
	timespec t8 = t - t6;
	cout << "t - t6 = " << t8.tv_sec << "." << t8.tv_nsec << " = t8" << endl;
	t8 += t7;
	cout << "t8 += t7: " << t8.tv_sec << "." << t8.tv_nsec << endl;
	t8 -= t7;
	cout << "t8 -= t7: " << t8.tv_sec << "." << t8.tv_nsec << endl;
	cout << "t5 == t8: " << (t5 == t8) << endl;
	cout << "t5 < t8: " << (t5 < t8) << endl;
	cout << "t5 > t8: " << (t5 > t8) << endl;

	timespec t9 = timespec_from_ms(10e3);
	cout << "Waiting for 10 seconds" << endl;
	timespec t10 = timespec_wait(t9);
	cout << "ok!" << endl;

	timespec t11 = - t9;
	cout << "t11 = - t9: " << t11.tv_sec << "." << t11.tv_nsec << " (t9 corresponding to 10 second)" << endl;

	return 0;
}
    
