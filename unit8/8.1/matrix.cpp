#include "matrix.h"
#include <iostream>
#include <exception>

using namespace std;

void matrix::pushMatrix(int n, int x)
{
	switch (n)
	{
	case 0: this->mat[0][0] = x;
		break;
	case 1: this->mat[0][1] = x;
		break;
	case 2: this->mat[1][0] = x;
		break;
	case 3: this->mat[1][1] = x;
		break;
	}
	this->num += 1;
}

int matrix::getNum()
{
	return this->num;
}


matrix& matrix::operator<<(int x)
{
	int n = this->getNum();
	pushMatrix(n, x);
	return *this;
}

void matrix::printMatrix()
{
	cout << this->mat[0][0] << " " << this->mat[0][1] << endl << this->mat[1][0] << " " << this->mat[1][1];
}
