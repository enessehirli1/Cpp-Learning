#pragma once

class Date
{
private:
	int m_day{};
	int m_month{};
	int m_year{};

public:
	Date(int day, int month, int year);
	void print() const;

	// Getters
	int getDay() const { return m_day; }
	int getMonth() const { return m_month; }
	int getYear() const { return m_year; }
};