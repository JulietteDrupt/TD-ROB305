#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>
#include "TimeSpec.h"
using namespace std;


struct Data
{
	volatile unsigned int nLoops;
	volatile double counter;
	bool protect;
	pthread_mutex_t mutex;
};


void incr(Data* p_data)
{
	
	for (unsigned i=0; i < p_data -> nLoops; i++)
	{
		if (p_data -> protect)
		{
			pthread_mutex_lock(&p_data -> mutex);
			p_data -> counter += 1.0;
			pthread_mutex_unlock(&p_data -> mutex);
		}
		else
		{
			p_data -> counter += 1.0;
		}

	}
}

void* call_incr(void* v_data)
{
	Data* p_data = (Data*) v_data;

	incr(p_data);
	
	return v_data;
}


int main(int argc, char* argv[])
{
	unsigned int nLoops = stoi(argv[1]);
	unsigned int nTasks = stoi(argv[2]);
	bool protect = false;

	if (argc == 4)
	{
		string test = argv[3];
		if (test == "protected")
		{
			protect = true;
		}
	}

	Data data = {nLoops, 0.0, protect};
	if (protect)
	{
		pthread_mutex_init(&data.mutex, NULL);
	}

	pthread_t incrementThread[nTasks];

	timespec time_begin = timespec_now();

	for (int i=0;i<nTasks;i++)
	{
		pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
	}

	for (int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

	timespec time_end = timespec_now();
	timespec duration_ts = time_end - time_begin;
	double duration_s = timespec_to_ms(duration_ts) / 1e3;
	cout << "Duration : " << duration_s << " s" << endl;

	if (protect)
	{
		pthread_mutex_destroy(&data.mutex);
	}

	cout << "Counter value: " << data.counter << endl;	

	return 0;
}
