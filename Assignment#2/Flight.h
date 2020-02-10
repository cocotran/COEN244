#pragma once
#include "Date.h"
#include "Time.h"
#include "Passenger.h"
#include <string.h>



class Flight
{
public:
	Flight(int flightNumber, string arrivalCity, Date *departureDate, Time *departureTime, Date *arrivalDate, Time *arrivalTime);
	int flightDurationInHours();
	void addPassenger(Passenger *p);
	void removePassenger(int passengerId);
	bool passengerExists(int passengerId);
	void printPassengerList();
	int availableSeatCount();

	~Flight();

private:
	int flightId;
	string city;

	Date *startDate;
	Time *startTime;

	Date *endDate;
	Time *endTime;

	int maxSeats = 100; // Default 100 seats
	int passengerCount; // Number of passengers in the passenger manifest

	Passenger **passengers;


};

