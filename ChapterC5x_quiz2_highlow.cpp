#include <iostream>
#include <random>
#include <ctime>

int getGuess(int count)
{
	while (true)
	{
		std::cout << "Guess #" << count << ": ";
		int guess;
		std::cin >> guess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else if (guess > 100)
		{
			std::cout << "Please pick smaller number than 100\n";
		}
		else if (guess < 0)
		{
			std::cout << "Please pick positive number\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return guess;
		}
	}
}

bool playGame(int guesses, int number)
{
	for (int count{ 1 }; count <= guesses; ++count)
	{
		int guess{ getGuess(count) };

		if (guess > number)
			std::cout << "Your guess is too high.\n";
		else if (guess < number)
			std::cout << "Your guess is too low.\n";
		else
			return true;
	}
	return false;
}

bool playAgain()
{
	char ch;
	do {
		std::cout << "Would you like to play again(y/n)? ";
		std::cin >> ch;
	} while (ch != 'y' && ch != 'n');
	if (ch == 'y')
		return true;
	if (ch == 'n')
		return false;
}

int main()
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // create mersenne twister and seed it

	// create distribution for integers with [1; 100] range
	std::uniform_int_distribution die{ 1, 100 };

	constexpr int guesses{ 7 };

	do
	{
		int number{ die(mersenne) };	// user guesses this rng number

		std::cout << "Let's play a game. I'm thinking of a number between 1-100. You have " << guesses << " tries to guess what it is.\n";

		bool won{ playGame(guesses, number) };
		if (won)
			std::cout << "Correct! You win!\n";
		else
			std::cout << "Sorry, you lose. The correct number was " << number << "\n";
	} while (playAgain());

	std::cout << "Thank you for playing.\n";

	return 0;
}