#include <time.h>
#include <iostream>
#include <string>
#include "../TimeSpec.h"
using namespace std;

void incr(unsigned int nLoops, volatile double* pCounter)
{
	for (unsigned i=0; i<nLoops; i++)
	{
		*pCounter += 1.0;
	}
}

int main(int argc, char* argv[])
{
	unsigned int nLoops = stoi(argv[1]);
	volatile double counter = 0.0;

	timespec time_begin = timespec_now();
	incr(nLoops, &counter);
	timespec time_end = timespec_now();

	timespec duration_ts = time_end - time_begin;
	double duration_s = timespec_to_ms(duration_ts) / 1e3;
	cout << "Counter: " << counter << endl;
	cout << "Duration : " << duration_s << " s" << endl;

	
	return 0;
}
