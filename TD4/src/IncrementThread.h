/*!
 * \file IncrementThread.h
 * \brief Thread that increments a counter value.
 * \author Juliette DRUPT
 */

#ifndef INC_THREAD_H
#define INC_THREAD_H

#include <signal.h>
#include "Thread.h"
#include "data.h"

/*! \class IncrementThread
 * \brief class that encapsulates the functionalities of a posix thread the increments a counter value
 */
class IncrementThread : public Thread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of IncrementThread class.
	 *
	 *  Creates IncrementThread.
	 *
	 *  \param data : value to set to data attribute
	 */
		IncrementThread(Data* data);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of IncrementThread class
		 */
		~IncrementThread();
		Data* data; /*!< Ponter to Data structure that countains a counter and a number of loops to do */

	protected :
	/*!
		*  \brief Function called by Thread::call_run, that increments data's counter
		*/
		void run();
};

#endif
