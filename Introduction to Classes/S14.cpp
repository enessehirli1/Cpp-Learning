#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	// Consturctors
	explicit Fraction(int numerator=0, int denominator=1)
        : m_numerator { numerator }, m_denominator { denominator}
    {
    }

	// getFraction member function
	void getFraction()
	{
		std::cout << "Enter a value for numerator: ";
		std::cin >> m_numerator;

		std::cout << "Enter a value for denominator: ";
		std::cin >> m_denominator;
		
		std::cout << '\n';
	}

	// mulitply membet function
	Fraction multiply(const Fraction& fr) const
	{
		return Fraction{ m_numerator * fr.m_numerator, m_denominator * fr.m_denominator };
	}

	// print membet function
	void print() const
	{
		std::cout << m_numerator << "/" << m_denominator << '\n';
	}

};


int main()
{
	Fraction f1{};
	f1.getFraction();

	Fraction f2{};
	f2.getFraction();

	std::cout << "Your fractions multiplied together: ";

	f1.multiply(f2).print();

	return 0;
}





















/*
class Point2d
{
private:
	double m_x{0.0};
	double m_y{0.0};

public:
	Point2d() = default;
	Point2d(double x, double y)
		: m_x{x}
		, m_y{y}
	{}

	void print() const
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	double distanceTo(const Point2d& point) const
	{
		return std::sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
	}
};

int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };

	first.print();
	second.print();

	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	return 0;
}



class Dollars
{
private: 
	int m_dollars{};
	
public:
	explicit Dollars(int dollar)
		: m_dollars{ dollar }
	{
	}

	int getDollars() const { return m_dollars; }
};

void printDollars(const Dollars& d)
{
	std::cout << d.getDollars() << '\n';
}

int main()
{
	printDollars(Dollars{ 1200 }); // compilation error because Dollars(int) is explicit

	return 0;
}








class Ball
{
private:
	std::string m_color{"black"};
	double m_radius{10.0};

public:
	explicit Ball(std::string_view color="black", double radius=10.0)
		: m_color{ color }
		, m_radius{ radius }
	{
		print();
	}

	explicit Ball(double radius) : Ball("black", radius) {}

	void print()
	{
		std::cout << "(" << m_color << ", " << m_radius << ")\n";
	}
};

int main()
{
	Ball def{};
	Ball blue{ "blue" };
	Ball twenty{ 20.0 };
	Ball blueTwenty{ "blue", 20.0 };

	return 0;
}
*/
