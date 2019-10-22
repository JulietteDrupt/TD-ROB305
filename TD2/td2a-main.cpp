#include <time.h>
#include <iostream>
#include <string>
#include <pthread.h>
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

	Data data = {nLoops, 0.0};

	pthread_t incrementThread[nTasks];

	for (int i=0;i<nTasks;i++)
	{
		pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
	}
	for (int i=0; i<nTasks;i++) pthread_join(incrementThread[i],NULL);

	cout << "Counter value: " << data.counter << endl;	

	return 0;
}
