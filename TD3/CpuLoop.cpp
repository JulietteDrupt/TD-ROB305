#include "CpuLoop.h"
#include "Looper.h"
#include "Calibrator.h"
#include <iostream>
using namespace std;

CpuLoop::CpuLoop(Calibrator &calibrator) : Looper(), calibrator(calibrator){}

void CpuLoop::runTime(double duration_ms)
{
	double n = (this -> calibrator).nLoops(duration_ms);
	double nl = this -> runLoop(n);
	cout << nl << endl;
}

