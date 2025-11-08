#pragma once
#include <iostream>

template <typename T, typename K>
class Pair
{
protected:
	T m_first{};
	K m_second{};

public:
	Pair(T first, K second)
		: m_first{ first }
		, m_second{ second }
	{
	}

	T first() const { return m_first; }
	K second() const { return m_second; }
};

template<typename K>
class StringValuePair : public Pair<std::string, K>
{
public:
	StringValuePair(std::string_view key, const K& value)
		: Pair<std::string, K>{static_cast<std::string>(key), value}
	{
	}
};
