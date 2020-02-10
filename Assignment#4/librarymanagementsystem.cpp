#include "librarymanagementsystem.h"

LibraryManagementSystem::LibraryManagementSystem() 
{
	// Just for utility
	time_t t = time(NULL);
	tm buffer;
	localtime_s(&buffer, &t); // USE FOR WINDOWS
    // localtime_r(&t, &buffer); // USE FOR LINUX
	std::cout << "Library Management System opened at " << buffer.tm_hour << ":" << buffer.tm_min << ":" << buffer.tm_mday << ", " << buffer.tm_mon + 1 << "/" << buffer.tm_mday << "/" << buffer.tm_year + 1900 << std::endl;
};

// Check if there are any copies of a book in the catalogue with on_shelf = true to loan to the borrower. Return false if no copies are on shelf, true if available.
available_copy LibraryManagementSystem::checkBorrowAvailability(unsigned int call_number)
{
	// Declare pair of iterators to declinate the beginning and ending of the range of values matching the call number
	std::pair <catalogue_iterator, catalogue_iterator> range;
	range = catalogue.equal_range(call_number);

	for (catalogue_iterator i = range.first; i != range.second; ++i)
	{
		// If an available copy is found at this location, return the location and "true"
		if (i->second.getOnShelf() == true)
		{
			return available_copy{i, true};
		}

	}
	// else if no available copies, return the first iterator in the equal_range with "false"
	return available_copy{ range.first, false };

}


void LibraryManagementSystem::booksLoanedTo(unsigned int borrower_ID) const
{
	// Find the borrower ID in the list, if it is the last element and the iterator is 'pointing' to end() (1 'address' after the last element), decrement by 1 to point to the last element
	auto it = borrower_data.find(borrower_ID);
	if (it == borrower_data.end()) --it;

	// For clarity, set a pointer to the Borrower object in the borrower_ID_list container whose pair the iterator points to
	Borrower * borrower = it->second;

	// Call the printBorrowedBooks function of this Borrower object
	std::cout << "\nBooks currently loaned to " << borrower->getName() << ", " << " Borrower ID "<< borrower_ID << ":";
	borrower->printBorrowedBooksData();

}


void LibraryManagementSystem::addBook(Book bk)
{
	catalogue.insert(std::make_pair(bk.callNumber(), bk));
	std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
	std::cout << "A copy of \"" << bk.getTitle() << "\" has been added to the catalogue. The # of copies of this book in the catalogue is:  " << catalogue.count(bk.callNumber());
}

void LibraryManagementSystem::removeBook(unsigned int call_number)
{
	remove(call_number, catalogue);
}

void LibraryManagementSystem::registerBorrower(Borrower * b)
{
	// Check if borrower doesn't already exist
	if (borrower_data.count(b->getID()) == 0)
	{
		std::cout << b->getType() << " " << b->getName() << ", ID " << b->getID() << " has been registered with the system successfully.\n";
		borrower_data.insert(std::make_pair(b->getID(), b));
	}

	else std::cout << "\nA borrower by that ID already exists in the system.\n";

}

void LibraryManagementSystem::loanToBorrower(unsigned int borrower_ID, unsigned int call_number)
{
	// Proceed only if the borrower exists
	if (borrower_data.count(borrower_ID) > 0)
	{
		// If the call number exists in the catalogue for at least 1 copy, continue
		if (catalogue.count(call_number) > 0)
		{
			// Find the borrower ID in the list, if it is the last element and the iterator is 'pointing' to end() (1 'address' after the last element), decrement by 1 to point to the last element
			auto it = borrower_data.find(borrower_ID);
			if (it == borrower_data.end()) --it;

			// Do the same here when finding call_number in the catalogue
			available_copy copy = checkBorrowAvailability(call_number);
			if (copy.it == catalogue.end()) --copy.it;
			
			// Define a string for the book's title to improve readibility
			std::string title = copy.it->second.getTitle();

			// Define a pointer to the borrower to improve readability
			Borrower * borrower = it->second;

			std::cout << "\nAttempting to loan \"" << title << "\" to borrower " << borrower->getName() << ", ID number " << borrower->getID() << "...";

			if (copy.available) 
			{
			
				std::cout << " A copy of \"" << title << "\" is on the shelf and available to loan.\n";

				// If the borrower's canBorrow function determines that they can borrow (books less than capacity, etc.)
				if (borrower->canBorrow())
				{
					// Add the book information to the borrower's borrowed_books container, and if the addition was successfull...
					if (borrower->addToBorrowed(&copy.it->second))
					{
						// Set the appropriate due date in the catalogue
						copy.it->second.setDueDate( Date(borrower->borrowTime()) );

						// Make the current borrower for this copy equal to the borrower passed by parameter for this function call
						copy.it->second.setBorrower(borrower);

						// Set on_shelf to false, since the item has been loaned out.
						copy.it->second.setOnShelf(false);

					}

				}
				
				else std::cout << "Loan failed. Borrower has reached borrow capacity.\n";

			}

			else std::cout << " There are no copies of \"" << copy.it->second.getTitle() << "\" available for loan.\n";

		}

		else std::cout << "\nCall number " << call_number << " is not in the catalogue.\n";

	}
	
	else std::cout << " No borrower with that ID number exists.\n";
	std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";

}

