// Lab 8.1.1 by Jeongseop Yi
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "matrix.cpp"

using namespace std;

int main()
{
	matrix m;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	m << a << b << c << d;
	m.printMatrix();
}
