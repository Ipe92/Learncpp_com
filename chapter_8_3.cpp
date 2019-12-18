#include <iostream>
#include <array>
#include <cassert>

class Stack
{
private:
	static constexpr int s_maxStackLength{ 10 };
	int m_array[s_maxStackLength];
	int m_next = 0;

public:

	void reset()
	{
		m_next = 0;
	}

	bool push(int value)
	{
		// If the stack is already full, return false and bail
		if (m_next == s_maxStackLength)
			return false;

		// Set the next free element to the value, then increase m_next
		m_array[m_next++] = value;
		return true;
	}

	int pop()
	{
		assert(m_next > 0 && "Can not pop empty stack");
		// m_next points to the next free element, so the last valid element is m_next -1
		// what we want to do is something like this:
		// int val = m_array[m_next-1]; // get the last valid element
		// --m_next; //  m_next is now one less since we just removed the top element
		// return val; // return the last element that can be condensed down into this:
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (int i{0}; i < m_next; ++i)
			std::cout << m_array[i] << " ";
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}