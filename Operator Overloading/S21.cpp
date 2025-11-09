#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](std::string name);
};

char& GradeMap::operator[](std::string name)
{
	auto found{ std::find_if(m_map.begin(), m_map.end(),
				[name](const auto& a) {return a.name == name; }) };

	if (found != m_map.end())
		return found->grade;

	return m_map.emplace_back(StudentGrade{ name }).grade;
}

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	std::cout << "Hannah has a grade of " << grades["Hannah"] << '\n';

	return 0;
}










/*
class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string_view make, std::string_view model)
		: m_make{ make }, m_model{ model }
	{
	}

	friend bool operator== (const Car& c1, const Car& c2);
	friend bool operator!= (const Car& c1, const Car& c2);

	friend std::ostream& operator<<(std::ostream& out, const Car& car);
	friend bool operator<(const Car& car1, const Car& car2);
};

bool operator== (const Car& c1, const Car& c2)
{
	return (c1.m_make == c2.m_make &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
	return (c1.m_make != c2.m_make ||
		c1.m_model != c2.m_model);
}

bool operator<(const Car& car1, const Car& car2)
{
	if (car1.m_make != car2.m_make)
		return car1.m_make < car2.m_make;

	return car1.m_model < car2.m_model;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	out << "(" << car.m_make << ", " << car.m_model << ")";
	return out;
}

int main()
{
	std::vector<Car> cars{
	  { "Toyota", "Corolla" },
	  { "Honda", "Accord" },
	  { "Toyota", "Camry" },
	  { "Honda", "Civic" }
	};

	std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

	for (const auto& car : cars)
		std::cout << car << '\n'; // requires an overloaded operator<<

	return 0;
}



class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);


	friend bool operator==(const Fraction& f1, const Fraction& f2) {
		return f1.m_denominator == f2.m_denominator
			&& f1.m_numerator == f2.m_numerator;
	}
	friend bool operator!=(const Fraction& f1, const Fraction& f2) { return !(operator==(f2, f1));}
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2) { return operator<(f2, f1); }
	friend bool operator<=(const Fraction& f1, const Fraction& f2) { return !(operator>(f1, f2)); }
	friend bool operator>=(const Fraction& f1, const Fraction& f2) { return !(operator<(f1, f2)); }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return (static_cast<double>(f1.m_numerator) / static_cast<double>(f1.m_denominator))
		   < 
		   (static_cast<double>(f2.m_numerator) / static_cast<double>(f2.m_denominator));
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}























class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
	// friend overloading functions
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
	
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fr);
	friend std::istream& operator>>(std::istream& in, Fraction& fr);

	// member overloading functions
	Fraction operator-() const;
	Fraction operator+() const;
	bool operator!() const;

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& fr)
{
	out << fr.m_numerator << "/" << fr.m_denominator;
	return out;
}

Fraction Fraction::operator-() const
{
	return Fraction{ -m_numerator, m_denominator };
}

Fraction Fraction::operator+() const
{
	return *this;
}

bool Fraction::operator!() const
{
	return !(m_numerator == 0);
}

std::istream& operator>>(std::istream& in, Fraction& fr)
{
	int numerator{};
	char ignore{};
	int denominator{};

	in >> numerator >> ignore >> denominator;
	if (denominator == 0)
		in.setstate(std::ios_base::failbit);
	if (in)
		fr = Fraction{ numerator, denominator };

	return in;
}


int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	std::cout << -f1 << '\n';
	std::cout << +f1 << '\n';
	if (!f1)
		std::cout << "Positive";
	else
		std::cout << "Zero";


	return 0;
}















class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator, int denominator)
		: m_numerator {numerator}
		, m_denominator{ denominator } {reduce();}

	int getNumerator() const { return m_numerator; }
	int getDenominator() const { return m_denominator; }

	friend Fraction operator*(const Fraction& f1, const Fraction f2);
	friend Fraction operator*(const Fraction& fr, int value);
	friend Fraction operator*(int value, const Fraction& fr);

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator)};

		m_numerator /= gcd;
		m_denominator /= gcd;
	}

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << '\n';
	}

};

Fraction operator*(const Fraction& f1, const Fraction f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}


Fraction operator*(const Fraction& fr, int value)
{
	return Fraction{ fr.m_numerator * value, fr.m_denominator };
}

Fraction operator*(int value, const Fraction& fr)
{
	return Fraction{ fr * value };
}


int main()
{
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
	f6.print();

	Fraction f7{ 0, 6 };
	f7.print();

	Fraction f8{ 2,4 };
	f8.print();

	return 0;
}









class MinMax
{
private:
	int m_min{};
	int m_max{};

public:
	MinMax(int min, int max)
		: m_min {min}
		, m_max {max} {}

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax& m1, const MinMax& m2);
	friend MinMax operator+(const MinMax& m, int value);
	friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
	int min{ m1.m_min > m2.m_min ? m2.m_min : m1.m_min };
	int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

	return MinMax{ min, max };
}

MinMax operator+(const MinMax& m, int value)
{
	int min{ m.m_min < value ? m.m_min : value };
	int max{ m.m_max < value ? value : m.m_max };

	return MinMax{ min , max };
}

MinMax operator+(int value, const MinMax& m)
{
	// calls operator+(MinMax, int)
	return m + value;
}

int main()
{
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
}
*/