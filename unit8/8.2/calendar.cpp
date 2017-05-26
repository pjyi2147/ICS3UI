#include "calendar.h"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

Calendar::Calendar(int day, int month, int year)
{
	try
	{
		if (month < 1 || month > 12)
		{
			throw nodate("Month cannot be less than 0 or bigger than 12");
		}
		this->month = month;
		if (year < 1970)
		{
			throw nodate("Year cannot be less than 1970");
		}
		this->year = year;
		if (month == 2)
		{
			if (checkLeap(year))
			{
				if (day < 0 || day > 29)
				{
					throw nodate("Date not in valid range");
				}
				this->day = day;
			}
			else
			{
				if (day < 0 || day > 28)
				{
					throw nodate("Date not in valid range");
				}
				this->day = day;
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 0 || day > 31)
			{
				throw nodate("Date not in valid range");
			}
			this->day = day;
		}
		else
		{
			if (day < 0 || day > 30)
			{
				throw nodate("Date not in valid range");
			}
			this->day = day;
		}
	}
	catch (nodate ex)
	{
		cout << ex.what() << endl;
		throw;
	}
	this->totalday = calculateDays(year, month, day);
}

void Calendar::print()
{
	string toPrint = "";
	toPrint = toPrint + to_string(this->day) + " ";
	switch (this->month)
	{
	case 1: toPrint += "january "; break;
	case 2: toPrint += "february "; break;
	case 3: toPrint += "march "; break;
	case 4: toPrint += "april "; break;
	case 5: toPrint += "may "; break;
	case 6: toPrint += "june "; break;
	case 7: toPrint += "july "; break;
	case 8: toPrint += "august "; break;
	case 9: toPrint += "september "; break;
	case 10: toPrint += "october "; break;
	case 11: toPrint += "november "; break;
	case 12: toPrint += "december "; break;
	}
	toPrint += to_string(this->year) + " - ";
	switch ((this->totalday-1) % 7)
	{
	case THURSDAY: toPrint += "Thursday - "; break;
	case FRIDAY: toPrint += "Friday - "; break;
	case SATURDAY: toPrint += "Saturday - "; break;
	case SUNDAY: toPrint += "Sunday - "; break;
	case MONDAY: toPrint += "Monday - "; break;
	case TUESDAY: toPrint += "Tuesday - "; break;
	case WEDNESDAY: toPrint += "Wednesday - "; break;
	}

	toPrint += to_string(this->totalday) + " days since 1970 January 1st.";
	cout << toPrint << endl;
}

bool checkLeap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int calculateDays(int year, int month, int day)
{
	int totaldays = 0;
	for (int yr = 1970; yr < year; yr++)
	{
		if (checkLeap(yr))
		{
			totaldays += 366;
		}
		else
		{
			totaldays += 365;
		}
	}
	for (int mo = 1; mo < month; mo++)
	{
		if (mo == 2)
		{
			if (checkLeap(year))
			{
				totaldays += 29;
			}
			else
			{
				totaldays += 28;
			}
		}
		else if (mo == 1 || mo == 3 || mo == 5 || mo == 7 || mo == 8 || mo == 10 || mo == 12)
		{
			totaldays += 31;
		}
		else
		{
			totaldays += 30;
		}
	}
	totaldays += day;
	return totaldays;
}

nodate::nodate(string k) : runtime_error(k)
{
}
