#include "book.h"

const unsigned int Book::callNumber() const
{
	return call_number;
}
const std::string Book::getTitle() const
{
	return title;
}


const bool Book::getOnShelf() const
{
	return on_shelf;
}

const Date Book::getDueDate() const
{

	return due_date;
}

const Borrower * Book::getBorrower() const
{
	return borrower;
}

void Book::setBorrower(Borrower * b)
{
	borrower = b;
}

void Book::setDueDate(const Date & d)
{
	due_date = d;
}

void Book::setOnShelf(bool bl)
{
	on_shelf = bl;
}


Book::~Book()
{
}
