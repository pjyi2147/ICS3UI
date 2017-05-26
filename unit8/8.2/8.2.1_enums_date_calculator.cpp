// Lab 8.2.1 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "calendar.cpp"

using namespace std;

int main()
{
	int date, month, year;
	cout << "Input date: ";
	cin >> date;
	cout << "Input month: ";
	cin >> month;
	cout << "Input year: ";
	cin >> year;
	try
	{
		Calendar cal(date, month, year);
		cal.print();

	}
	catch(...)
	{
		cout << "Exception thrown: Exitting..." << endl;
	}
}
