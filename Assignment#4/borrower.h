#ifndef BORROWER_H
#define BORROWER_H

#include "book.h"
#include "date.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

class Book;
class Borrower
{
public:
	Borrower() {};

	Borrower(unsigned int id, std::string name) : id(id), name(name) {};
	const unsigned int getID() const;
	const std::string getName() const;
	virtual const std::string getType() const;
	virtual const bool canBorrow() const;
	virtual const unsigned int borrowTime() const;
	virtual const bool addToBorrowed(Book * book);
	const bool removeFromBorrowed(unsigned int);
	const bool isBorrowing(unsigned int) const;
	void printBorrowedBooksData() const;
	void printBorrowedBooksTitles() const;

	virtual ~Borrower();

protected:
	unsigned int id;
	std::string name;
	std::multimap<unsigned int, Book *> books_borrowed;
};

#endif