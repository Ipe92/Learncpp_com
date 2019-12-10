#include <iostream>
#include <functional>

int foo()
{
	return 5;
}

int goo()
{
	return 6;
}

int main()
{
	/*
	int (*fcnPtr)(){ foo }; // fcnPtr points to function foo
    fcnPtr = goo; // fcnPtr now points to function goo
	*/

	// declare function pointer that returns an int and takes no parameters
	std::function<int()> funcPtr{ foo }; 

	funcPtr = goo; // fncPtr now points to function goo
	std::cout << funcPtr() << '\n'; // call the function just like normal

	return 0;
}