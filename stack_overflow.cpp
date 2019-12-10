#include <iostream>

void foo()
{
	foo();
}

int main()
{
	//int stack[100000000000000];
	//std::cout << "hi";

	foo();
	return 0;
}