#include <cassert>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <algorithm>

class IntArray
{
private:
	std::size_t m_length{};
	std::unique_ptr<int[]> m_data{};

public:
	IntArray() = default;

	IntArray(std::size_t length)
		: m_length{length}
		, m_data{std::make_unique<int[]>(length)}
		{}

	IntArray(std::initializer_list<int> list)
		: IntArray(list.size()) // list size is std::size_t already
	{
		for (std::size_t count{0}; count < list.size(); ++count)
		{
			m_data[count] = list.begin()[count];
		}
		// std::copy(list.begin(), list.end(), m_data.get()); // alternative
	}

	~IntArray() = default;

	IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	IntArray& operator=(std::initializer_list<int> list)
	{
		std::size_t length{ list.size() };
		if (length != m_length)
		{
			// since we use unique_ptr, memory will be automatically freed so ne need to call delete[]
			m_length = length;
			m_data = std::make_unique<int[]>(list.size());
		}

		std::copy(list.begin(), list.end(), m_data.get());

		return *this;
	}

	int& operator[](std::size_t index)
	{
		assert(index < m_length);
		return m_data[index];
	}

	int getLength() const { return static_cast<int>(m_length); }	
};

int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (std::size_t count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (std::size_t count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}