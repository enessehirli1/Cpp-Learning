#include <iostream> 
#include <array>
#include <cstddef>
#include <cassert>

class Simple
{
private:
	int m_nId{};

public:
	Simple(int id)
		: m_nId{ id }
	{
		std::cout << "Constructor worked " << m_nId << '\n';
	}

	~Simple()
	{
		std::cout << "Destructor worked " << m_nId << '\n';
	}

	int getId() const { return m_nId; }
};


int main()
{
	Simple simple{ 2 };
	std::cout << simple.getId()<< '\n';

	Simple* pSimple{ new Simple {5} };
	std::cout << pSimple->getId() << '\n';

	delete pSimple;
}



/*
class IntArray
{
private:
	int* m_array{};
	int  m_length{};

public:
	IntArray(int length)
	{
		assert(length > 0);
		m_array = new int[static_cast<std::size_t>(length)];
		m_length = length;
	}

	~IntArray()
	{
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) const { return m_array[index]; }
	int getLength() const { return m_length; }
};


int main()
{
	IntArray ar(10);

	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count + 1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	return 0;

	return 0;
}
*/
