/*!
 * \file SemProducerThread.h
 * \brief Thread that gives tokens to a semaphore
 * \author Juliette DRUPT
 */

#ifndef SEM_PROD_THREAD_H
#define SEM_PROD_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "Semaphore.h"

/*! \class SemProducerThread
 * \brief class that gives tokens to a semaphore
 */
class SemProducerThread : public Thread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of SemProducerThread class.
	 *
	 *  Creates SemProducerThread.
	 *
	 *  \param sem : reference to a Semaphore instance
	 */
		SemProducerThread(Semaphore& sem);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of SemProducerThread class
		 */
		~SemProducerThread();
	protected :
	/*!
		*  \brief Function called by Thread::call_run, that produces tokens
		*/
		void run();
		Semaphore& sem; /*!< Reference to a Semaphore instance */

};


#endif
