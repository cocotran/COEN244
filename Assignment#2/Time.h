#pragma once
#include <iostream>
#include <string>

using namespace std;
class Time {
public:
	Time(); // constructor
	void setTime(int, int, int); // set hour, minute, second
	void printTime() const; // print time format h:m:s
	void setTimePartA(int, int, int, const char* AMPM);
	void printTimePartB() const;

	int getSecondTimeStamp() const; // Returns the timestamp as the number of seconds in the day

private:
	int hour; // 0 - 23 (24-hour clock format)
	int minute; // 0 - 59
	int second; // 0 - 59
};



