#include <iostream>
#include <algorithm> //std::sort
#include <iterator>	 //std::size

int main() {
	int array[]{ 30, 50, 20, 10, 40 };

	std::sort(std::begin(array), std::end(array));

	for (int i{ 0 }; i < std::size(array); ++i) {
		std::cout << array[i] << '\n';
	}

	std::cout << '\n';

	return 0;
}