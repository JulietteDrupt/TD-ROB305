#include "TimeSpec.h"
#include "CountDown.h"
#include <iostream>
using namespace std;

int main()
{
	double duration = 1000;
	CountDown cd(5);

	cd.start(duration); 
	while (cd.n >= 0)
	{
		continue;
	}
	cd.stop();
	

	return 0;
}

