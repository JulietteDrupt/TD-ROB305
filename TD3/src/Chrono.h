/*!
 * \file Chrono.h
 * \brief Chronometer
 * \author Juliette DRUPT
 */

#ifndef CHRONO_H
#define CHRONO_H

#include <time.h>

class Chrono
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of Chrono class. Starts the Chrono at current time.
	 */
		Chrono();

		/*!
  		*  \brief Stops the Chrono
  		*/
		void stop();
		/*!
			*  \brief Restarts the Chrono
			*/
		void restart();
		/*!
			*  \brief Checks if the Chrono is active
			*
			*  \return the value of Chrono's active attribute
			*/
		bool isActive();
		/*!
			*  \brief Get Chrono's start time
			*
			*  \return the Chrono's start time
			*/
		double startTime();
		/*!
			*  \brief Get Chrono's stop time
			*
			*  \return the Chrono's stop time
			*/
		double stopTime();
		/*!
			*  \brief Computed the time the Chrono has been running or ran before being stopped
			*
			*  \return the time the Chrono has been running or ran before being stopped
			*/
		double lap();

	private :
		timespec startTime_; /*!< Chrono start time */
		timespec stopTime_; /*!< Chrono stop time */
		bool active; /*!< True if the Chrono isn't stopped */
};

#endif
