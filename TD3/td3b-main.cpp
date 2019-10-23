#include "TimeSpec.h"
#include "CountDown.h"

int main()
{
	double duration = 32;
	CountDown cd;
	cd.start(duration);
	for (int i = 0; i<3000; i++)
	{
		continue;
	}
	cd.stop();
	

	return 0;
}

