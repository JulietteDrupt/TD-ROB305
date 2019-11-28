#include "Mutex.h"
#include <queue>

template <typename T>
class Fifo
{
	public :
		class EmptyException;
		void push(T element);
		T pop();
		T pop(double timeout_ms);

	protected :
		Mutex m;

	private :
		std::queue<T> elements;
};

template <typename T>
class Fifo<T>::EmptyException
{
	virtual const char* what() const throw()
	{
		return "Empty exception";
	}
};

template <typename T>
void Fifo<T>::push(T element)
{
	if ((this -> elements).empty())
	{
		Mutex::TryLock mtl = Mutex::TryLock(this -> mutex);
		mtl.notify();
		mtl.~TryLock();
	}
	(this -> elements).push(element);
}

template <typename T>
T Fifo<T>::pop()
{
	T val;
	if ((this -> elements).empty())
	{
		Mutex::Lock ml = Mutex::Lock(this -> mutex);
		ml.wait();
		ml.~Lock();
	}
	else
	{
		val = (this -> elements).front();
		(this -> elements).pop();
	}
	return val;
}

template <typename T>
T Fifo<T>::pop(double timeout_ms)
{
	T val;
	if ((this -> elements).empty())
	{
		throw Fifo::EmptyException();
		Mutex::Lock ml = Mutex::Lock(this -> mutex, timeout_ms);
		ml.wait();
		ml.~Lock();
	}
	else
	{
		val = (this -> elements).front();
		(this -> elements).pop();
	}
	return val;
}

