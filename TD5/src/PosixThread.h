/*!
 * \file PosixThread.h
 * \brief Encapsulation of the functionalities of a posix thread.
 * \author Juliette DRUPT
 */

#ifndef POSIX_THREAD_H
#define P0SIX_THREAD_H

#include <signal.h>
#include <exception>
#include <string>
#include <iostream>
using namespace std;

/*! \class PosixThread
 * \brief class that encapsulates the functionalities of a posix thread
 */
class PosixThread
{
	public :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of PosixThread class.
	 *
	 *  Creates PosixThread.
	 */
		PosixThread();
		/*!
		 *  \brief Constructor
		 *
		 *  Constructor of PosixThread class.
		 *
		 *  Creates PosixThread with an existing posix thread.
		 *
		 *  \param posixId : existing posix thread
		 */
		PosixThread(pthread_t posixId);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of PosixThread class
		 */
		~PosixThread();
		/*!
  		*  \brief Creates the thread
  		*
  		*  \param threadFunc : fonction the thread has to execute
			*  \param threadArg : thread arguments
  		*/
		void start(void* (*threadFunc)(void*), void* threadArg);
		/*!
			*  \brief Encapsulates posix join without parameter
			*/
		void join();
		/*!
			*  \brief Realises a timed join
			*
			*  \param timeout_ms : join timeout
			*  \return true on success, false otherwise
			*/
		bool join(double timeout_ms);
		/*!
			*  \brief Sets the scheduling of the thread
			*
			*  \param schedPolicy : scheduling policy to set
			*  \param priority : priority to set
			*  \return true on success, false otherwise
			*/
		bool setScheduling(int schedPolicy, int priority);
		/*!
			*  \brief Gets the scheduling of the thread
			*
			*  \param p_schedPolicy : pointer to the variable where to stock the scheduling policy value
			*  \param p_priority : pointer to the variable where to stock the priority value
			*  \return true on success, false otherwise
			*/
		bool getScheduling(int* p_schedPolicy = nullptr, int* p_priority = nullptr);
		/*! \class PosixThread::Exception
		 * \brief throws an exception if the posix thread given in parameter does not exist in the second constructor
		 */
		class Exception;

	protected :
		bool isActive; /*!< true if the task is active, false otherwise */

	private :
		pthread_t posixId; /*!< Posix thread */
		pthread_attr_t posixAttr; /*!< Posix attribute */

};

class PosixThread::Exception : public exception
{
	public :
		Exception(const string& msg);
		const char* what() const noexcept override
		{
			return _msg.c_str();
		};
	private :
		string _msg;

};

#endif
