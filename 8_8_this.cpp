#include <iostream>

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

class Calc
{
private:
	int m_value;

public:
	Calc() { m_value = 0; }

	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	int getValue() { return m_value; }
};

int main()
{
	Calc calc;
	calc.add(5).sub(3).mult(4); // returns this 8
	//calc.sub(3); // returns void
	//calc.mult(4); // returns void

	std::cout << calc.getValue() << '\n';

	/*Simple simple(1);
	simple.setID(2);
	std::cout << simple.getID() << '\n';*/

	return 0;
}