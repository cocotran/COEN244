#pragma once
class Date
{
public:
	Date(int = 1, int = 1, int = 2000); // sets day, month, year
	void printDate() const; // print date to the screen
	void setDate(int d, int m, int y);
	const char* monthinletters();
	static int daysBetweenDates(Date* date1, Date* date2);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

	long int GetDayTimestamp() const;

private:
	int day;
	int month;
	int year;

};

