#include <cassert>
#include <cmath>
#include <cstdint> // for fixed width integers
#include <iostream>

class IntArray
{
private:
	int m_length{};
	int* m_array{};

public:
	IntArray(int length)
		: m_length{ length }
	{
		m_array = new int[static_cast<std::size_t>(length)] {} ;
	}

	~IntArray()
	{
		delete[] m_array;
	}

	IntArray(const IntArray& other)
		: m_length(other.m_length)
	{
		if (m_length)
			m_array = new int[static_cast<std::size_t>(m_length)];

		std::copy_n(other.m_array, m_length, m_array);
	}

	IntArray& operator= (const IntArray& str);

	friend std::ostream& operator<<(std::ostream&out, const IntArray& arr);
	const int& operator[] (int index) const
	{
		assert(index >= 0 && index < m_length);
		return m_array[index];
	}

	int& operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		return m_array[index];
	}
};


std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
	for (int index{ 0 }; index < arr.m_length; index++)
		out << arr[index] << " ";

	return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

IntArray& IntArray::operator=(const IntArray& arr)
{
	// self-assignment check
	if (this == &arr)
		return *this;

	// if data exists in the current string, delete it
	if (m_array) delete[] m_array;

	m_length = arr.m_length;
	m_array = nullptr;

	// allocate a new array of the appropriate length
	if (m_length)
		m_array = new int[static_cast<std::size_t>(arr.m_length)];

	std::copy_n(arr.m_array, m_length, m_array); // copies m_length elements of str.m_data into m_data

	// return the existing object so we can chain this operator
	return *this;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);

	b = a;

	a[4] = 7;

	std::cout << b << '\n';
	return 0;
}








/*
class Average
{
	std::int32_t m_sum{0};
	int m_numNums{0};

public:
	Average(std::int32_t sum)
		: m_sum {sum} {}

	Average() = default;

	friend std::ostream& operator<<(std::ostream& out,const Average& avg);

	Average& operator+=(std::int32_t value);
};

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	if (avg.m_numNums == 0)
		out << "0";

	else
		out << static_cast<double>(avg.m_sum) / avg.m_numNums;

	return out;
}

Average& Average::operator+=(std::int32_t value)
{
	m_sum += value;
	++m_numNums;
	return *this;
}


int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
*/
