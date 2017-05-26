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
	cin >> date >>  month >> year;
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
