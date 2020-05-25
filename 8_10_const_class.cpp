class Something
{
public:
	int m_value;

	Something(): m_value{0} { }

	void resetValue() { m_value = 0; }
	void setValue(int value) { m_value = value; }

	int getValue() const; // const here
};

int Something::getValue() const // note const after parameter list
{
	return m_value;
}