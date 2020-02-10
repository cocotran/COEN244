/*

ASSIGNMENT #1 - COEN 244 SUMMER 2019
NAME: NICHOLAS JOANNETTE
ID: 27439059
PROFESSOR: DANIEL SINNIG

*/

#include <iostream>
#include <chrono>

void printArray(int * array, int sz) // Function to perform task A) Output the contents of the array
{

	std::cout << "[";

	for (int i = 0; i < sz; ++i)	
	{

		if (i == sz - 1) std::cout << *(array + i);
			else std::cout << *(array + i) << ", ";

	}

	std::cout << "]\n";

}

void nonRecursiveReverse(int * array, int size) // B) Implement a non-recursive function that reverses the contents of the array
{

	int * head = array;
	int * tail = array + size - 1;
	int temp;

	do {
		// Swap values
		temp = *head;
		*head = *tail;
		*tail = temp;

		// Increment head pointer, decrement tail pointer
		head += 1;
		tail -= 1;

		if (head == tail + 1) break; // If size was even and the last pair of elements has been swapped, break

	} while ((head != tail));

}

void recursiveReverse(int * array, int size) // C) Implement a recursive function that reverses the contents of the array
{

	int temp;

	if (size <= 1) return; // Base case, if array size is even and no more pairs to swap, quit. If odd and on middle element, return.

	else {

		int * head = array;	// Set pointer to start of array
		int * tail = array + size - 1; // Set pointer to end of array
		// Swap values
		temp = *head;
		*head = *tail;
		*tail = temp;

		recursiveReverse(head + 1, size - 2);

	}

}

void findPlateau(int * array, int sz)
{

	int * start, * finish; // Pointers for incrementing through and scanning the array

	start = array;
	finish = array + 1;

	// Plateau start & finish pointers to save location of longest plateaus
	int * p_start = start;
	int * p_finish = finish;

	int plateau_length = 1;
	int plateau_count = 1;


	while (finish < array + sz)	// While the end of the array has not been reached
	{

		while (*start == *finish) // So long as the value of the finish pointer is equal to the value to the left of it pointed to by the start pointer
		{

			++finish; // Increment the finish pointer

			if ((*start != *finish) && (finish - start >= plateau_length))	// If the plateau has ended, and the length of the plateau is longer than or equal to the largest plateau yet found
			{

				p_start = start;	// Set the plateau starting pointer to the address of start
				p_finish = finish;	// Set the plateau finish pointer to the address of finish

				if (finish - start == plateau_length) ++plateau_count; // If the length of this plateau is equal to the largest plateau yet found, increment the plateau count

				else // Else if the plateau is longer, reset the plateau count and set this new length as the largest yet found
				{

					plateau_length = p_finish - p_start;
					plateau_count = 1;

				}

			}

		}

		// Increment finish pointer and set start to 1 subscript to the left of it
		++finish;
		start = finish - 1;

	}
		
		// Print out results
	if (plateau_length == 1) plateau_count = sz; // If the longest plateau had a length of 1 element, the number of plateaus of this length is the size of the array
		std::cout << "\nThe longest occurring plateau in the array had a length of " << p_finish - p_start << ". The number of plateaus of this length in the array was: " << plateau_count << ".\n" <<
		"\nThe last detected plateau of this size in the array occurred from the array subscripts [" <<
		(p_start - array) << "] to [" << (p_finish - array - 1) << "].";
		
		std::cout << "\n\nHere are the elements of the plateau which occurred between those subscripts printed out:\n";

		printArray(p_start, plateau_length); // Output the plateau
	
}

void sortAscending(int * array, int sz)
{

	int temp;

	for (int i = 0; i < sz; ++i)
	{

		for (int j = i + 1; j < sz; ++j)
		{
			// If the element j is smaller than the element i, swap them
			if (array[j] < array[i])
			{

				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}

		}

	}
	
}

int main()
{
	
	float floatsz; // Used as a temp variable to test if user input was of type int or float
	int sz;

	std::cout << "Please enter an integer value for the size for the array \n";

	while (!(std::cin >> floatsz) || (int(floatsz * 10) % 10 != 0)) // If input has a remainder when divided by 10, it is not an integer
	{

		std::cin.clear();	// Get user input and handle for invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: \n";

	}

	sz = floatsz; // User entered integer as array size, assign this value to sz 

	if (sz == 0) // If the user entered zero for the array size, nothing can be determined - end the program.
	{
		std::cout << "You have chosen an array size of 0. No relevant information can be determined.\nGoodbye.";
		exit(0);
	}

	int * arr = new int[sz]; // Dynamically allocate array 

	// Seed rand function & populate array with pseudo-random integers between 0 and 20
	srand(time(NULL)); 
	for (int i = 0; i < sz ; ++i) 
	{
		
		*(arr + i) = rand()%20;

	}

	// A) Output the contents of the array
	std::cout << "\nHere is the original array:\n";
	printArray(arr, sz);	


	// D-1) Apply the non-recursive reversal function to the array and output its contents
	auto start = std::chrono::system_clock::now();
	nonRecursiveReverse(arr, sz); 
	auto end = std::chrono::system_clock::now();  // Used for timing the performance of the functions, for step E)

	std::cout << "\nHere are the contents of the array after being reversed by the non recursive function:\n";
	printArray(arr, sz);


	std::cout << "\nThe time elapsed during the non recursive reversal function was: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds.\n";

	std::cout << "\nHere are the contents of the array after being reversed again, this time by the recursive function:\n";

	// D-2) Apply the recursive reversal function to the reversed array and output its contents
	start = std::chrono::system_clock::now();
	recursiveReverse(arr,sz);
	end = std::chrono::system_clock::now();

	printArray(arr, sz); // Output contents

	std::cout << "\nThe time elapsed during the recursive reversal function was: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds.\n";

	// F) Determine and prints out the longest plateau & the highest & lowest subscripts
	findPlateau(arr, sz);

	// G) Sort the elements of the array in ascending order and output the contents of the array

	sortAscending(arr, sz);
	
	std::cout << "\nHere is the array after being sorted in ascending order:\n";
	printArray(arr, sz); // Output contents

	// Delete the memory on the heap and de-allocate the pointer

	delete[] arr;
	arr = nullptr;

	return 0;

}

