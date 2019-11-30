/**
 * \file td3c-main.cpp
 * \brief Calibrates a looper and checks calibration.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program reproduces looper calibration of TD1-d with an object oriented architecture.
 *
 */

#include "Calibrator.h"
#include "CpuLoop.h"

int main()
{
	Calibrator calib = Calibrator(100.0,4);
	CpuLoop cpul = CpuLoop(calib);
	cpul.runTime(100.0);

	return 0;
}
