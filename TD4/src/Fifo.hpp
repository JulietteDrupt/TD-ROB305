/*!
 * \file Fifo.hpp
 * \brief Fifo template
 * \author Juliette DRUPT
 */

#ifndef FIFO_H
#define FIFO_H

#include "Mutex.h"
#include <queue>

/*! \class Fifo
 * \brief class that consist in a fifo
 */
template <typename T>
class Fifo
{
	public :
	/*! \class Fifo::EmptyException
	 * \brief class that throws an exception if the fifo is empty.
	 */
		class EmptyException;
		/*!
			*  \brief Adds an element to the fifo, as last item
			*
			*  \param element : element to add
			*/
		void push(T element);
		/*!
			*  \brief Removes the first element in the fifo
			*
			*  \return element removed from the fifo
			*/
		T pop();
		/*!
			*  \brief Removes the first element in the fifo with a timeout
			*
			*  \param timeout_ms : timeout value in milliseconds
			*  \return element removed from the fifo or random element in case the pop did not succeed within the timeout
			*/
		T pop(double timeout_ms);

	protected :
		Mutex mutex; /*!< Mutex object */

	private :
		std::queue<T> elements; /*!< Elements in the fifo */
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

#endif
