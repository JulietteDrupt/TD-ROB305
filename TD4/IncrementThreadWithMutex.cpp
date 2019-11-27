#include "IncrementThreadWithMutex.h"

IncrementThreadWithMutex::IncrementThreadWithMutex(Data data, Mutex::Monitor& monitor) : IncrementThread(data), monitor(monitor)
{}

IncrementThreadWithMutex::~IncrementThreadWithMutex()
{}

