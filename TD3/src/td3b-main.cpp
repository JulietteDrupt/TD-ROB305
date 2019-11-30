/**
 * \file td3b-main.cpp
 * \brief Tests CountDown class.
 * \author Juliette DRUPT
 * \date November 30th 2020
 *
 * This program instanciates a CountDown object and tests its methods, and thus tests Timer and PeriodicTimer classes.
 *
 */

#include "TimeSpec.h"
#include "CountDown.h"
#include <iostream>
using namespace std;

int main()
{
	double duration = 1000;
	CountDown cd(5);

	cd.start(duration);
	while (cd.n >= 0)
	{
		continue;
	}
	cd.stop();


	return 0;
}
