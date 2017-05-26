#include "matrix.h"
#include <iostream>
#include <exception>

using namespace std;

matrix::matrix(int height, int width, int val)
{
	this->height = height;
	this->width = width;
	this->matrix1 = new int* [height];
	for (int i = 0; i < height; i++)
	{
		this->matrix1[i] = new int[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			this->matrix1[i][j] = val;
		}
	}
}

int matrix::getHeight()
{
	return this->height;
}

int matrix::getWidth()
{
	return this->width;
}

bool matrix::compatible(matrix m)
{
	bool t = true;
	if (this->getHeight() != m.getHeight())
	{
		t = false;
	}
	if (this->getWidth() != m.getWidth())
	{
		t = false;
	}
	return t;
}

matrix matrix::operator*(matrix& m)
{
	try
	{
		if (this->compatible(m))
		{
			matrix c(height, width, 0);
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					*c(i, j) = *(*this)(i, j) * *m(i, j);
				}
			}
			return c;
		}
		else
		{
			throw incompatible("Two matrices are not compatible\n");
		}
	}
	catch(incompatible ex)
	{
		cout << ex.what();
		throw;
	}
}

matrix matrix::operator+(matrix& m)
{
	try
	{
		if (this->compatible(m))
		{
			matrix c(height, width, 0);
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					*c(i, j) = *(*this)(i, j) + *m(i, j);
				}
			}
			return c;
		}
		else
		{
			throw incompatible("Two matrices are not compatible\n");
		}
	}
	catch (incompatible ex)
	{
		cout << ex.what();
		throw;
	}
}

matrix matrix::operator-(matrix& m)
{
	try
	{
		if (this->compatible(m))
		{
			matrix c(height, width, 0);
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					*c(i, j) = *(*this)(i, j) - *m(i, j);
				}
			}
			return c;
		}
		else
		{
			throw incompatible("Two matrices are not compatible\n");
		}
	}
	catch (incompatible ex)
	{
		cout << ex.what();
		throw;
	}
}

matrix& matrix::operator*(int x)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			*(*this)(i, j) = *(*this)(i, j) * x;
		}
	}
	return *this;
}

matrix& matrix::operator+(int x)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			*(*this)(i, j) = *(*this)(i, j) + x;
		}
	}
	return *this;
}

matrix& matrix::operator-(int x)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			*(*this)(i, j) = *(*this)(i, j) - x;
		}
	}
	return *this;
}

int* matrix::operator()(int x, int y)
{
	return &this->matrix1[x][y];
}

string matrix::printMatrix()
{
	string k = "";
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			k += to_string(*(*this)(i,j)) + " ";
		}
		k += "\n";
	}
	return k;
}

incompatible::incompatible(string k) : runtime_error(k)
{

}
