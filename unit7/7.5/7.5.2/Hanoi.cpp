#include "Hanoi.h"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

inexistTower::inexistTower(const string& msg) : out_of_range(msg) {}
invalidMovement::invalidMovement(const string& msg) : invalid_argument(msg) {}

Hanoi::Hanoi()
{
	for (int i = 3; i > 0; i--)
	{
		tower1.push_back(i);
	}
}

void Hanoi::move(char fromTower, char toTower)
{
	list<int>* fTower;
	list<int>* tTower;
	switch (fromTower)
	{
	case '1': fTower = &this->tower1;
		break;
	case '2':	fTower = &this->tower2;
		break;
	case '3':	fTower = &this->tower3;
		break;
	default: throw inexistTower("NO matching tower for FromTower");
	}

	switch (toTower)
	{
	case '1':   tTower = &this->tower1;
		break;
	case '2':	tTower = &this->tower2;
		break;
	case '3':	tTower = &this->tower3;
		break;
	default: throw inexistTower("NO matching tower for toTower. Try Again.");
	}
	if (fTower->size() > 0 && tTower->size() > 0)
	{
		if (fTower->back() > tTower->back())
		{
			throw invalidMovement("The block on the toTower is bigger than the one on the fromtower. Try again.");
		}
		else
		{
			tTower->push_back(fTower->back());
			fTower->pop_back();
		}
	}
	else if (fTower->size() > 0 && tTower->size() == 0)
	{
		tTower->push_back(fTower->back());
		fTower->pop_back();
	}
	else
	{
		throw invalidMovement("There is no block in fromblock. NO operation possible.");
	}
}

void Hanoi::printTower()
{
	cout << "tower_1: ";
	if (this->tower1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		for (list<int>::const_iterator iterator = tower1.begin(), end = tower1.end(); iterator != end; ++iterator)
		{
			cout << *iterator << " ";
		}
		cout << endl;
	}
	cout << "tower_2: ";
	if (this->tower2.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		for (list<int>::const_iterator iterator = tower2.begin(), end = tower2.end(); iterator != end; ++iterator)
		{
			cout << *iterator << " ";
		}
		cout << endl;
	}
	cout << "tower_3: ";
	if (this->tower3.empty())
	{
		cout << "empty";
	}
	else
	{
		for (list<int>::const_iterator iterator = tower3.begin(), end = tower3.end(); iterator != end; ++iterator)
		{
			cout << *iterator << " ";
		}
		cout << endl;
	}
}
