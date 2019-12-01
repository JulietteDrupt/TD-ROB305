/*!
 * \file Semaphore.h
 * \brief Semaphore.
 * \author Juliette DRUPT
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "Mutex.h"
#include <signal.h>
#include <climits>

/*! \class Semaphore
 * \brief class that consist in a semaphore
 */
class Semaphore
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of Semaphore class.
	 *
	 *  Creates a Semaphore instance.
	 *
	 *  \param initCount : initial number of tokens
	 *  \param maxCount  :maximum number of tokens
	 */
		Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);
		/*!
			*  \brief Adds a token
			*/
		void give();
		/*!
			*  \brief Removes a token and block if the token counter is 0
			*/
		void take();
		/*!
			*  \brief Removes a token and block with a timeout if the token counter is 0
			*/
		bool take(double timeout_ms);

	private :
		unsigned int counter; /*!< Token counter */
		unsigned int maxCount; /*!< Maximum number of tokens in counter */
		Mutex mutex; /*!< Mutex object */
};

#endif
