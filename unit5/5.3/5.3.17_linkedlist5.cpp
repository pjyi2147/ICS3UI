// Lab 5.3.17 by Jeongseop Yi
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
	Node* pop_back();
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

// pop back
Node* List::pop_back()
{
	if (this->tail != nullptr)
	{
		if (this->size() == 1)
		{
			Node*k = this->tail;
			this->tail = nullptr;
			this->head = nullptr;
			return k;
		}
		Node* k = this->tail;
		Node* p = this->head;
		while (p->next != k && this->size() > 1)
		{
			p = p->next;
		}
		this->tail = p;
		p->next = nullptr;
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


/*main*/
int main()
{
	List list;

	for (int i = 1; i < 5; i++) {
        list.push_front(i);
	}

	Node* k;
	while (list.size() > 0)
	{
		k = list.pop_back();
		cout << k->value << endl;
	}
	return 0;
}
