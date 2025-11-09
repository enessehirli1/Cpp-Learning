#pragma once
#include <cassert>
#include <cstddef> // for std::size_t
#include <memory>
#include <vector>
#include <algorithm>


class IntArray
{
private:
	std::size_t m_length{};
	std::unique_ptr<int[]> m_data{};

public:
	IntArray() = default;

	IntArray(std::size_t length)
		: m_length {length} 
	{
		assert(length >= 0);

		if (length > 0)
			m_data = std::make_unique<int[]>(length);
	}

	IntArray(const IntArray& a)
		: IntArray(a.getLength())
	{
		std::copy_n(a.m_data.get(), m_length, m_data.get());
	}

	IntArray(IntArray&& a) noexcept
		: m_length{ a.m_length }
		, m_data{ std::move(a.m_data) }
	{
		a.m_length = 0;
		a.m_data = nullptr;
	}

	IntArray& operator=(const IntArray& a)
	{
		if (&a == this)
			return *this;

		reallocate(a.getLength());
		std::copy_n(a.m_data.get(), m_length, m_data.get());
		return *this;
	}

	IntArray& operator=(IntArray&& a) noexcept
	{
		if (&a == this)
			return *this;

		m_length = a.m_length;
		m_data = std::move(a.m_data);
		a.m_length = 0;
		a.m_data = nullptr; // No need to do this, but it is clearer (defensive programming)

		return *this;
	}

	void erase()
	{
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](std::size_t index)
	{
		assert(index>=0 && index < m_length);
		return m_data[index];
	}


	// reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly
	void reallocate(std::size_t newLength)
	{
		erase();
		if (newLength <= 0)
			return;

		m_data = std::make_unique<int[]>(newLength);
		m_length = newLength;
	}


	// resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
	void resize(std::size_t newLength)
	{
		if (newLength == m_length)
			return;


		// Now we can assume newLength is at least 1 element.  This algorithm
		// works as follows: First we are going to allocate a new array.  Then we
		// are going to copy elements from the existing array to the new array.
		// Once that is done, we can destroy the old array, and make m_data
		// point to the new array.

		// First we have to allocate a new array
		std::unique_ptr<int[]> data{ std::make_unique<int[]>(newLength) };
		if (m_length > 0)
		{
			std::size_t elementsToCopy{ (newLength > m_length) ? m_length : newLength};
			std::copy_n(m_data.get(), elementsToCopy, data.get());
		}

		// Now we can delete the old array, and use the new array instead
		m_data = std::move(data);
		m_length = newLength;

	}


	void insertBefore(int value, std::size_t index)
	{
		assert(index <= m_length);

		// First create a new array one element larger than the old array
		std::unique_ptr<int[]> data{ std::make_unique<int[]>(m_length + 1) };

		// Copy all of the elements up to the index
		std::copy_n(m_data.get(), index, data.get());

		// Insert our new element into the new array
		data[index] = value;

		// Copy all of the values after the inserted element
		std::copy_n(m_data.get() + index, m_length - index, data.get() + index + 1);

		// Finally, use the new array instead of the old array
		m_data = std::move(data);
		++m_length;
	}


	void remove(std::size_t index)
	{
		// Sanity check our index value
		assert(index < m_length);

		// If this is the last remaining element in the array, set the array to empty and bail out
		if (m_length == 1)
		{
			erase();
			return;
		}

		// First create a new array one element smaller than the old array
		std::unique_ptr<int[]> data{ std::make_unique<int[]>(m_length - 1) };

		// Copy all of the elements up to the index
		std::copy_n(m_data.get(), index, data.get());

		// Copy all of the values after the removed element
		std::copy_n(m_data.get() + index + 1, m_length - index - 1, data.get() + index);

		// Finally, use the new array instead of the old array
		m_data = std::move(data);
		--m_length;

	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

	std::size_t getLength() const { return m_length; }
};