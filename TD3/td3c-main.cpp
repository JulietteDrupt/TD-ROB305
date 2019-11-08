#include "Calibrator.h"
#include "CpuLoop.h"

int main()
{
	Calibrator calib = Calibrator(100.0,4);
	CpuLoop cpul = CpuLoop(calib);

	return 0;
}

