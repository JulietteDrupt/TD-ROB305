//#define _GNU_SOURCE
#include <sched.h>

#include "Mutex.h"
#include <time.h>
#include "../TimeSpec.h"
#include <signal.h>
#include <pthread.h>
#include "../TD3/Calibrator.h"
#include "../TD3/CpuLoop.h"
#include "ThreadWithCpuLoop.h"
#include <iostream>
using namespace std;


int main()
{
	cpu_set_t  cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);
	sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);


	Calibrator calib = Calibrator(100.0, 4);
	CpuLoop cpulA = CpuLoop(calib);
	CpuLoop cpulB = CpuLoop(calib);
	CpuLoop cpulC = CpuLoop(calib);

	Mutex mutex = Mutex(false);
	ThreadWithCpuLoop A = ThreadWithCpuLoop(mutex, cpulA, 40, 60, 30, 10, 10);
	ThreadWithCpuLoop B = ThreadWithCpuLoop(mutex, cpulB, 10, 70, 30);
	ThreadWithCpuLoop C = ThreadWithCpuLoop(mutex, cpulC, 50, 110, 0, 20, 20);

	A.setScheduling(SCHED_RR, 10);
	B.setScheduling(SCHED_RR, 9);
	C.setScheduling(SCHED_RR, 8);


	A.start();
	B.start();
	C.start();

	A.join();
	B.join();
	C.join();

	timespec end = timespec_now();

	cout << "A : full duration : " << A.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;
	cout << "B : full duration : " << B.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;
	cout << "C : full duration : " << C.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;


	return 0;
}

