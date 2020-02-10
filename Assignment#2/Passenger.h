#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Passenger
{
public:
	Passenger();

	void setPassengerInfo(int id, string passengerName, string passengerAddress, string passengerTelephone, Date const &dob);
	void setPassengerId(int id);
	void setName(string name);
	void setAddress(string address);
	void setTel(string tel);
	void setDateOfBirth(Date &dob);

	int getPassengerId();
	string getName();
	string getAddress();
	string getTel();
	Date &getDateOfBirth();

	void printPassenger();

private:
	int passengerId;
	string name;
	string address;
	string telephoneNumber;
	Date dateOfBirth;
};

