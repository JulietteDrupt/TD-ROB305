/*!
 * \file CpuLoop.h
 * \brief Looper calibration and execution on CPU
 * \author Juliette DRUPT
 */

#ifndef CPULOOP_H
#define CPULOOP_H

#include "Looper.h"
#include "Calibrator.h"

/*! \class CpuLoop
 * \brief class that calibrates a looper and is able to run it a given time according to the calibration.
 */
class CpuLoop : public Looper
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of CpuLoop class.
	 *
	 *  Calibrates the looper.
	 *
	 *  \param calibrator : Calibrator used
	 */
		CpuLoop(Calibrator &calibrator);
		/*!
			*  \brief Runs the looper for a given time
			*
			*  Used calibration to compute the number of loops to do to run this given time.
			*
			*  \param duration_ms : duration willed, in milliseconds
			*/
		void runTime(double duration_ms);
		Calibrator& calibrator; /*!< looper calibrator */
};

#endif
