#include <iostream>
//#include <cstddef> //NULL

void doSomething(std::nullptr_t)
{
	std::cout << "In doSomething()\n";
}

int main()
{
	doSomething(nullptr);

	return 0;
}