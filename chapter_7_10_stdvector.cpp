#include <iostream>
#include <vector>

int main()
{
	std::vector<int> array{ 0,1,2 };
	array.resize(5);	//set length to 5

	std::cout << "The length is: " << array.size() << '\n';

	std::cout << "The capacity is: " << array.capacity() << '\n';

	for (auto const& element : array)
		std::cout << element << ' ';

	return 0;
}