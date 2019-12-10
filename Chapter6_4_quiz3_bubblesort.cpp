#include <iostream>
#include <iterator>	 //std::size
#include <utility>   //std::swap

int main() {
	int array[] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	const int length = std::size(array);

	for (int index = 0; index < length - 1; ++index)
	{
		int endofArrayIndex(length - index);

		bool swapped(false);

		for (int innerIndex = 0; innerIndex < endofArrayIndex - 1; ++innerIndex) {
			if (array[innerIndex] > array[innerIndex + 1])	{
				std::swap(array[innerIndex], array[innerIndex + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			std::cout << "Terminated early on iteration: " << index + 1 << '\n';
			break;
		}
	}

	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	return 0;
}