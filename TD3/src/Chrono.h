#ifndef CHRONO_H
#define CHRONO_H

#include <time.h>

class Chrono
{
	public :
		// Constructeur
		Chrono();

		// Méthodes
		void stop();
		void restart();
		bool isActive();
		double startTime();
		double stopTime();
		double lap();

	private :
		timespec startTime_;
		timespec stopTime_;
		bool active;
};

#endif
