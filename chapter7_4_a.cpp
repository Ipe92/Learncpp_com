#include <iostream>
#include <tuple>

std::tuple<int, double> returnTuple() // return a tuple that contains an int and a double
{
	return std::make_tuple(5, 6.7); // use std::make_tuple() as shortcut to make a tuple to return
};

int main()
{
	auto[a, b] = returnTuple();	// Used structured binding declaration to put results of tuple in variables a and b (c++17)
	std::cout << a << ' ' << b << '\n';

	return 0;
}