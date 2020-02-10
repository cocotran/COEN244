#ifndef FACULTYMEMBER_H
#define FACULTYMEMBER_H

#include "borrower.h"

class FacultyMember :
	public Borrower
{

public:
	FacultyMember() : Borrower(0, "Unset") {};
	FacultyMember(unsigned int id, std::string name) : Borrower(id, name) {};
	const bool canBorrow() const;
	const bool addToBorrowed(Book *);
	const unsigned int borrowTime() const;
	const std::string getType() const;
	~FacultyMember();

private:
	const static unsigned int BORROW_CAP = 30;
	const static unsigned int BORROW_DAY_CAP = 56; // (8 weeks * 7 days)

};

#endif

