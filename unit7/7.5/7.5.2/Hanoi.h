#ifndef _Hanoi
#define _Hanoi
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Hanoi
{
	list<int> tower1;
	list<int> tower2;
	list<int> tower3;
public:
	Hanoi();
	void printTower();
	void move(char fromTower, char toTower);
};

class inexistTower : public out_of_range
{
public:
	inexistTower(const string &msg);
};

class invalidMovement : public invalid_argument
{
public:
	invalidMovement(const string &msg);
};

#endif // _Hanoi
