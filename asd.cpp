#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

int main()
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // create mersenne twister and seed it

		// create distribution for integers with [1; 100] range
	std::uniform_int_distribution die{ 48, 127 };

	constexpr int guesses{ 7 };

	int number{ die(mersenne) };	// user guesses this rng number
	int number2{ die(mersenne) };
	int number3{ die(mersenne) };

	std::cout << number << '\n' << number2 << '\n' << number3;

}