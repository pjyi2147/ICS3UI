#pragma once
using namespace std;

class stack
{
	int num;
	int size;
	int* array;
public:
	stack(int x);
	stack();
	void push(int x);
	int pop();
	stack& operator<< (int x);
	int& operator>> (int &x);
};

class stack_overflow : public runtime_error
{
public:
	stack_overflow();
};

class stack_underflow : public runtime_error
{
public:
	stack_underflow();
};
