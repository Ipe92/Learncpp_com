/*2) Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100). Ask the user how many students they want to enter. Dynamically allocate an array to hold all of the students. Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs, sort the list by grade (highest first). Then print all the names and grades in sorted order.

For the following input:

Joe
82
Terry
73
Ralph
4
Alex
94
Mark
88

The output should look like this:

Alex got a grade of 94
Mark got a grade of 88
Joe got a grade of 82
Terry got a grade of 73
Ralph got a grade of 4
*/

#include <iostream>
#include <iterator>

struct StudentGrades
{
	std::string name;
	int grade;
};

void sortArray(StudentGrades* array, int length) //dyn array and size
{

	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int biggestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex].grade > array[startIndex].grade)
				biggestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[biggestIndex]);
	}
}

int main()
{
	int studentNameCount{};
	do
	{
		std::cout << "How many names would you like to enter?" << '\n';
		std::cin >> studentNameCount;
	} while (studentNameCount <= 1);
	
	// make dynamic array to hold names
	StudentGrades* students{ new StudentGrades[studentNameCount] {} };

	// ask user for names + grades
	for (int index = 0; index < studentNameCount; ++index)
	{
		std::cout << "Please enter name #" << index + 1 << '\n';
		std::cin >> students[index].name;
		do
		{
			std::cout << "Please enter grade between 1-100" << '\n';;
			std::cin >> students[index].grade;
		} while ((students[index].grade > 0) && (students[index].grade <= 100));
	}
		
	// sort that dynamic array (function)
	sortArray(students, studentNameCount);

	//print our sorted array as proof it works
	for (int index = 0; index < studentNameCount; ++index)
		std::cout << students[index].name << " got a grade of " << students[index].grade << '\n';

	// finally delete that dynamic array
	delete[] students;

	return 0;
}