// Lab 5.3.14 by Jeongseop Yi
#include <iostream>
#include <string>
// #include <cmath>

using namespace std;

class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
	cout << "+Node" << endl;
}

Node::~Node()
{
	cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	Node* pop_front();
private:
	Node* head;
};

List::List() : head(nullptr)
{
}

List::~List()
{
	Node* k = this->pop_front();
	while (k != nullptr)
	{
		delete k;
		k = this->pop_front();
	}
	delete this->head;
}


void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
}

Node* List::pop_front()
{
	if (this->head != nullptr)
	{
		Node* k = this->head;
		this->head = k->next;
		return k;
	}
	return nullptr;
}

int main()
{
	List list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	return 0;
}
