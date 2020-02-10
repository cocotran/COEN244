#include "pch.h"
#include <iostream>
#include "Date.h"

using namespace std;

// Constructor
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
// print date
void Date::printDate() const
{
	std::cout << month << "/" << day << "/" << year << "\n";
}

void Date::setDate(int d, int m, int y) {
	month = (m >= 1 && m <= 12) ? m : 0;
	year = y;

	if (d > 0)
		switch (m) {
		case 1: case 3: case 5: case 7:case 8: case 10: case 12:
			if (d <= 31 && d > 0)
				day = d;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d <= 30)
				day = d;
			break;
		case 2:
			if (d <= 28)
				day = d;
		}
}

//part b
const char* Date::monthinletters() {

	const char* Month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const char* month_name = Month[month - 1];

	return month_name;
}
//part c
int Date::daysBetweenDates(Date* date1, Date* date2) {

	long int n1 = date1->GetDayTimestamp();
	long int n2 = date2->GetDayTimestamp();

	return (n2 - n1);

}


long int Date::GetDayTimestamp() const
{
	const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int n1 = year * 365 + day;
	for (int i = 0; i < month - 1; i++)
		n1 += daysInMonth[i];

	return n1;
}


int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}



