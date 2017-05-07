// Lab 6.3.1 by Jeongseop Yi
#include  <iostream>

using namespace std;

class Tree
{
public:
	virtual void Draw()
	{

	}
};

class Tree1 : public Tree
{
	void Draw()
	{
		cout << " /\\" << endl << "//\\\\" << endl;
	}
};

class Tree2 : public Tree
{
	void Draw()
	{
		cout << " /\\" << endl << "/**\\" << endl;
	}
};

class Tree3 : public Tree
{
	void Draw()
	{
		cout << " /\\" << endl << "/**\\" << endl;
	}
};

int main()
{
	Tree* trees[3];
	trees[0] = new Tree1;
	trees[1] = new Tree2;
	trees[2] = new Tree3;

	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i+1 << ":" << endl;
		trees[i]->Draw();
	}

}
