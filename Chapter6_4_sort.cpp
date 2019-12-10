#include <iostream>
#include <utility>

// actually swap
int main() {
	int x = 2;
	int y = 4;
	std::cout << "Before swap: x = " << x << ", y = " << y << '\n';

	std::swap(x, y);

	std::cout << "Before swap: x = " << x << ", y = " << y << '\n';


	return 0;
}