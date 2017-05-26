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
	node* d = new node;
	int w, x, y, z;
	cin >> w >> x >> y >> z;
	a->setval(w);
	b->setval(x);
	c->setval(y);
	d->setval(z);

	a->setchildl(b);
	a->setchildr(c);
	b->setchildl(d);

	cout << "Inorder: " << a->inorder() << endl;
	cout << "Postorder: " << a->postorder() << endl;
	cout << "Preorder: " << a->preorder() << endl;

}
