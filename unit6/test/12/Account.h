#pragma once
#include <string>

using namespace std;

class Account
{
public:
	Account(int number);
	float getBalance();
	void credit(float amount);
	void debit(float amount);
	int getNumber();
private:
	float balance;
	int number;
};