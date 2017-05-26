#pragma once
#include <string>

using namespace std;

class matrix
{
	int mat[2][2];
	int num = 0;
public:
	matrix& operator<< (int x);
	int getNum();
	void pushMatrix(int n, int x);
	void printMatrix();
};
