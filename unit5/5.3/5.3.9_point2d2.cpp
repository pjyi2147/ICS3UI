// Lab 5.3.9 by Jeongseop Yi
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
	double getSlope(Point2D that);
	double getx();
	double gety();
private:
	double x;
	double y;
};

class Line2D
{
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString();

private:
	double slope;
	double y_intercept;
};

// point2d initializer
Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

// line2d initializer
Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	double slope = pointA.getSlope(pointB);
	double y_intercept = pointA.gety() - (slope*pointA.getx());
	this->slope = slope;
	this->y_intercept = y_intercept;
}

Line2D::Line2D(double slope, double y_intercept)
{
	this->slope = slope;
	this->y_intercept = y_intercept;
}

// point2d toString
string Point2D::toString()
{
	string forReturn = "";
	forReturn += "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
	return forReturn;
}

// line2d toString
string Line2D::toString()
{
	string forReturn = "";
	forReturn += "y = " + to_string(this->slope) + "x";
	if (this->y_intercept >= 0)
	{
		forReturn += " + " + to_string(this->y_intercept);
	}
	else
	{
		forReturn += " - " + to_string(abs(this->y_intercept));
	}
	return forReturn;
}

// Point2d get methods
double Point2D::distanceTo(Point2D that)
{
	return sqrt((this->x - that.x) * (this->x - that.x) + (this->y - that.y) * (this->y - that.y));
}

double Point2D::getx()
{
	return this->x;
}

double Point2D::gety()
{
	return this->y;
}

double Point2D::getSlope(Point2D that)
{
	return (that.gety() - this->y) / (that.getx() - this->x);
}

// Line2d get methods


// main
int main()
{
	double x, y;
	cin >> x >> y;
	Point2D point1(x, y);
	cin >> x >> y;
	Point2D point2(x, y);

	Line2D l1(point1, point2);
	cout << l1.toString() << endl;
	return 0;
}
