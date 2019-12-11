#include <iostream>

void printBinary(int x)
{
	// Termination case
	if (x == 0)
		return;

	// Recurse to the next bit
	printBinary(x / 2);

	// Print out the remainders (in reverse order)
	std::cout << x % 2;
}

int main()
{
	int x;
	std::cout << "Enter positive integer: ";
	std::cin >> x;

	printBinary(x);

	return 0;
}