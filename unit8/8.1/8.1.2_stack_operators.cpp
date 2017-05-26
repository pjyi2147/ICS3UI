// Lab 8.1.2 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "stack.cpp"

using namespace std;

int main()
{
	int x;
	cin >> x;
	stack stk(x);
	for (int i = 0; i < x+1; i++)
	{
		int k;
		cin >> k;
		stk << k;
	}
	for (int i = 0; i < x+1; i++)
	{
		int k;
		try
		{
			stk >> k;
			cout << k << endl;
		}
		catch (stack_underflow ex)
		{

		}
	}
	cin >> x;
}
