#include "graduatestudent.h"

const unsigned int GraduateStudent::borrowTime() const
{
	return BORROW_DAY_CAP;
}

const bool GraduateStudent::canBorrow() const
{
	if (books_borrowed.size() > BORROW_CAP) return false;
	else return true;
}

const std::string GraduateStudent::getType() const
{
	return "Graduate student";
}

const bool GraduateStudent::addToBorrowed(Book * book)
{
	// If the returned iterator of the std::unordered_multimap insert function is not end() (indicating a successful insert) print success and return true
	if (books_borrowed.insert(std::make_pair(book->callNumber(), book)) != books_borrowed.end())
	{
		book->setDueDate(borrowTime());
		std::cout << "\nThe book was added to the books_borrowed container of graduate student " << name << " successfully.\nIts due date is " << book->getDueDate() << ".";
		return true;
	}
	// Else return false and print failure
	else
	{
		std::cout << "\nThe book was not succsesfully added to the books_borrowed container of graduate student " << name << ".\n";
		return false;
	}

}

GraduateStudent::~GraduateStudent()
{
}
