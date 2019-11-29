#include "Mutex.h"
#include <time.h>
#include "../TimeSpec.h"
#include <signal.h>
#include <pthread.h>
#include "../TD3/Calibrator.h"
#include "../TD3/CpuLoop.h"
#include "ThreadWithCpuLoop.h"

int main()
{
	Calibrator calib = Calibrator(100.0, 4);
	CpuLoop cpul = CpuLoop(calib);

	Mutex mutex = Mutex(true);
	ThreadWithCpuLoop A = ThreadWithCpuLoop(mutex, cpul);
	ThreadWithCpuLoop B = ThreadWithCpuLoop(mutex, cpul);
	ThreadWithCpuLoop C = ThreadWithCpuLoop(mutex, cpul);

	A.setScheduling(SCHED_RR, 10);
	B.setScheduling(SCHED_RR, 9);
	C.setScheduling(SCHED_RR, 8);


	return 0;
}

