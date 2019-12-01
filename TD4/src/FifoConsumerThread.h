/*!
 * \file FifoConsumerThread.h
 * \brief Thread that consumes the elements of a Fifo
 * \author Juliette DRUPT
 */

#ifndef FIFO_CONS_THREAD_H
#define FIFO_CONS_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Fifo.hpp"

/*! \class FifoConsumerThread
 * \brief class that consumes the elements of a Fifo
 */
class FifoConsumerThread : public Thread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of FifoConsumerThread class.
	 *
	 *  Creates FifoConsumerThread.
	 *
	 *  \param fifo : reference to a Fifo instance using int elements
	 *  \param n : number of elements to consume from the Fifo
	 */
		FifoConsumerThread(Fifo<int>& fifo, int n);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of FifoConsumerThread class
		 */
		~FifoConsumerThread();

	protected :
	/*!
		*  \brief Function called by Thread::call_run, that consumes elements from the Fifo
		*/
		void run();
		Fifo<int>& fifo; /*!< Reference to a Fifo instance using int elements */
		int n; /*!< Number of elements to consume from the Fifo */
};

#endif
