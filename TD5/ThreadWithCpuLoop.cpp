#include "ThreadWithCpuLoop.h"
#include "../TD3/CpuLoop.h"
#include "Mutex.h"
#include "../TD3/Calibrator.h"

ThreadWithCpuLoop::ThreadWithCpuLoop(Mutex& mutex, CpuLoop& cpul) : Thread(), cpul(cpul), mutex(mutex)
{}

ThreadWithCpuLoop::~ThreadWithCpuLoop()
{}

void ThreadWithCpuLoop::run()
{
	(this -> cpul).runTime(100.0); //Remplacer par le temps correspondant à 60 ticks d'horloge
}

