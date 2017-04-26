// Lab 5.3.20 by Jeongseop Yi
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
	Node* prev;
};

// init
Node::Node(int val) : value(val), next(nullptr), prev(nullptr)
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
	List(List& list);
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
List::List() : head(nullptr), tail(nullptr)
{
}

List::List(List& list)
{
	this->head = nullptr;
	this->tail = nullptr;
	for (int i = 0; i < list.size(); i++)
	{
		this->push_back(list.at(i));
	}
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
	// connect original the next one;
	new_head->next = this->head;
	if (this->head != nullptr) this->head->prev = new_head;
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
		// change the last one
		(this->tail)->next = new_head;
		// connect the prev
		new_head->prev = this->tail;
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
		// first one is the one returned
		Node* k = this->head;
		// change the first one
		this->head = k->next;
		// grounding
		if (this->head != nullptr) this->head->prev = nullptr;
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
		Node* p = k->prev;
		this->tail = p;

		// grounding
		p->next = nullptr; // since p is the last node
		k->prev = nullptr; // not necessary but still...
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
		// exchange of next and prev between k->next and new_node
		new_node->next = k->next;
		k->next->prev = new_node;

		// exchange of next and prev between new node and k
		k->next = new_node;
		new_node->prev = k;
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
			p->next->prev = nullptr;
			p->next = nullptr;
			this->tail = p;
		}
		// else than
		else {
			p->next = p->next->next;
			p->next->prev = p;
		}
	}
}


inline void printList(List* list) // the list changes when not pointer. why?????
{
	for (int i = 0; i < list->size(); i++)
	{
		cout << "list[" << i << "] == " << list->at(i) << endl;
	}
}

int main()
{
	List list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	cout << "list1" << endl;
	printList(&list1);
	cout << endl;
	List list2(list1);
	cout << "list2" << endl;
	printList(&list2);
	cout << endl;
	list1.insert_at(1, 6);
	list2.remove_at(2);
	cout << "list1" << endl;
	printList(&list1);
	cout << endl;
	cout << "list2" << endl;
	printList(&list2);
	cout << endl;
	return 0;
}
