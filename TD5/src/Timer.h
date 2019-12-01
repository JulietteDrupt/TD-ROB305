/*!
 * \file Timer.h
 * \brief Timer that encapsulate posix functionalities
 * \author Juliette DRUPT
 */

#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <signal.h>

/*! \class Timer
 * \brief class that implements a posix timer
 */
class Timer
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of Timer class.
	 */
		Timer();
		/*!
 		 *  \brief Destructor
 	 	 *
 	 	 *  Destructor of Timer class
 	 	 */
		~Timer();

		/*!
  		*  \brief Starts the timer
  		*
  		*  \param duration_ms : delay before calling callback
  		*/
		void start (double duration_ms);
		/*!
			*  \brief Stops the timer
			*/
		void stop();

	protected :
		timer_t tid; /*!< Timer posix id */
		virtual void callback() = 0; /*!< Timer's callback */
		struct sigaction sa;
		struct sigevent sev;

	private :
	/*!
		*  \brief Calls the callback
		*/
		static void call_callback (int sig, siginfo_t* si, void* user);

};

#endif