void LibraryManagementSystem::returnFromBorrower(unsigned int borrower_ID, unsigned int call_number)
{
	// Proceed only if the borrower exists
	if (borrower_data.count(borrower_ID) > 0)
	{
		// Find the borrower ID in the list, if it is the last element and the iterator is 'pointing' to end() (1 'address' after the last element), decrement by 1 to point to the last element
		auto it = borrower_data.find(borrower_ID);
		if (it == borrower_data.end()) --it;

		// Declare a borrower pointer to improve readibility
		Borrower * borrower = it->second;

		// Proceed only if the call number exists in the catalogue
		if (catalogue.count(call_number) > 0)
		{
			// Proceed only if a book by that call_number is currently loaned out to the borrower with id=borrower_ID
			if (borrower->isBorrowing(call_number))
			{
				// Assign book's title to a temporary string variable to improve readability
				std::string title = catalogue.find(call_number)->second.getTitle();

				// Find the copy in the catalogue which is loaned to this borrower
				catalogue_iterator copy;
				for (auto it = catalogue.begin(); it != catalogue.cend(); ++it)
				{
					if (it->first == call_number && (it->second.getBorrower()) == borrower ) copy = it;
				}

				std::cout << "\nAttempting to return \"" << title << "\" from borrower " << borrower->getName() << ", ID number " << borrower->getID() << "...";
				
				// If the book was successfully returned and removed from the borrower's books_borrowed , set on_shelf to true for that copy
				if (borrower->removeFromBorrowed(call_number)) copy->second.setOnShelf(true);

			}

			else std::cout << " The book with call number " << call_number << " is not currently loaned to the borrower with ID number " << borrower_ID << "; therefore, the return cannot be made.\n ";

		}

		else std::cout << " There are no books with that call number on or off shelf at this library.\n";

	}

	else std::cout << " No borrower with that ID number exists.\n";
	std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";

}

void LibraryManagementSystem::printCatalogue() const
{
	std::cout << "\nCatalogue:\n" << std::left << std::setw(15) << "Call Number" << std::setw(50) << "Title" << std::setw(10) << "Status" << std::setw(20) << "Borrower" << std::setw(12) << "Due Date";

	for (auto & it : catalogue)
	{

		std::cout << "\n-------------------------------------------------------------------------------------------------------------\n" <<
		std::setw(15) << it.first << std::setw(50) << it.second.getTitle() << std::setw(10) << (it.second.getOnShelf()) ? "On shelf" : "On loan";

		// If the object is on loan, print the borrower name of the copy and the due date
		if (!it.second.getOnShelf()) std::cout << std::setw(20) <<  (it.second.getBorrower()->getName()) << it.second.getDueDate();

	}

	std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";

}

void LibraryManagementSystem::printRegisteredBorrowers() const
{

	std::cout << "\nList of borrowers' ID numbers, names, and books currently borrowed\n--------------------------------------------\n";

	for (auto & it : borrower_data)
	{

		std::cout << "ID number: " << it.second->getID();
		std::cout << "\nName: " << it.second->getName();
		std::cout << "\nBooks currently borrowed: "; it.second->printBorrowedBooksTitles();
		std::cout << "\n--------------------------------------------\n";

	}

}

const Date LibraryManagementSystem::getReturnDate(unsigned int call_number) const
{
	// If the call number exists in the catalogue, continue; else, print that the book isn't in the library's catalogue
	if (catalogue.count(call_number) > 0)
	{
		// Find the borrower ID in the list, if it is the last element in the map (iterator is 'pointing' to end()) decrement by 1 to point to the last element
		auto it = catalogue.find(call_number);
		if (it == catalogue.end()) --it;

		std::cout << "The expected return/due date for this book is " << it->second.getDueDate() << "\nA copy of the due date object has been returned.\n";
		return (it->second.getDueDate());

	} 

	else 
	{
		std::cout << "\nNo book with call number " << call_number << " exists.\n";

	}	

}

LibraryManagementSystem::~LibraryManagementSystem()
{
}
