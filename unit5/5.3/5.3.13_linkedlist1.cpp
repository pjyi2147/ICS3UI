// Lab 5.3.13 by Jeongseop Yi
#include <iostream>
#include <string>
// #include <cmath>

using namespace std;

class Node
{
public:
	Node(int val);
	int value;
	Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

class List
{
public:
	List();
	void push_front(int value);
	Node* pop_front();
private:
	Node* head;
};

List::List() : head(nullptr)
{
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
		this->head = k->36next;
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

	//int value = 0;
	Node* k = list.pop_front();
	while (k != nullptr)
	{
		cout << k->value << endl;
		k = list.pop_front();
	}
	return 0;
}
