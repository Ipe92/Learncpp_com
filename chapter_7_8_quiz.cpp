#include <iostream>
#include <functional>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x;
	std::cin >> x;
	return x;
}

char getOperation()
{
	char op;

	do
	{
		std::cout << "Enter an operation ('+', '-', '*', '/'): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}



int divide(int x, int y)
{
	return x / y;
}

std::function<int(int, int)> getArithmeticFunction(char op)
{
	switch (op)
	{
	default: // default will be to add
	case '+': return add;
	case '-': return subtract;
	case '*': return multiply;
	case '/': return divide;
	}
}

int main()
{
	int x{ getInteger() };
	char op{ getOperation() };
	int y{ getInteger() };

	std::function<int(int, int)> fcn{ getArithmeticFunction(op) };
	std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y)
		<< '\n';

	return 0;
}