#include <iostream>
#include <string>
#include "node.h"
#pragma once


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

string node::inorder()
{
	string k = "";
	if (this->getchildl() != nullptr)
	{
		k += this->getchildl()->inorder();
	}
	k += to_string(this->getval()) + " ";
	if (this->getchildr() != nullptr)
	{
		k += this->getchildr()->inorder() + " ";
	}
	return k;
}

string node::postorder()
{
	string k = "";
	if (this->getchildl() != nullptr)
	{
		k += this->getchildl()->postorder() + " ";
	}
	if (this->getchildr() != nullptr)
	{
		k += this->getchildr()->postorder() + " ";
	}
	k += to_string(this->getval());
	return k;
}

string node::preorder()
{
	string k = "";
	k += to_string(this->getval()) + " ";
	if (this->getchildl() != nullptr)
	{
		k += this->getchildl()->preorder();
	}
	if (this->getchildr() != nullptr)
	{
		k += this->getchildr()->preorder();
	}
	return k;
}

