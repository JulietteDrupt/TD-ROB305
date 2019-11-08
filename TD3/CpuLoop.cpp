#include "CpuLoop.h"
#include "Looper.h"
#include "Calibrator.h"

CpuLoop::CpuLoop(Calibrator &calibrator) : Looper(), calibrator(calibrator){}

void runTime(double duration_ms)
{
	int i = 1;
}

