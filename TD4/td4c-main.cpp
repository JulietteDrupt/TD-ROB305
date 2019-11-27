#include "ProductorThread.h"
#include "ConsumerThread.h"
#include "Semaphore.h"
#include "Mutex.h"
#include <signal.h>

int main()
{
	Semaphore sem;
	ProductorThread pt = ProductorThread(sem);
	ProductorThread pt2 = ProductorThread(sem);
	ConsumerThread ct = ConsumerThread(sem);

	pt.start();
	pt2.start();
	ct.start();
	pt2.start();
	pt.join();
	pt2.join();
	ct.join();

	return 0;
}

