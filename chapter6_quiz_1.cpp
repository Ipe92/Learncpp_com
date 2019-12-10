/*1) Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows. Create an enum to identify the different types of items, and a fixed array to store the number of each item the player is carrying (use built-in fixed arrays, not std::array). The player should start with 2 health potions, 5 torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total. Have your main() function print the output of countTotalItems().*/
#include <iostream>

enum playerItems
{
	ITEM_POTION,
	ITEM_TORCH,
	ITEM_ARROW,
	MAX_ITEMS
};

int countTotalItems(int* array)
{
	int totalItems = 0;
	
	for (int index = 0; index < MAX_ITEMS; ++index)
		totalItems += array[index];
	return totalItems;
}

int main()
{
	int array[MAX_ITEMS] { 2, 5, 10 };

	std::cout << "Array has " << countTotalItems(array) << " items in it\n";
	return 0;
}