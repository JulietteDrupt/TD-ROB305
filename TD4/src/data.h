/**
 * \file data.h
 * \brief Defines Data structure.
 */

#ifndef DATA_H
#define DATA_H

/**
 * \struct Data
 * \brief Object with 2 parameters : a number of loops and a counter.
 *
 */
struct Data
{
	volatile unsigned int nLoops; /*!< Number of loops. */
	volatile double counter; /*!< Counter. */
};

#endif
