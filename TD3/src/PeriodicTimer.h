/*!
 * \file PeriodicTimer.h
 * \brief Periodic timer that encapsulates posix functionalities
 * \author Juliette DRUPT
 */

#ifndef PERIODIC_TIMER_H
#define PERIODIC_TIMER_H

#include "Timer.h"

/*! \class PeriodicTimer
 * \brief class that implements a periodic posix timer
 */
class PeriodicTimer : public Timer
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of PeriodicTimer class.
	 *
	 *  Creates and starts a timer with a  given periodicity.
	 *
	 *  \param duration_ms : period of the timer
	 */
		void start (double duration_ms);
};

#endif
