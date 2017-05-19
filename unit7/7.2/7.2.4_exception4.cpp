// Lab 7.2.4 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class object
{
public:
	int value;
	int maxboundary;
	int minboundary;
	object(int val, int max, int min);
	void subtract(int a);
	void add(int a);
};

void object::add(int a)
{
	if (this->value + a > maxboundary)
	{
		throw string("Value cannot exceed its limit");
	}
	if (this->value + a < minboundary)
	{
		throw string("Value cannot exceed its limit");
	}
	this->value += a;
}

void object::subtract(int a)
{
	if (this->value - a > maxboundary)
	{
		throw string("Value cannot exceed its limit");
	}
	if (this->value - a < minboundary)
	{
		throw string("Value cannot exceed its limit");
	}
	this->value -= a;
}



object::object(int val, int max, int min)
{
	this->value = val;
	this->maxboundary = max;
	this->minboundary = min;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	object x(a, b, c);
	cin >> a >> b >> c;
	object y(a, b, c);
	cin >> a;
	try
	{
		x.add(a);
	}
	catch (string a)
	{
		cout << a << endl;
	}
	try
	{
		y.add(a);
	}
	catch (string a)
	{
		cout << a << endl;
	}
	try
	{
		x.subtract(a);
	}
	catch (string a)
	{
		cout << a << endl;
	}
	try
	{
		y.subtract(a);
	}
	catch (string a)
	{
		cout << a << endl;
	}
}
