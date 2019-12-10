/*3) Write your own function to swap the value of two integer variables. Write a main() function to test it.

Hint: Use reference parameters*/

#include <iostream>

void swap(int& x, int& y)
{
	int temp{};
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int first = 5;
	int second = 10;
	std::cout << "first is:" << first << " and second is:" << second << '\n';
	swap(first, second);
	if (first == 10 && second == 5)
		std::cout << "It works!";
	else
		std::cout << "It's broken!";

	std::cout << "first is:" << first << " and second is:" << second << '\n';

	return 0;
}