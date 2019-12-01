/*!
 * \file Looper.h
 * \brief Looper
 * \author Juliette DRUPT
 */

#ifndef LOOPER_H
#define LOOPER_H
#include <cfloat>
#include <limits>

/*! \class Looper
 * \brief class that can run a given number of itertions of a loop
 */
class Looper
{
	public :
	/*!
		*  \brief Runs a given number of iterations of a loop while stop is not true
		*
		*  \param nLoops : number of iterations to run. Its default value is DBL_MAX.
		*  \return the number of number of loops effectively executed
		*/
		double runLoop(double nLoops=DBL_MAX);
		/*!
			*  \brief Gets the current number of loops executed.
			*
			*  \return current number of loops executed
			*/
		double getSample();
		/*!
			*  \brief Stops the looper
			*
			*  \return number of loops executed
			*/
		double stopLoop();

	private :
		bool doStop; /*!< loop stops when it is true */
		volatile double iLoop; /*!< current number of loops executed */
};

#endif
