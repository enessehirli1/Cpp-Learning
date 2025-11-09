#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year)
    : m_day{ day }
    , m_month{ month }
    , m_year{ year }
{
}

void Date::print() const
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}