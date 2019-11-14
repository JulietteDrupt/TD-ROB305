#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>
#include "../TimeSpec.h"
using namespace std;


struct Data
{
	volatile unsigned int nLoops;
	volatile double counter;
};


void incr(volatile unsigned int nLoops, volatile double* pCounter)
{
	for (unsigned i=0; i<nLoops; i++)
	{
		*pCounter += 1.0;
	}
}

void* call_incr(void* v_data)
{
	Data* p_data = (Data*) v_data;
	incr(p_data -> nLoops, &p_data -> counter);
	return v_data;
}


int main(int argc, char* argv[])
{
	unsigned int nLoops = stoi(argv[1]);
	unsigned int nTasks = stoi(argv[2]);
	int schedPolicy = atoi(argv[3]);

	struct sched_param schedParam;
	schedParam.sched_priority = sched_get_priority_max(schedPolicy);
	pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&attr, schedPolicy);
	sched_param schedParams;
	schedParams.sched_priority = 9;
	pthread_attr_setschedparam(&attr, &schedParams);

	Data data = {nLoops, 0.0};

	pthread_t incrementThread[nTasks];

	timespec time_begin = timespec_now();

	for (int i=0;i<nTasks;i++)
	{
		pthread_create(&incrementThread[i], &attr, call_incr, (void*)&data);
	}
	pthread_attr_destroy(&attr);
	for (int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

	timespec time_end = timespec_now();
	timespec duration_ts = time_end - time_begin;
	double duration_s = timespec_to_ms(duration_ts) / 1e3;
	cout << "Duration : " << duration_s << " s" << endl;

	cout << "Counter value: " << data.counter << endl;	
	
	return 0;
}
