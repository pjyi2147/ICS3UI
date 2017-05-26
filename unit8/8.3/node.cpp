#pragma once


#include <iostream>
#include <string>
#include "node.h"

using namespace std;

node::node(int val)
{
	this->val = val;
}

node* node::getchildl()
{
	return this->left;
}

node* node::getchildr()
{
	return this->right;
}

void node::setchildl(node* child)
{
	this->left = child;
}

void node::setchildr(node* child)
{
	this->right = child;
}

void node::setval(int val)
{
	this->val = val;
}

int node::getval()
{
	return this->val;
}
