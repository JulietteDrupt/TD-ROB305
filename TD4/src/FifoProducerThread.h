/*!
 * \file FifoProducerThread.h
 * \brief Thread that adds elements to a Fifo
 * \author Juliette DRUPT
 */

#ifndef FIFO_PROD_THREAD_H
#define FIFO_PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Fifo.hpp"

/*! \class FifoConsumerThread
 * \brief class that adds elements to a Fifo
 */
class FifoProducerThread : public Thread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of FifoProducerThread class.
	 *
	 *  Creates FifoProducerThread.
	 *
	 *  \param fifo : reference to a Fifo instance using int elements
	 *  \param n : number of elements to add to the Fifo
	 */
		FifoProducerThread(Fifo<int>& fifo, int n);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of FifoProducerThread class
		 */
		~FifoProducerThread();

	protected :
	/*!
		*  \brief Function called by Thread::call_run, that adds elements to the Fifo
		*/
		void run();
		Fifo<int>& fifo; /*!< Reference to a Fifo instance using int elements */
		int n; /*!< Number of elements to add to the Fifo */
};

#endif
