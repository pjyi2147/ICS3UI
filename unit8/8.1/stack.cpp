#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "stack.h"

using namespace std;

stack::stack()
{
	this->array = new int[0];
	this->num = 0;
	this->size = 0;
}

stack::stack(int x)
{
	this->array = new int[x];
	this->num = 0;
	this->size = x;
}

void stack::push(int x)
{
	if (this->num >= this->size)
	{
		throw stack_overflow();
	}
	array[num++] = x;
}

int stack::pop()
{
	if (this->num <= 0)
	{
		throw stack_underflow();
	}
	int x = array[--num];
	return x;
}

stack& stack::operator<<(int x)
{
	try
	{
		this->push(x);
		return *this;
	}
	catch (stack_overflow ex)
	{
		cout << ex.what();
	}
}

int& stack::operator>>(int &x)
{
	try
	{
		x = this->pop();
		return x;
	}
	catch (stack_underflow ex)
	{
		cout << ex.what();
		throw;
	}
}

stack_overflow::stack_overflow() : runtime_error("Exception: stack is full.")
{
}

stack_underflow::stack_underflow() : runtime_error("Exception: stack is empty.")
{
}



