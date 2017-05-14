#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// constructor
Account::Account(int number)
{
	this->number = number;
	cout << "Initialize your bank account " << this->getNumber() << " with an initial balance: ";
	float balance;
	cin >> balance;
	// when the balance is negative
	while (balance < 0)
	{
		cout << "The initial balance can't be less than $0. Try again" << endl;
		cout << "Initialize your bank account with the initial balance: " << endl;
		cin >> balance;
		if (balance >= 0)
		{
			break;
		}
	}
	this->balance = balance;
}


// returns the account number
int Account::getNumber()
{
	return this->number;
}

// credits the balance
void Account::credit(float amount)
{
	// when the amount is negative
	if (amount < 0)
	{
		cout << "We cannot credit negative amount. Try debit function." << endl << endl;
	}
	else
	{
		this->balance += amount;
	}
}

// debits the balance
void Account::debit(float amount)
{
	// when the amount is negative
	if (amount < 0)
	{
		cout << "We cannot debit negative amount. Try credit function." << endl << endl;
	}
	// when amount > balance;
	else if (amount > this->balance)
	{
		cout << "We cannot make the account balance less than $0. Try again." << endl << endl;
	}
	else
	{
		this->balance -= amount;
	}
}

// returns its balance
float Account::getBalance()
{
	return this->balance;
}
