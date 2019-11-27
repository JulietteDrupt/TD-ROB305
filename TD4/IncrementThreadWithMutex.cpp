#include "IncrementThreadWithMutex.h"

IncrementThreadWithMutex::IncrementThreadWithMutex(Data data, Mutex& mutex, bool tl) : IncrementThread(data), tl(tl), mutex(mutex)
{}

IncrementThreadWithMutex::~IncrementThreadWithMutex()
{}


