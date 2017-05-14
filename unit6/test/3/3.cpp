/*
*  10/05/17
*  ICS3UI
*  Unit test 6 #3
*  Jeongseop Yi
*  Mr. Damian
*/

#include <iostream>
#include <string>

using namespace std;

long long int getNumber(int blocks)
{
	if (blocks == 1)
	{
		return 1;
	}
	// An+1 = 2An + 1
	return 2 * getNumber(blocks - 1) + 1;
}

void MoveDisk(int frompole, int topole)
{
	cout << frompole << " -> " << topole << endl;
}

void MovePole(int blocks, int startpole, int endpole, int withpole)
{
	if (blocks >= 1)
	{
		// move the top one to the other empty one
		MovePole(blocks - 1, startpole, withpole, endpole);
		// move the Disk we want
		MoveDisk(startpole, endpole);
		// move the top disks back to the endpole
		MovePole(blocks - 1, withpole, endpole, startpole);
	}
}

void Hanoi(int blocks, int startpole, int endpole, int withpole)
{
	cout << "The needed steps are " << getNumber(blocks) << " steps" << endl;
	MovePole(blocks, startpole, endpole, withpole);
}


int main()
{
	cout << "This program calculates and shows the solution of mininum number of moves given a Hanoi tower." << endl;
	cout << "Input the number of blocks: ";
	int x;
	cin >> x;
	//cout << getNumber(x);
	Hanoi(x, 1, 3, 2);
	cin >> x;
	return 0;
}
