#include "TimeSpec.h"
#include <math.h>
#include <iostream>
using namespace std;

double timespec_to_ms(const timespec& time_ts)
{
	double time_ms = time_ts.tv_sec * 1e3 + time_ts.tv_nsec / 1e6;
	return time_ms;
}

timespec timespec_from_ms(double time_ms)
{
	struct timespec time_ts;
	time_ts.tv_sec = (long) (time_ms / 1e3);
	time_ts.tv_nsec = (time_ms / 1e3 - time_ts.tv_sec) * 1e9;
	return time_ts;
}
     

timespec timespec_now()
{
	struct timespec time_ts_now;
	clock_gettime(CLOCK_REALTIME, &time_ts_now);
	return time_ts_now;
}


timespec timespec_negate(const timespec& time_ts)
{
	struct timespec time_ts_neg;
	time_ts_neg.tv_sec = - time_ts.tv_sec;
	if (time_ts.tv_nsec != 0)
	{
		time_ts_neg.tv_sec -= 1;
		time_ts_neg.tv_nsec = 1e9 - time_ts.tv_nsec;
	}
	else
	{
		time_ts_neg.tv_nsec = 0;
	}
	return time_ts_neg;
}


timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
	struct timespec time_ts_sum;
	time_ts_sum.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
	time_ts_sum.tv_sec += (time1_ts.tv_nsec + time2_ts.tv_nsec) / 1e9;
	if (time1_ts.tv_nsec + time2_ts.tv_nsec < 1e9)
	{
		time_ts_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
	}
	else
	{
		time_ts_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec - 1e9;
	}
	return time_ts_sum;

}

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
	struct timespec time_ts_dif;
	time_ts_dif.tv_sec = time1_ts.tv_sec - time2_ts.tv_sec;
	if (time1_ts.tv_nsec < time2_ts.tv_nsec)
	{
		time_ts_dif.tv_sec -= 1;
		time_ts_dif.tv_nsec = time1_ts.tv_nsec + 1e9 - time2_ts.tv_nsec;
	}
        else
        {
		time_ts_dif.tv_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;
	}
	return time_ts_dif;
}

timespec timespec_wait(const timespec& delay_ts)
{
	struct timespec time_ts_remaining;
	//cout << "Gonna wait" << endl;
	int test = nanosleep(&delay_ts, &time_ts_remaining);
	//cout << "Gonna wait" << endl;
	while (test != 0)
	{
		test = nanosleep(&time_ts_remaining,&time_ts_remaining);
	}
	return time_ts_remaining;
}

timespec  operator- (const timespec& time_ts)
{
	timespec time_res = timespec_negate(time_ts);
	return time_res;
}

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_res = timespec_add(time1_ts, time2_ts);
	return time_res;
}

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_res = timespec_subtract(time1_ts, time2_ts);
	return time_res;
}

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_add(time_ts, delay_ts);
	return time_ts;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_subtract(time_ts, delay_ts);
	return time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
	return (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
	return !(time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}


bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_dif = timespec_subtract(time1_ts, time2_ts);
	double time_dif_ms = timespec_to_ms(time_dif);
	return (time_dif_ms < 0);
}

bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_dif = timespec_subtract(time1_ts, time2_ts);
	double time_dif_ms = timespec_to_ms(time_dif);
	return (time_dif_ms > 0);
}




