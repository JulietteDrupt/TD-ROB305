/*!
 * \file SemConsumerThread.h
 * \brief Thread that consumes the tokens of a semaphore
 * \author Juliette DRUPT
 */

#ifndef SEM_CONS_THREAD_H
#define SEM_CONS_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

/*! \class SemConsumerThread
 * \brief class that consumes the tokens of a semaphore
 */
class SemConsumerThread : public Thread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of SemConsumerThread class.
	 *
	 *  Creates SemConsumerThread.
	 *
	 *  \param sem : reference to a Semaphore instance
	 */
		SemConsumerThread(Semaphore& sem);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of SemConsumerThread class
		 */
		~SemConsumerThread();
	protected :
	/*!
		*  \brief Function called by Thread::call_run, that consumes tokens
		*/
		void run();
		Semaphore& sem; /*!< Reference to a Semaphore instance */

};


#endif
