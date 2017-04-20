// Lab 5.1.3 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class AdHocSquare {
public:
	AdHocSquare(double side);
	void set_side(double side) {
		this->side = side;
	}
	double get_area() {
		return this->side*this->side;
	}
private:
	double side;
};

class LazySquare {
public:
	LazySquare(double side);
	void set_side(double side) {
		this->side = side;
		this->side_changed = 1;
	}
	double get_area() {
		if (this->side_changed) {
			this->area = this->side*this->side;
			this->side_changed = 0;
			return this->area;
		}
		else {
			return this->area;
		}
	}
private:
	double side;
	double area;
	bool side_changed;
};

AdHocSquare::AdHocSquare(double side) {
	this->side = side;
}

LazySquare::LazySquare(double side) {
	this->side = side;
}

int main() {
	AdHocSquare s1(4);
	LazySquare s2(4);
	cout << "Adhoc:" << s1.get_area() << endl;
	cout << "Lazy:" << s2.get_area() << endl;
	s1.set_side(130);
	s2.set_side(130);
	cout << "Adhoc:" << s1.get_area() << endl;
	cout << "Lazy:" << s2.get_area() << endl;

	cout << "Adhoc:" << s1.get_area() << endl;
	cout << "Lazy:" << s2.get_area() << endl;

}
