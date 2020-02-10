#include "pch.h"
#include "Time.h"

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
// set new Time value
void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}
// print Time
void Time::printTime() const
{
	cout << hour << ":" << minute << ":" << second << "\n";
}

void Time::setTimePartA(int h, int m, int s, const char*AMPM) {
	if (AMPM == "PM") {
		if (h < 12) {
			hour = h + 12;
			minute = (m >= 0 && m < 60) ? m : 0;
			second = (s >= 0 && s < 60) ? s : 0;

		}
		else if (h == 12) {
			hour = 12;
			minute = (m >= 0 && m < 60) ? m : 0;
			second = (s >= 0 && s < 60) ? s : 0;
		}

		else {
			cout << "incorrect value for hour";
		}
	}

	else if (AMPM == "AM") {
		if (h <= 12) {
			hour = h;
			minute = (m >= 0 && m < 60) ? m : 0;
			second = (s >= 0 && s < 60) ? s : 0;

		}
		else {
			cout << "incorrect value for hour";
		}
	}
}


void Time::printTimePartB() const
{
	if (hour > 12)
	{
		cout << (hour-12) << ":" << minute << ":" << second << " PM\n";
	}
	else
	{
		cout << hour << ":" << minute << ":" << second << " AM\n";
	}
}

//
// Returns the timestamp as the number of seconds in the day
//
int Time::getSecondTimeStamp() const
{
	return second + (60 * minute) + (3600 * hour);
}


