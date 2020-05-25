#include <iostream>

int main(void) {

	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++)
			std::cout << "#";
		std::cout << " " << std::endl;
	}
	std::cout <<  '/n';
}