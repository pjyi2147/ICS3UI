// Lab 5.3.5 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
	this->denominator = denominator;
	this->numerator = numerator;
}

string Fraction::toString() {
	int inte, remain;
	string forReturn = "";
	inte = this->numerator / this->denominator;
	remain = this->numerator % this->denominator;
	if (inte == 0) {
        if (((double) this->numerator / (double) this->denominator) < 0 && this->denominator < 0) {
            forReturn += "-" + to_string(remain) + "/" + to_string(abs(this->denominator));
        }
        else {
            forReturn += to_string(remain) + "/" + to_string(abs(this->denominator));
        }
	}
	else {
		forReturn += to_string(inte) + " " + to_string(remain) + "/" + to_string(abs(this->denominator));
	}
	return forReturn;
}

double Fraction::toDouble() {
	return (double) this->numerator / (double) this->denominator;
}

int main() {
	int num, den;
	string input = "";
	cin >> num >> input >> den;

	Fraction fraction(num, den);

	cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	return 0;
}
