// Lab 7.2.2 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class except
{
	string err;
public:
	except();
	void printerror();
};

except::except() : err("Area can't be negative")
{
}

void except::printerror()
{
	cout << this->err << endl;
}

float square_area(float s)
{
	if (s < 0)
	{
		throw except();
	}
	return s*s;
}

float rectangle_area(float x, float y)
{
	if (x < 0 || y < 0)
	{
		throw except();
	}
	return x*y;
}

int main()
{
	float a, b, r;
	cin >> a;
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (except a)
	{
		a.printerror();
	}
}
