#pragma once
#include <string>

using namespace std;

class matrix
{
	int height = 0;
	int width = 0;
	int** matrix1;

public:
	matrix(int height, int width, int val = 0);
	matrix operator* (matrix& m);
	matrix operator+ (matrix& m);
	matrix operator- (matrix& m);

	matrix& operator* (int x);
	matrix& operator+ (int x);
	matrix& operator- (int x);

	int* operator() (int x, int y);

	bool compatible(matrix m);
	int getHeight();
	int getWidth();

	string printMatrix();
};

class incompatible : public runtime_error
{
public:
	incompatible(string k);
};
