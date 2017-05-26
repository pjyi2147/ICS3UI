#pragma once
#include <exception>
#include <string>

using namespace std;

class Calendar
{
	int day, month, year;
	int totalday;
public:
	Calendar(int day, int month, int year);
	enum weekday {THURSDAY, FRIDAY, SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY};
	void print();
};

bool checkLeap(int year);
int calculateDays(int year, int month, int day);

class nodate : public runtime_error
{
public:
	nodate(string k);
};
