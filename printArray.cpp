#include <iostream>
#include <iterator>

// Actually quiz 2 of chapter 6.3

int main() {
	int userValue{};
	do
	{
		std::cout << "Enter value between 1-9:";
		std::cin >> userValue;

		if (std::cin.fail())
			std::cin.clear();

		std::cin.ignore(32767, '\n');

	} while ((userValue < 1) || (userValue > 9));

	int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	const int arrayLength = std::size(array);

	for (int i = 0; i < arrayLength; ++i)
		std::cout << array[i] << " ";

	std::cout << "\n";

	for (int i = 0; i < arrayLength; ++i) {
		if (array[i] == userValue) {
			std::cout << "Your value was:" << userValue << "\n";
			std::cout << "Index of that value is:" << i << "\n";
		}
	}
	return 0;
}