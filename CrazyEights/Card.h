#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Card
{
	char rank;
	char suit;
};

inline std::ostream& operator<<(std::ostream& out, const Card& c)
{
	if (c.rank == '0')
	{
		out << "10";
	}
	else
		out << c.rank;

	out << c.suit;
	return out;
}
