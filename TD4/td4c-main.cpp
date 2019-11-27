#include "ProductorThread.h"
#include "ConsumerThread.h"
#include "Semaphore.h"
#include "Mutex.h"
#include <signal.h>

int main()
{
	Semaphore sem;
	ProductorThread pt = ProductorThread(sem);
	ConsumerThread ct = ConsumerThread(sem);
	return 0;
}

