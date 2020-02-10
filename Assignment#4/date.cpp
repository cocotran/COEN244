#include "date.h"
#include <iostream>

// Default constructor constructs the date for today
Date::Date()
{
	// set null time, create a tm struct, use localtime_r to fill the data for the current tieme.
	time_t t = time(NULL);
	tm buffer;
    localtime_s(&buffer, &t); // USE FOR WINDOWS
    // localtime_r(&t, &buffer); // USE FOR LINUX

	this->day = buffer.tm_mday;
	this->month = buffer.tm_mon + 1;
	this->year = buffer.tm_year + 1900;
	current_time = buffer;
	// initialize the date object's values to correspond w/ this data. Months and days are incremented by 1 because of how ctime is implemented
}

void Date::addDays(int days_past_today)
{
	time_t t = mktime(&current_time);
	tm buffer;
	t += (60*60*24*days_past_today);
    localtime_s(&buffer, &t); // USE FOR WINDOWS
    // localtime_r(&t, &buffer); // USE FOR LINUX

	this->day = buffer.tm_mday;
	this->month = buffer.tm_mon + 1;
	this->year = buffer.tm_year + 1900;
}

Date::Date(int days)
{
	// set null time, create a tm struct, use localtime_r to fill the data for the current tieme.
	time_t t = time(NULL);
	tm buffer;
    localtime_s(&buffer, &t); // USE FOR WINDOWS
    // localtime_r(&t, &buffer); // USE FOR LINUX
	current_time = buffer;

	addDays(days);

}


// Days between dates calculating function - excludes start/end days. To include them, add +2 to day_count
int Date::differenceInDays(const Date& d1, const Date& d2) const
{

	int days_Passed_Per_Month[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
	int day_count = 0;

	day_count += (d2.year - d1.year) * 365; // Add 365 times the difference in years
	day_count += (days_Passed_Per_Month[d2.month - 1] - days_Passed_Per_Month[d1.month - 1]); // Add the difference in days between the months
	day_count += (d2.day - d1.day); // Add the difference in days

	if (day_count < 0) day_count *= -1; // Take the absolute value of the difference in days

	return day_count;

}

bool Date::operator==(const Date & d2) const
{
	return (day == d2.day && month == d2.month && year == d2.year);
}

Date & Date::operator+=(int days)
{

	return *this;
}


std::ostream & operator<<(std::ostream & os, const Date & d)
{
	os << d.month << "/" << d.day << "/" << d.year;
	return os;
}

std::ostream & operator<<(const Date & d, std::ostream & os)
{
	os << d.month << "/" << d.day << "/" << d.year;
	return os;
}