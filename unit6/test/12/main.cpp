/*
*  10/05/17
*  ICS3UI
*  Unit test 6 #1,2
*  Jeongseop Yi
*  Mr. Damian
*/

#include <iostream>
#include <string>
#include "Account.cpp"
#include <iomanip>

using namespace std;

int main()
{
	cout << "This program is a bank account simulator." << endl;
	cout << "You are given 2 accounts to use." << endl;
	cout << "Before start, initialize your bank account with the initial balance: " << endl;
	Account a(1);
	Account b(2);

	string order;
	while (order != "quit")
	{
		cout << fixed << setprecision(2) << "The remaining balance in the account " << a.getNumber() << " is $" << a.getBalance() << endl;
		cout << fixed << setprecision(2) << "The remaining balance in the account " << b.getNumber() << " is $" << b.getBalance() << endl;
		cout << "Please Enter your order [order] [accountNumber] [amount]: ";
		cin >> order;
		string number;
		cin >> number;
		if (order == "quit") {
            break;
		}
		if (number == "1")
		{
            // when the user puts debit
			if (order == "debit")
			{
				float amount;
				cin >> amount;
				a.debit(amount);
			}
			// when the user puts credit
			else if (order == "credit")
			{
				float amount;
				cin >> amount;
				a.credit(amount);
			}
			else
			{
				cout << "Invalid. Try again." << endl;
			}
		}
		else if (number == "2")
		{
			// when the user puts debit
			if (order == "debit")
			{
				float amount;
				cin >> amount;
				b.debit(amount);
			}
			// when the user puts credit
			else if (order == "credit")
			{
				float amount;
				cin >> amount;
				b.credit(amount);
			}
			else
			{
				cout << "Invalid. Try again." << endl;
			}
		}
		else
		{
			cout << "Invalid. Try again." << endl;
		}
	}
	cout << fixed << setprecision(2) << "The remaining balance in the account is $" << a.getBalance() << endl;
	cout << fixed << setprecision(2) << "The remaining balance in the account is $" << a.getBalance() << endl;
	cout << "Quitting simulation." << endl;
	int x;
	cin >> x;
	return 0;
}
