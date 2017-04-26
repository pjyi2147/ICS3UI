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
	//cout << "+Node" << endl;
}

Node::~Node()
{
	//cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	Node* pop_front();
	int size();
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

int main()
{
	List list;
    for (int i = 0; i <= 5; i++)
    {
        list.push_front(i);
        cout << "pushed " << i << ", size: " << list.size() << endl;
    }
    cout << endl;
    for (int i = 0; i <= 3; i++)
    {
        int value;
        list.pop_front();
        cout << "popped " << i << ", size: " << list.size() << endl;
    }
	return 0;
}
