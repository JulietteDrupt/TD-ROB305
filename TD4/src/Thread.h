/*!
 * \file Thread.h
 * \brief Inherits from PosixThread and completes posix thread encapsulation
 * \author Juliette DRUPT
 */

#ifndef THREAD_H
#define THREAD_H

#include <signal.h>
#include <time.h>
#include "PosixThread.h"

/*! \class Thread
 * \brief clas that completes posix thread functionalities encapsulation
 */
class Thread : public PosixThread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of Thread class.
	 *
	 *  Creates Thread.
	 */
		Thread();
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of Thread class
		 */
		~Thread();
		/*!
			*  \brief Creates the thread and determines it start time and stop time
			*
			*  The thread created executes function Thread::call_run.
			*  \return true if the thread  not already running, false otherwise.
			*/
		bool start();
		/*!
			*  \brief Puts the thread to sleep a given duration
			*
			*  \param delay_ms : sleep duration in milliseconds
			*/
		static void sleep_ms(double delay_ms);
		/*!
			*  \brief Get the time the thread started at
			*
			*  \return start time, in milliseconds
			*/
		double startTime_ms();
		/*!
			*  \brief Get the time the thread stopped at
			*
			*  \return stop time, in milliseconds
			*/
		double stopTime_ms();
		/*!
			*  \brief Get the duration of the thread execution
			*
			*  \return execution time, in milliseconds
			*/
		double execTime_ms();
		static bool started; /*!< true if the thread is running, false otherwise */

	protected :
	/*!
		*  \brief Function called by Thread::call_run
		*/
		virtual void run() = 0;

	private :
	/*!
		*  \brief Function the thread has to execute
		*
		*  \param v_thread : pointer (void *) to the thread
		*  \return Pointer to the thread.
		*/
		static void* call_run(void* v_thread);
		timespec startTime; /*!< time the thread starts at */
		timespec stopTime; /*!< time the thread stops at */
		pthread_attr_t posixAttr; /*!< posix attribute of the thread */
};

#endif
