/*!
 * \file CountDown.h
 * \brief Periodic timer that counts down.
 * \author Juliette DRUPT
 */

#ifndef COUNT_DOWN_H
#define COUNT_DOWN_H

#include "PeriodicTimer.h"

/*! \class CountDown
 * \brief class of periodic timer that counts down
 */
class CountDown : public PeriodicTimer
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of CountDown class.
	 *
	 *  Creates and launches a periodic timer that counts down to 0.
	 *
	 *  \param n : value to start the count down from.
	 */
		CountDown(int n);
		volatile int n; /*!< value to start the count down from */

	protected :
	/*!
		*  \brief Callback that counts down.
		*/
		void callback();
};

#endif
