// Lab 5.3.16 by Jeongseop Yi
#include <iostream>
#include <string>
// #include <cmath>

using namespace std;

/*Node*/
class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};

// init
Node::Node(int val) : value(val), next(nullptr)
{
}

// delete
Node::~Node()
{
}

/*List*/
class List
{
public:
	List();
	~List();
	void push_front(int value);
	void push_back(int value);
	Node* pop_front();
	int size();
private:
	Node* head;
	Node* tail;
};

// init
List::List() : head(nullptr)
{
}

// delete
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

// push front
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = this->head;
	if (this->size() == 0)
	{
		this->tail = new_head;
	}
	this->head = new_head;
}

// push back
void List::push_back(int value)
{
	Node* new_head = new Node(value);
	if (this->size() > 0)
	{
		(this->tail)->next = new_head;
	}
	if (this->size() == 0)
	{
		this->head = new_head;
	}
	this->tail = new_head;
}

// pop front
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

// size
int List::size()
{
	int size = 0;
	Node* k = this->head;
	while (k != nullptr) {
		size += 1;
		k = k->next;
	}
	return size;
}


// main
int main()
{
	List list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	Node* k = list.pop_front();
	while (k != nullptr)
	{
		cout << k->value << endl;
		k = list.pop_front();
	}
	return 0;
}
