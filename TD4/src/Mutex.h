/*!
 * \file Mutex.h
 * \brief Encapsulation of the functionalities of a posix mutex.
 * \author Juliette DRUPT
 */

#ifndef MUTEX_H
#define MUTEX_H

#include <signal.h>

/*! \class PosixThread
 * \brief class that encapsulates the functionalities of a posix mutex
 */
class Mutex
{
	public :
  	/*! \class Mutex::Lock
  	 * \brief class that locks a mutex
  	 */
		class Lock;
		/*! \class Mutex::TryLock
		 * \brief class that tries to lock a mutex
		 */
		class TryLock;
		/*! \class Mutex::Monitor
		 * \brief class that monitors a mutex
		 */
		class Monitor;
		/*!
		 *  \brief Constructor
		 *
		 *  Constructor of Mutex class.
		 *
		 *  Creates Mutex.
		 */
		Mutex();
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of Mutex class
		 */
		~Mutex();

	private :
		pthread_mutex_t posixId; /*!< Posix mustex */
		pthread_cond_t posixCondId; /*!< Posix condition attribute of the mutex */
		/*!
			*  \brief Locks the mutex
			*/
		void lock();
		/*!
			*  \brief Locks the mutex with a timeout
			*
			*  \param timeout_ms : lock timeout
			*  \return true on success, false otherwise
			*/
		bool lock(double timeout_ms);
		/*!
			*  \brief Tries to lock the mutex
			*  \return true on success, false otherwise
			*/
		bool trylock();
		/*!
			*  \brief Unlocks the mutex
			*/
		void unlock();
};

class Mutex::Monitor
{
	public :
	  /*! \class Mutex::Monitor::TimeoutException
	   * \brief class that throws an exception if the lock or trylock operation of Lock (with timeout) and TryLock classes did not work.
	   */
		class TimeoutException;
		/*!
			*  \brief Waits for the posix condition of the mutex
			*
			*/
		void wait();
		/*!
			*  \brief Waits for the posix condition of the mutex or the end of a duration
			*
			*  \param timeout_ms : timeout value in milliseconds
			*  \return true on success, false otherwise
			*/
		bool wait(double timeout_ms);
		/*!
			*  \brief Notifies
			*
			*/
		void notify();
		/*!
			*  \brief Broadcasts
			*
			*/
		void notifyAll();
		Mutex& mutex; /*!< Reference to a Mutex object */

	protected :
	/*!
	 *  \brief Constructor
	 *
	 *  Constructor of Mutex::Monitor class.
	 *
	 *  Creates Mutex::Monitor instance.
	 *
	 *  \param m : reference to Mutex instance
	 */
		Monitor(Mutex& m);

};

class Mutex::Monitor::TimeoutException
{
	virtual const char* what() const throw()
	{
		return "Timeout exception";
	}
};

class Mutex::Lock : public Mutex::Monitor
{
	public :
	  /*!
	   *  \brief Constructor
  	 *
  	 *  Constructor of Mutex::Lock class.
	   *
  	 *  Creates Mutex::Lock instance and locks the mutex.
  	 *
  	 *  \param m : reference to Mutex instance
  	 */
		Lock(Mutex& m);
		/*!
		 *  \brief Constructor
		 *
		 *  Constructor of Mutex::Lock class.
		 *
		 *  Creates Mutex::Lock instance and locks the mutex with a timeout. Throw Mutex::Monitor::TimeoutException in case of failure
		 *
		 *  \param m : reference to Mutex instance
		 *  \param timeout_ms : timeout value in milliseconds
		 */
		Lock(Mutex& m, double timeout_ms);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of Mutex::Lock class
		 *
		 *  Unlocks the mutex
		 */
		~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
	public :
  	/*!
  	 *  \brief Constructor
  	 *
  	 *  Constructor of Mutex::TryLock class.
	   *
	   *  Creates Mutex::TryLock instance and tries to lock the mutex. Throw Mutex::Monitor::TimeoutException in case of failure
	   *
	   *  \param m : reference to Mutex instance
	   */
		TryLock(Mutex& m);
		/*!
		 *  \brief Destructor
		 *
		 *  Destructor of Mutex::TryLock class
		 *
		 *  Unlocks the mutex
		 */
		~TryLock();
};

#endif
