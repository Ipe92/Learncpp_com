#include <iostream>

void foo(int*& p)
{

}

int main()
{
	char* chPtr;
	int* iPtr;
	struct Something
	{
		int nX, nY, nZ;
	};
	Something* somethingPtr;

	std::cout << sizeof(chPtr) << '\n';
	std::cout << sizeof(iPtr) << '\n';
	std::cout << sizeof(somethingPtr) << '\n';

	return 0;
}