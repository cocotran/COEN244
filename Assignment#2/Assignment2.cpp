// Assignement2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Time.h"
#include "Date.h"
#include "Passenger.h"
#include "Flight.h"

int main() {

	// Question 1 Tests
	cout << "QUESTION 1\n==========\n";
	Time* object1 = new Time();
	object1->setTimePartA(5, 30, 23, "PM");
	object1->printTime();
	object1->printTimePartB();

	Time* object2 = new Time ();
	object2->setTime(2, 4, 6);
	object2->printTime();
	object2->printTimePartB();

	// Question 2 Tests
	cout << "\nQUESTION 2\n==========\n";
	Date* Feb1st2018 = new Date();
	Feb1st2018->setDate(1, 2, 2018);
	Feb1st2018->printDate();
	std::cout << Feb1st2018->monthinletters() << std::endl;

	Date* Nov30th2019 = new Date();
	Nov30th2019->setDate(30, 11, 2019);

	std::cout << "between dates is " << Date::daysBetweenDates(Feb1st2018, Nov30th2019) << std::endl;

	// Question 3 Tests
	cout << "\nQUESTION 3\n==========\n";
	Passenger *passenger1 = new Passenger();
	passenger1->setPassengerInfo(7, "James Bond", "MI 6 London", "514 123 4567", Date(20, 6, 2000));

	Passenger *passenger2 = new Passenger();
	passenger2->setPassengerInfo(9, "Le Chiffre", "Casino Royale", "514 121 9897", Date (12,4,1998));

	Passenger *passenger3 = new Passenger();
	passenger3->setPassengerInfo(4, "Miss Moneypenny", "MI 6 Head quarters", "514 789 2314", Date(23, 8, 1952));

	Passenger *passenger4 = new Passenger();
	passenger4->setPassengerInfo(3, "Auric Goldfinger", "Miami Beach", "514 456 1234", Date(14, 1, 1969));

	Passenger *passenger5 = new Passenger();
	passenger5->setPassengerInfo(5, "Dr. Julius No", "Crab Key", "514 678 8254", Date(2, 7, 1973));

	passenger1->printPassenger();
	passenger2->printPassenger();

	// Question 4 Tests

	cout << "\nQUESTION 4\n==========\n";
	Date *departureDate1 = new Date(20, 7, 2019);
	Time *departureTime1 = new Time();
	departureTime1->setTime(20, 18, 20);

	Date *arrivalDate1 = new Date(21, 7, 2019);
	Time *arrivalTime1 = new Time();
	arrivalTime1->setTime(20, 18, 19);

	Flight *airCanadaMontrealToNewYork = new Flight(111, "New York City", departureDate1, departureTime1, arrivalDate1, arrivalTime1);
	cout << "Flight time in hours = " << airCanadaMontrealToNewYork->flightDurationInHours() << std::endl;

	airCanadaMontrealToNewYork->addPassenger(passenger1);
	airCanadaMontrealToNewYork->addPassenger(passenger2);
	airCanadaMontrealToNewYork->addPassenger(passenger3);
	airCanadaMontrealToNewYork->addPassenger(passenger4);
	airCanadaMontrealToNewYork->addPassenger(passenger5);

	airCanadaMontrealToNewYork->printPassengerList();

	cout << "Is James Bond on the flight? " << airCanadaMontrealToNewYork->passengerExists(7) << std::endl;

	cout << "Number of seats available = " << airCanadaMontrealToNewYork->availableSeatCount() << std::endl;
	
	cout << "Remove a passenger\n";
	airCanadaMontrealToNewYork->removePassenger(3);
	airCanadaMontrealToNewYork->printPassengerList();


	Date *departureDate2 = new Date(2, 8, 2019);
	Time *departureTime2 = new Time();
	departureTime2->setTime(20, 18, 20);

	Date *arrivalDate2 = new Date(2, 8, 2019);
	Time *arrivalTime2 = new Time();
	arrivalTime2->setTime(21, 18, 20);


	Flight *airCanadaMontrealToBoston = new Flight(888, "Boston", departureDate2, departureTime2, arrivalDate2, arrivalTime2);
	cout << "Flight time to Boston in hours = " << airCanadaMontrealToBoston->flightDurationInHours() << std::endl;

	airCanadaMontrealToBoston->addPassenger(passenger1);
	airCanadaMontrealToBoston->addPassenger(passenger2);
	airCanadaMontrealToBoston->addPassenger(passenger3);
	airCanadaMontrealToBoston->addPassenger(passenger4);
	airCanadaMontrealToBoston->addPassenger(passenger5);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
