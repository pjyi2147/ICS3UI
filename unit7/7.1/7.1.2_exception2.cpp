// Lab 7.1.2 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a;
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
	}
}
