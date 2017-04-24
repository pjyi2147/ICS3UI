// Lab 5.1.2 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class Square {
public:
	Square(double side);
	void set_side(double side) {
		if (side > 0) {
			this->side = side;
			this->area = side*side;
		}
	}
	void print() {
		cout << "Square: side=" << this->side << " area=" << this->area << endl;
	}

private:
	double side;
	double area;
};

Square::Square(double side) {
	this->side = side;
	this->area = side*side;
}

int main() {
	Square s(4);
	s.print();
	s.set_side(2);
	s.print();
	s.set_side(-33);
	s.print();
	return 0;
}
