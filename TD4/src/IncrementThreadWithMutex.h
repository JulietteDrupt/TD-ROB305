/*!
 * \file IncrementThreadWithMutex.h
 * \brief Thread that increments a counter value using a mutex.
 * \author Juliette DRUPT
 */


#ifndef INC_THREAD_MUTEX_H
#define INC_THREAD_MUTEX_H

#include "IncrementThread.h"
#include "Mutex.h"
#include "data.h"
#include <signal.h>

class IncrementThreadWithMutex : public IncrementThread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of IncrementThreadWithMutex class.
	 *
	 *  Creates IncrementThreadWithMutex.
	 *
	 *  \param data : pointer to Data structure
	 *  \param mutex : reference to a Mutex instance
	 */
		IncrementThreadWithMutex(Data* data, Mutex& mutex);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of IncrementThreadWithMutex class
		 */
		~IncrementThreadWithMutex();
	protected :
		Mutex& mutex; /*!< Reference to a Mutex instance */
		/*!
			*  \brief Function called by Thread::call_run, that increments data's counter
			*/
		void run();
};

#endif
