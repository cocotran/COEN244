#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>
#include <ctime>
#include <chrono>


class Date {

public:

	Date(); // default to today's date
	Date(int); // construct Date as today's date +/- integer amount of days passed as argument
	bool operator==(const Date &d2) const; // to simplify date comparison 
	Date & operator+=(int);
	friend std::ostream & operator<<(std::ostream & os, const Date & d);
	friend std::ostream & operator<<(const Date & d,std::ostream & os);

	void addDays(int days);
	int differenceInDays(const Date& d1, const Date& d2) const; // Can be useful when calculating # of days late and during other library tasks. Included for extensibility.
														
private:

	int day;
	int month;
	int year;
	tm current_time;

};
#endif /* DATE_H_ */
