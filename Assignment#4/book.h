#ifndef BOOK_H
#define BOOK_H

#include "borrower.h"
#include "date.h"
#include <string>
class Borrower;

class Book
{

public:
	Book(unsigned int call_number, std::string title) : call_number(call_number), title(title), on_shelf(true) {};
	 
	const unsigned int callNumber() const;
	const std::string getTitle() const;
	const bool getOnShelf() const;
	const Date getDueDate() const;
	const Borrower * getBorrower() const;
	void setBorrower(Borrower *);
	void setDueDate(const Date &);
	void setOnShelf(bool);
	
	~Book();

private:
	unsigned int call_number;
	std::string title;
	bool on_shelf = true; // if false, is on loan
	Borrower * borrower;
	Date due_date;

};

#endif