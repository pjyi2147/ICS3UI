// Lab 7.5.2 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "Hanoi.cpp"

using namespace std;

int main()
{
	string order;
	cin >> order;
	Hanoi hanoi;
	while (order != "q")
	{
		try
		{
			stoi(order);
			hanoi.move(order[0], order[1]);
		}
		catch (inexistTower a)
		{
			cout << a.what() << endl;
		}
		catch (invalidMovement a)
		{
			cout << a.what() << endl;
		}
		catch (invalid_argument a)
		{
			cout << "The order is not numerical. Try again" << endl;
		}
		cin >> order;
	}
	hanoi.printTower();
}
