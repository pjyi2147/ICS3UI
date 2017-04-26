// Lab 5.3.8 by Jeongseop Yi
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point2D
{
public:
	Point2D(double x, double y);
	string toString();
	double toDouble();

	double distanceTo(Point2D that);

private:
	double x;
	double y;
};

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

string Point2D::toString()
{
	string forReturn = "";
	forReturn += "(" + to_string(this->x) + "," + to_string(this->y) + ")";
	return forReturn;
}

double Point2D::distanceTo(Point2D that)
{
	return sqrt((this->x - that.x) * (this->x - that.x) + (this->y - that.y) * (this->y - that.y));
}


int main()
{
	double x, y;
	cin >> x >> y;
	Point2D point1(x, y);
	cin >> x >> y;
	Point2D point2(x, y);

	cout << point1.distanceTo(point2) << endl;
	return 0;
}
