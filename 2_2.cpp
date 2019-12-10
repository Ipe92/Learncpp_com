// 2.2 — Function return values - Fixing our challenge program
#include <iostream>

int getValueFromUser() {
	std::cout << "Enter an integer: " << '\n';
	int input{};
	std::cin >> input;
	return input;
}

int main()
{
	int num{ getValueFromUser() };
	std::cout << " doubled is:: " << num * 2 << '\n';
	return 0;
}

