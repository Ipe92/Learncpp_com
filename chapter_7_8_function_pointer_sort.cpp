#include <iostream>
#include <utility>

// Note the user-defined comparison is the third parameter
void SelectionSort(int* array, int size, bool (*comparisonFcn)(int, int) = ascending)
{
	// Step through each element of the array
	for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
	{
		// bestIndex is the index of the smallest/largest element we've encountered so far
		int bestIndex{ startIndex };

		// Looks for smallest/largest element remaining in the array (starting at startIndex+1)
		for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
		{
			// If the current element is smaller/larger than our previously found smalles
			if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
				// This is the new smallest/largest number for this iteration
				bestIndex = currentIndex;
		}

		// Swap our start element with our smallest/largest number for this iteration 
		std::swap(array[startIndex], array[bestIndex]);
	}
}

bool ascending(int x, int y)
{
	return x > y; // swap if the first element is greater than the second
}

bool descending(int x, int y)
{
	return x < y; // swap if the second element is greater than the first
}

bool evensFirst(int x, int y)
{
	// if x is even and y is odd, x goes first (no swap needed)
	if ((x % 2 == 0) && !(y % 2 == 0))
		return false;

	// if x is odd and y is even, y goes first (swap needed)
	if (!(x % 2 == 0) && (y % 2 == 0))
		return true;

	// otherwise sort in ascending order
	return ascending(x, y);
}

void printArray(int* array, int size)
{
	for (int index{ 0 }; index < size; ++index)
		std::cout << array[index] << ' ';
	std::cout << '\n';
}

int main()
{
	int array[9]{ 3,7,9,5,6,1,8,2,4 };

	// Sort the array in descending order using the descending() function
	SelectionSort(array, 9, descending);
	printArray(array, 9);

	// Sort the array in ascending order using the ascending() function
	SelectionSort(array, 9, ascending);
	printArray(array, 9);

	SelectionSort(array, 9, evensFirst);
	printArray(array, 9);

	return 0;
}