/*4) Write a function to print a C-style string character by character. Use a pointer to step through each character of the string and print that character. Stop when you hit a null terminator. Write a main function that tests the function with the string literal “Hello, world!”.

Hint: Use the ++ operator to advance the pointer to the next character.*/

#include <iostream>

void printCharacters(const char* message)
{
	while (*message != '\0')
	{
		std::cout << *message;
		++message;
	}
}

int main()
{
	printCharacters("Hello world!");
	return 0;
}