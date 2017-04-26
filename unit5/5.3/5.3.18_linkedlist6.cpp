// Lab 5.3.18 by Jeongseop Yi
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
	Node* pop_back();
	int size();
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
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

// at functions
int List::at(int index)
{
	Node* k = this->head;
	for (int i = 0; i < index; i++)
	{
		k = k->next;
	}
	return k->value;
}

void List::insert_at(int index, int value)
{
	int sizelst = this->size();
	if (index > sizelst)
	{
		cout << "Not vaild operation" << endl;
	}
	else {
		Node* k = this->head;
		Node* new_node = new Node(value);
		for (int i = 0; i < index - 1; i++)
		{
			k = k->next;
		}
		new_node->next = k->next;
		k->next = new_node;
	}
}

void List::remove_at(int index)
{
	if (index + 1 > this->size())
	{
		cout << "Not vaild operation: out of bounds" << endl;
	}
	else {
		Node* p = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		// when the object is the end of the list
		if (index + 1 == this->size())
		{
			p->next = nullptr;
			this->tail = p;
		}
		// else than
		else {
			p->next = p->next->next;
		}
	}
}

inline void printList(List* list)
{
	for (int i = 0; i < list->size(); i++)
	{
		cout << "list[" << i << "] == " << list->at(i) << endl;
	}
}

inline void printList(List list) // this does not work.... why?????
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
}

int main()
{
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	printList(&list);
	cout << endl;
	list.remove_at(2);
	printList(&list);
	cout << endl;
	list.insert_at(1, 6);
	printList(&list);

	return 0;
}
