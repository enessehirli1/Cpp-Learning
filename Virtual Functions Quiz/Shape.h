#pragma once
#include <iostream>
#include "Point.h"

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Shape& s)
	{
		return s.print(out);
	}

	virtual ~Shape() = default;
};


class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
		: m_p1{ p1 }
		, m_p2{ p2 }
		, m_p3{ p3 }
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Triangle(";
		out << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_center;
	int m_radius{};

public:
	Circle(const Point& p, int radius)
		: m_center{ p }
		, m_radius{ radius }
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Circle(";
		out << m_center;
		out << ", radius " << m_radius << ")";
		return out;
	}

	int getRadius()
	{
		return m_radius;
	}
};

