/*!
 * \file Calibrator.h
 * \brief Looper calibrator
 * \author Juliette DRUPT
 */

#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "PeriodicTimer.h"
#include "Looper.h"
#include <vector>

/*! \class Calibrator
 * \brief class that calibrates a looper
 *
 *  The class determines parameters a and b in the equation that links the number l of loops executed by a looper depending on time t : l(t)  = a*t+b.
 */
class Calibrator : public PeriodicTimer
{
	public :
		/*!
	 	 *  \brief Constructor
	 	 *
	 	 *  Constructor of Calibrator class.
	 	 *
		 *  Creates calibrator and computes looper calibration.
		 *
	 	 *  \param samplingPeriod_ms : sampling period for calibration
		 *  \param nSamples : number of samples to take for calibration
	 	 */
		Calibrator(double samplingPeriod_ms, unsigned int nSamples);
		/*!
  		*  \brief Computes the number of loops that correspond to a duration in milliseconds
  		*
  		*  Computes l(t) = a*t + b
  		*
  		*  \param strSong : le morceau a ajouter
  		*  \return the corresponding number of loops
  		*/
		double nLoops(double duration);
		/*!
  		*  \brief Getter for attribute a
  		*/
		int getA();
		/*!
  		*  \brief Getter for attribute b
  		*/
		int getB();
		Looper looper; /*!< Looper*/
		unsigned int nSamples; /*!< Number of samples to take*/


	protected :
	/*!
		*  \brief Callback that gets the current number of loops and stops the looper when the number of samples nSamples is reached.
		*/
		void callback();

	private :
		double a; /*!< a in l(t) = a*t+b */
		double b; /*!< b in l(t) = a*t+b */
		std::vector<double> samples; /*!< Number of loops executed for each sample */
};

#endif
