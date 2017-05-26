// Lab 8.3.1 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "node.cpp"

using namespace std;

ostream& operator<<(ostream& os, node* node)
{
	os << node->getchildl()->getval() << endl << node->getval() << endl << node->getchildr()->getval();
	return os;
}


int main()
{


	node* a = new node;
	node* b = new node;
	node* c = new node;
	int x, y, z;
	cin >> x >> y >> z;

	a->setval(x);
	b->setval(z);
	c->setval(y);

	a->setchildl(b);
	a->setchildr(c);

	cout << a;
}
