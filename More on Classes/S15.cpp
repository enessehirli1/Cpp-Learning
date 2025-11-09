#include <chrono>
#include <random>
#include <iostream>

class Random
{
private: // could be public if we want these to be accessible
	static std::mt19937 generate()
	{
		std::random_device rd{};

		// Create seed_seq with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	static inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

public:
	// Generate a random int between [min, max] (inclusive)
	static int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
};

int main()
{
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

	return 0;
}

















/*
class Fruit

{
public:
	enum Type
	{
		apple,
		banana,
		cherry
	};

private:
	Type m_type{};
	int m_percentageEaten{};

public:
	Fruit(Type type)
		: m_type{type}
	{}

	~Fruit()
	{
		std::cout << "Object destoyed by destuctor ! \n";
	}

	Type getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEaten; }

	bool isCherry() const { return m_type == cherry; }
};

int main()
{
	Fruit apple{ Fruit::apple };

	if (apple.getType() == Fruit::apple)
	{
		std::cout << "I am an apple \n";
	}
	else
		std::cout << "I am not an apple \n";

	return 0;
}

*/

