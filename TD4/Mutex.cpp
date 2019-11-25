#include "Mutex.h"
#include <pthread.h>

Mutex::Mutex()
{
	pthread_mutexattr_t mutexAttribute,
	pthread_mutexattr_init(&mutexAttribute);
	pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&(this -> posixId), &mutexAttribute);
	pthread_cond_init(&(this -> posixCondId), NULL);
	pthread_mutexattr_destroy(&mutexAttribute);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&(this -> posixId));
	pthread_cond_destroy(&(this -> posixCondId));
}

void Mutex::lock()
{
	pthread_mutex_lock(&(this -> posixId));
}

bool lock(double timeout_ms);
bool trylock();

void unlock()
{
	pthread_mutex_unlock(&(this -> posixId));
}

