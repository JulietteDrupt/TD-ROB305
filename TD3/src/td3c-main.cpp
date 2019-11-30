#include "Calibrator.h"
#include "CpuLoop.h"

int main()
{
	Calibrator calib = Calibrator(100.0,4);
	CpuLoop cpul = CpuLoop(calib);
	cpul.runTime(100.0);

	return 0;
}
