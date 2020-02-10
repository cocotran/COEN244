#include <iostream>
#include "librarymanagementsystem.h"
#include "borrower.h"
#include "facultymember.h"
#include "graduatestudent.h"
#include "undergraduatestudent.h"
#include "date.h"
#include "book.h"

int main()
{
	LibraryManagementSystem LMS;
	
	// 1. Add 10 books to the library.
	std::cout << "\n---1. Add 10 books to the library---\n";
	LMS.addBook(Book(111, "The Lord of the Rings: Return of the King"));
	LMS.addBook(Book(222, "The Bhagavad Gita"));
	LMS.addBook(Book(333, "The Prince"));
	LMS.addBook(Book(444, "The Upanishads, 2nd Edition"));
	LMS.addBook(Book(555, "War and Peace"));
	LMS.addBook(Book(666, "The Divine Comedy"));
	LMS.addBook(Book(777, "The Chronology of Ancient Kingdoms Amended"));
	LMS.addBook(Book(888, "The Problem of Increasing Human Energy"));
	LMS.addBook(Book(999, "Tao Te Ching"));
	LMS.addBook(Book(1111, "A History of Electromagnetism"));

	// 2. Register 5 borrowers of different types with the library

	// Formatting for better demonstration
	std::cout << "\n\n---2. Register 5 borrowers of each different type with the library---\n\n" <<
		"-------------------------------------------------------------------------------------------------------------\n\n"; 

	// a) Create 5 borrowers of type UnderGraduateStudent
	UnderGraduateStudent * new_undergrads = new UnderGraduateStudent[5]
	{
		UnderGraduateStudent(1,"Brandon O'Connnell"),
		UnderGraduateStudent(2,"Mark Reiner"),
		UnderGraduateStudent(3, "Peter Tagur"),
		UnderGraduateStudent(4, "Yiwei Xi"),
		UnderGraduateStudent(5, "John Donovan")
	};

	// b) Create 5 borrowers of type GraduateStudent
	GraduateStudent * new_grads = new GraduateStudent[5]
	{
		GraduateStudent(101,"Vignesh Prabhahar"),
		GraduateStudent(102,"Dhanesh Patel"),
		GraduateStudent(103, "Jonas Wagner"),
		GraduateStudent(104, "Lucas Langer"),
		GraduateStudent(105, "Prita McCartney")
	};

	// c) Create 5 borrowers of type FacultyMember
	FacultyMember * new_faculty = new FacultyMember[5]
	{
		FacultyMember(201,"Mohammed Abboud"),
		FacultyMember(202,"Brodie Finlay"),
		FacultyMember(203, "Donald Roetgen"),
		FacultyMember(204, "Sariswati Agarwal"),
		FacultyMember(205, "Raphael Elliot")
	};

	// Register these new borrowers with the library
	for (int i = 0; i < 5; ++i)
	{
		LMS.registerBorrower(new_undergrads + i);
		LMS.registerBorrower(new_grads + i);
		LMS.registerBorrower(new_faculty + i);
	}

	std::cout << "\n-------------------------------------------------------------------------------------------------------------\n"; 

	// 3. Two different borrowers loan at least 3 books from the catalog.
	std::cout << "\n---3. Loan to two different borrowers at least 3 books from the catalog---\n";
	// Brandon O'Connell loans The Upanishads 2nd Edition, War and Peace, The Prince, and then attempts to loan The Upanishads Again (to demonstrate the program's ability to handle "no copies left" scenario
	LMS.loanToBorrower(1, 444);
	LMS.loanToBorrower(1, 555);
	LMS.loanToBorrower(1, 333);
	// Attempt to loan non-existent book
	LMS.loanToBorrower(1, 4534592);

	// Attempt to loan The Upanishads 2nd Edition to Vignesh Prabhar (no copies should be available since it has already been loaned to Brandon O'Connell)
	LMS.loanToBorrower(101, 444);
	
	// Vignesh Prabhahar loans The Problem of Increasing Human Energy, The Divine Comedy, The Bhagavad Gita, and A History of Electromagnetism
	LMS.loanToBorrower(101, 888);
	LMS.loanToBorrower(101, 666);
	LMS.loanToBorrower(101, 222);
	LMS.loanToBorrower(101, 1111);

	// 4. One borrower returns a book to the library
	std::cout << "\n---4. One borrower returns a book from the library---\n";
	// Vignesh Prabhahar returns The Divine Comedy
	LMS.returnFromBorrower(101, 666);

	// 5. Print a list of the books currently in the catalog, including all necessary information (call number, title, on-shelf/on-loan, borrower name and return due date)
	std::cout << "\n---5. Print a list of the books currenttly in the catalog, with necessary info---\n";
	
	LMS.printCatalogue();

	// 6. Print a list of all registered borrowers; for each borrower, print their id, name, and list of books currently borrowed
	std::cout << "\n---6. Print a list registered borrowers: include their ID, name, & a list of books currently borrowed---\n";

	LMS.printRegisteredBorrowers();
	
	// Deallocate memory on the heap
	delete[] new_undergrads; 
	new_undergrads = nullptr;
	delete[] new_grads; 
	new_grads = nullptr;
	delete[] new_faculty; 
	new_faculty = nullptr;

}

