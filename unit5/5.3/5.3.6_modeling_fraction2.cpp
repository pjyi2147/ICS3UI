// Lab 5.3.6 by Jeongseop Yi
#include <iostream>
#include <string>

using namespace std;

int gcd(int x, int y)
{
    // not to have div 0 exception
	if (x != 0 && y != 0)
	{
		int r = 0;
		int a = (x > y) ? x : y; // a is greater number
		int b = (x < y) ? x : y; // b is smaller number

		r = b;
		while (a % b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return r;
	}
	else
	{
		return 1;
	}
}

int lcm(int x, int y)
{
	int k = gcd(x, y);
	return x * y / k;
}

class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
	// calculation methods
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);

private:
	int numerator;
	int denominator;
	void reduce();
};

// initializer
Fraction::Fraction(int numerator, int denominator) {
	this->denominator = denominator;
	this->numerator = numerator;
}

void Fraction::reduce()
{
	int gcd1 = gcd(this->numerator, this->denominator);
	this->numerator = this->numerator / gcd1;
	this->denominator = this->denominator / gcd1;
}

// print
string Fraction::toString() {
	string forReturn = "";
	int inte = this->numerator / this->denominator;
	int remain;
	if (inte < 0) {
        remain = abs(this->numerator % this->denominator);
	}
	else {
        remain = this->numerator % this->denominator;
	}
	if (inte == 0) {
		if (((double) this->numerator / (double) this->denominator) < 0 && this->denominator < 0) {
			forReturn += "-" + to_string(remain) + "/" + to_string(abs(this->denominator));
		}
		else if (remain == 0) {
            forReturn += '0';
		}
		else {
			forReturn += to_string(remain) + "/" + to_string(abs(this->denominator));
		}
	}
	else if (remain == 0)
	{
		forReturn += to_string(inte);
	}
	else {
		forReturn += to_string(inte) + " " + to_string(remain) + "/" + to_string(abs(this->denominator));
	}
	return forReturn;
}

// calculation
double Fraction::toDouble() {
	return (double) this->numerator / (double) this->denominator;
}

// methods
Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::minus(Fraction that)
{
	int num = (this->numerator * that.denominator) - (this->denominator * that.numerator);
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::plus(Fraction that)
{
	int num = (this->numerator * that.denominator) + (this->denominator * that.numerator);
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

int main() {
	int num, den;
	string input = "";
	cin >> num >> input >> den;
	Fraction fraction1(num, den);

	cin >> num >> input >> den;
	Fraction fraction2(num, den);

	cout << fraction1.toString() << " + " << fraction2.toString() << " = " << fraction1.plus(fraction2).toString() << endl;
	cout << fraction1.toString() << " - " << fraction2.toString() << " = " << fraction1.minus(fraction2).toString() << endl;
	cout << fraction1.toString() << " * " << fraction2.toString() << " = " << fraction1.times(fraction2).toString() << endl;
	cout << fraction1.toString() << " / " << fraction2.toString() << " = " << fraction1.by(fraction2).toString() << endl;

	return 0;
}
