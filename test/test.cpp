#include "pch.h"

#include <iostream>
using namespace std;


class Date
{
public:
	// Constructors
	// initialise to 1/1/1900
	Date();
	// initialise to dd/mm/yy
	Date(int dd, int mm, int yy);
	// member functions
	void print(); // prints date
	void next_day(); // sets date to next day
	// Accessor functions
	int get_day(); // returns day
	int get_month(); // returns month
	int get_year(); // returns year

private:
	int day;
	int month;
	int year;
	int leap_year(); // returns true if year is a leap
	// year. Required in next_day()
};

// Constructor functions
Date::Date(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}
Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}
// Accessor functions
int Date::get_day()
{
	return day;
}
int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}
// Other functions
void Date::print()
{
	cout << day << "/"
		<< month << "/"
		<< year;
}
void Date::next_day()
{
	int days_in_month;
	day++;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: days_in_month = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: days_in_month = 30;
		break;
	case 2: if (leap_year())
		days_in_month = 29;
		  else days_in_month = 28;
		break;
	}
	if (day > days_in_month)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}
// Private function
int Date::leap_year()
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}

int leap_year(int year)
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}

// Testattava funktio
#include <cmath>
double cubic(double d) {
    return pow(d, 3);
}

// Testit
TEST(TestCubicFuntion, CubicTest) {
  EXPECT_EQ(1000, cubic(10));
  EXPECT_EQ(8, cubic(2));
  EXPECT_TRUE(true);
}

TEST(LeapYearFunction, LeapYearTest) {
	EXPECT_EQ(false, leap_year(2001));
	EXPECT_EQ(true, leap_year(2012));
	EXPECT_EQ(false, leap_year(1900));
	EXPECT_EQ(true, leap_year(1600));
}

TEST(GetterFunctions, testGetterFunction) {
	Date d1 = Date(5, 2, 2012);
	EXPECT_EQ(5, d1.get_day());
	EXPECT_EQ(2, d1.get_month());
	EXPECT_EQ(2012, d1.get_year());
}

TEST(GetterFunctions2, testGetterFunctions2) {
	Date d1 = Date();
	EXPECT_EQ(1, d1.get_day());
	EXPECT_EQ(1, d1.get_month());
	EXPECT_EQ(1900, d1.get_year());
}

TEST(TestNextDayFunction, testNextDay) {
	Date d1 = Date();
	d1.next_day();
	EXPECT_EQ(2, d1.get_day());
	EXPECT_EQ(1, d1.get_month());
	EXPECT_EQ(1900, d1.get_year());
}