#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H

#include "borrower.h"

class UnderGraduateStudent :
	public Borrower
{

	public:
		UnderGraduateStudent() : Borrower(0, "Unset") {};
		UnderGraduateStudent(unsigned int id, std::string name) : Borrower(id, name) {};
		const bool canBorrow() const;
		const bool addToBorrowed(Book *);
		const unsigned int borrowTime() const;
		const std::string getType() const;
		~UnderGraduateStudent();

	
	private:
		const static unsigned int BORROW_CAP = 10;
		const static unsigned int BORROW_DAY_CAP = 28; // (4 weeks * 7 days)


};


#endif
