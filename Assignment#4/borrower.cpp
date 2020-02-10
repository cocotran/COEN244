#include "borrower.h"

const unsigned int Borrower::getID() const
{
	return id;
}

const unsigned int Borrower::borrowTime() const
{
	return 10; // Default value. This function is overriden in derived classes according to borrowing privileges
}

const bool Borrower::canBorrow() const
{
	return true; // Default, overriden in derived classes
}

const std::string Borrower::getName() const
{
	return name;
}

const std::string Borrower::getType() const
{
	return "Borrower";
}
const bool Borrower::addToBorrowed(Book * book)
{
	// If the returned iterator of the std::unordered_multimap insert function is not end() (indicating a successful insert) print success and return true
	if (books_borrowed.insert(std::make_pair(book->callNumber(), book)) != books_borrowed.end())
	{
		std::cout << "\nThe book was added to the borrower's books_borrowed container successfully.\n";
		return true;
	}
	// Else return false and print failure
	else
	{
		std::cout << "\nThe book was not successfully added to the borrower's books_borrowed container.\n";
		return false;
	}

}

const bool Borrower::removeFromBorrowed(unsigned int call_number)
{
	//Record the original size
	auto original_size = books_borrowed.size();

	//Erase the book
	books_borrowed.erase(books_borrowed.find(call_number));

	// If an element was successfully erased, print success and return true.
	if (books_borrowed.size() < original_size)
	{
		std::cout << "\n\nThe book was removed from the borrower's books_borrowed container successfully.\n";
		return true;
	}
	// Else return false and print failure
	else
	{
		std::cout << "\n\nThe book was not successfully removed from the borrower's books_borrowed container.\n";
		return false;
	}
}

void Borrower::printBorrowedBooksData() const
{
	// If the borrower is currently borrowing any books, continue
	if (books_borrowed.size() > 0)
	{

		std::cout << std::endl << std::setw(25) << std::left << "Call Number" << std::setw(50) << "Title" << "Due Date\n" <<
			"--------------------------------------------------------------------------------------";

		for (auto it = books_borrowed.begin(); it != books_borrowed.cend(); ++it)
			std::cout << std::endl << std::left << std::setw(25) << (it->first) << std::setw(50) << (it->second->getTitle()) << (it->second->getDueDate()) << std::endl <<
			"--------------------------------------------------------------------------------------" << std::endl; 
	}
	// Else print 'none'
	else std::cout << "None.\n";

}

const bool Borrower::isBorrowing(unsigned int call_number) const
{
	if (books_borrowed.count(call_number) != 0) return true;
	else return false;
}


void Borrower::printBorrowedBooksTitles() const
{
	if (books_borrowed.size() > 0)
	{
		for (auto it = books_borrowed.begin(); it != books_borrowed.cend(); ++it)
		{
			if (it != (--books_borrowed.cend())) std::cout << "\"" << it->second->getTitle() << "\", ";
			else std::cout << "\"" << it->second->getTitle() << "\"";
		}
	}

	else std::cout << "None";
}

Borrower::~Borrower()
{

}


