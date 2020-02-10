#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "borrower.h"

class GraduateStudent :
	public Borrower
{

public:
	GraduateStudent() : Borrower(0, "Unset") {};
	GraduateStudent(unsigned int id, std::string name) : Borrower(id, name) {};
	const bool canBorrow() const;
	const unsigned int borrowTime() const;
	const bool addToBorrowed(Book *);
	const std::string getType() const;
	~GraduateStudent();

private:
	const static unsigned int BORROW_CAP = 20;
	const static unsigned int BORROW_DAY_CAP = 42; // (6 weeks * 7 days)

};


#endif