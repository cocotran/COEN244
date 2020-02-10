#include "pch.h"
#include "Passenger.h"
#include <iostream>

using namespace std;


Passenger::Passenger()
{
	passengerId = 0;
	name = "";
	address = "";
	telephoneNumber = "";
	Date dateOfBirth;
}


void Passenger::setPassengerInfo(int id, string passengerName, string passengerAddress, string passengerTelephone, Date const &dob)
{
	passengerId = id;
	name = passengerName;
	address = passengerAddress;
	telephoneNumber = passengerTelephone;
	dateOfBirth.setDate(
		dob.getDay(),
		dob.getMonth(),
		dob.getYear());
	
}

void Passenger::setPassengerId(int id)
{
	passengerId = id;
}
void Passenger::setName(string passengerName)
{
	name = passengerName;
}
void Passenger::setAddress(string passengerAddress)
{
	address = passengerAddress;
}

void Passenger::setTel(string passengerTelephone)
{
	telephoneNumber = passengerTelephone;
}

void Passenger::setDateOfBirth(Date &dob)
{
	dateOfBirth.setDate(
		dob.getDay(),
		dob.getMonth(),
		dob.getYear());
}

int Passenger::getPassengerId()
{
	return passengerId;
}

string Passenger::getName()
{
	return name;
}

string Passenger::getAddress()
{
	return address;
}

string Passenger::getTel()
{
	return telephoneNumber;
}

Date &Passenger::getDateOfBirth()
{
	return dateOfBirth;
}

void Passenger::printPassenger()
{
	cout << "id = " << passengerId << ", name = " << name << ", address = " << address << ", telephone = " << telephoneNumber << ", dob = ";
	dateOfBirth.printDate();
}