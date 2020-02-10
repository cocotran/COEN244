#include "pch.h"
#include "Flight.h"


Flight::Flight(int flightNumber, string arrivalCity, Date *departureDate, Time *departureTime, Date *arrivalDate, Time *arrivalTime)
{
	flightId = flightNumber;
	city = arrivalCity;
	startDate = departureDate;
	startTime = departureTime;
	endDate = arrivalDate;
	endTime = arrivalTime;

	passengerCount = 0;
	passengers = new Passenger*[maxSeats];

}

Flight::~Flight()
{
	for (int i = 0; i < passengerCount; i++)
	{
		delete passengers[i];
		passengers[i] = NULL;
	}
	
	delete []passengers;
	passengers = (Passenger **)NULL;
	passengerCount = 0;
}

int Flight::flightDurationInHours()
{
	long int departureTimestamp = (startDate->GetDayTimestamp() * 24 * 3600) + startTime->getSecondTimeStamp(); // Get the number of seconds of the Departure time

	long int arrivalTimestamp = (endDate->GetDayTimestamp() * 24 * 3600) + endTime->getSecondTimeStamp(); // Get the number of seconds of the Arrival time

	long int differenceTime = arrivalTimestamp - departureTimestamp;

	return differenceTime / 3600; // convert the seconds back to hours by dividing by 3600 seconds per hour
}

void Flight::addPassenger(Passenger *p)
{
	if (passengerCount < maxSeats)
	{
		passengers[passengerCount] = p;
		passengerCount++;
	}
	else
	{
		cout << "There is not enough room on the plane to add any more passengers\n";
	}
}

void Flight::printPassengerList()
{
	for (int i = 0; i < passengerCount; i++)
	{
		passengers[i]->printPassenger();
	}
}

bool Flight::passengerExists(int passengerId)
{
	for (int i = 0; i < passengerCount; i++)
	{
		if (passengers[i]->getPassengerId() == passengerId)
		{
			return true;
		}
	}
	return false;
}

int Flight::availableSeatCount()
{
	return maxSeats - passengerCount;
}


void Flight::removePassenger(int passengerId)
{
	int foundPosition = -1;
	for (int i = 0; i < passengerCount; i++)
	{
		if (passengers[i]->getPassengerId() == passengerId)
		{
			foundPosition = i;
			break;
		}
	}

	if (foundPosition < 0)
	{
		// The passenger could not be found
		return;
	}

	// Copy all remaining items down by one
	for (int i = foundPosition + 1; i < passengerCount; i++)
	{
		passengers[i - 1] = passengers[i];
	}
	passengers[passengerCount - 1] = NULL;
	passengerCount--;
}




// Another way to manage the array would be to set the array values to NULL
// Whenever a passenger is added, then look for a pointer set to NULL and add it at that location in the array
// When we want to remove an item, delete it and set the pointer that pointed to the item to NULL