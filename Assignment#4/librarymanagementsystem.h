#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "borrower.h"
#include "date.h"
#include "book.h"
#include <unordered_map>
#include <map>


// Typedef used to avoid having to retype this iterator declaration for the complex multimap container type
typedef std::multimap<unsigned int, Book>::iterator catalogue_iterator;

// Typedef used to increase the intiutive readability of the addBook function
typedef std::tuple<std::string, bool, Borrower *, Date> catalogue_entry;

// Templatized function used here for extensibility purposes, considering the data structures used in the program are often STL maps. May be useful in the future for re-use
template<typename I, typename T>
void remove(const I & key, T& multi_map)
{
	typename T::iterator it = multi_map.find(key);
	multi_map.erase(it);    
}

// Struct to allow checkAvailability function to return two pieces of information (iterator location of first available copy of book in catalog, whether on shelf or not)
struct available_copy
{
	catalogue_iterator it;
	bool available;
};

class LibraryManagementSystem
{
public:

	LibraryManagementSystem();

	void addBook(Book);
	void removeBook(unsigned int); 
	void registerBorrower(Borrower *); // Pointer to borrower is passed. Borrowers exist elsewhere (in main) where they are dynamically instantiated and deleted.
	void loanToBorrower(unsigned int borrower_ID, unsigned int call_number);
	void returnFromBorrower(unsigned int borrower_ID, unsigned int call_number);
	void printCatalogue() const;
	void printRegisteredBorrowers() const;
	void booksLoanedTo(unsigned int borrower_ID) const;
	const Date getReturnDate(unsigned int call_number) const;
	available_copy checkBorrowAvailability(unsigned int call_number);

	~LibraryManagementSystem();

private:

	std::multimap<unsigned int, Book> catalogue; // Multimap of information about books (title, availability, borrower name, r
	std::map<unsigned int, Borrower *> borrower_data; // Pointers to Borrowers sorted as key-value pairs by unique ID. The value of these objects does not exist here. They are istantiated dynamically, and then deleted in main.cpp

};

#endif
