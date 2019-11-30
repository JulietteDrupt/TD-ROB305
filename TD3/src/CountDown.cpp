/*!
 * \file CounDown.cpp
 * \brief CountDown class implementation
 * \author Juliette DRUPT
 */

#include "CountDown.h"
#include "TimeSpec.h"
#include <signal.h>
#include <iostream>
using namespace std;

CountDown::CountDown(int n) : PeriodicTimer(), n(n)
{}

void CountDown::callback()
{
	cout << this -> n << endl;
	(this -> n)--;
}
