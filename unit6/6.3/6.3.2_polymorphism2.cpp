// Lab 6.3.2 by Jeongseop Yi
#include  <iostream>

using namespace std;

class Piece
{
public:
	virtual	bool checkMove(string pos2)
	{
		return false;
	}
};

class Men : public Piece
{
	bool checkMove(string pos2)
	{
		int x = abs('b' - pos2[0]);
		int y = abs('1' - pos2[1]);

		if (y <= 1 && x <= 1)
		{
			return true;
		}
		return false;
	}
};

class King : public Piece
{
	bool checkMove(string pos2)
	{
		int x = abs('b' - pos2[0]);
		int y = abs('1' - pos2[1]);

		if (x == 0 || y == 0)
		{
			return true;
		}
		if (x == y)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Piece* men = new Men;
	Piece* king = new King;

	if (men->checkMove("c2")) cout << "true" << endl;
	else cout << "false" << endl;

	if (king->checkMove("d3")) cout << "true" << endl;
	else cout << "false" << endl;

	if (men->checkMove("d3")) cout << "true" << endl;
	else cout << "false" << endl;

}
