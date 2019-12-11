#include <iostream>
#include <vector>

int fibonacci(int count)
{
	// We'll use a static std::vector to cache calculated results
	static std::vector<int> results{ 0, 1 };

	// If we've already seen this count, then use the cache'd results
	if (count < static_cast<int>(std::size(results)))
		return results[count];
	else
	{
		// Otherwise calculate the new results and add it
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}

int main()
{
	for (int i = 0; i < 50; ++i)
	std::cout << fibonacci(i) << '\n';
	return 0;
}