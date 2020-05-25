#include <iostream>

class IDGenerator
{
private:
	static int s_nextID;
public:
	static int getNextID(); // static member function dec
};

int IDGenerator::s_nextID{ 1 }; // static variable def
int IDGenerator::getNextID() { return s_nextID++; } // static function def

int main()
{
	for (int count{0}; count < 5; ++count)
	std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

	return 0;
}