// Lab 7.1.1 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

int main()
{
	int a = 8, b = 0, c = 0;
	cin >> b;
	try
	{
		if (b == 0)
		{
			throw string("Bad User");
		}
		c = a / b;
		cout << c << endl;
	}
	catch (string &excep)
	{
		cout << excep << endl;
		cout << c << endl;
	}
}
