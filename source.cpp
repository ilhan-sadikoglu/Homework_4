#include <iostream>
#include <vector>
#include <array>
#include "triangle.h"
#include "Quadrilateral.h"
#include "point.h"
#include <math.h>
Triangle::Triangle(const Point& k, const Point& l, const Point& m, const Color& color)
{
	setA(k);
	setB(l);
	setC(m);
	this->color = color;
}


Triangle::Triangle(const vector<Point>& pts, const Color& color)
{

	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);

	this->color = color;

}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
 {

	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);

	this->color = color;


}

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

auto Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	//PINK, RED, BLUE, WHITE, BLACK, GREEN
	switch (color)
	{
	case Triangle::Color::RED: return "RED";
	case Triangle::Color::GREEN: return "GREEN";
	case Triangle::Color::BLUE: return "BLUE";
	case Triangle::Color::PINK: return "PINK";
	case Triangle::Color::WHITE: return "WHITE";
	case Triangle::Color::BLACK: return "BLACK";
	}
}

double Triangle::getPerimeter() const noexcept
{
	
	return k+l+m;
}

bool Triangle::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::isValid() const
{
	if (k + l > m&& k + m > l&& l + m > k)
		return true;
	else return false;
}

double Triangle::printInfo() const noexcept
{
	// Ekrana þunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/
	cout << "Triangle" << endl << "Number of points: 3" << endl << "Points: " << "(" << a.x << "," << a.y << ")" << "(" << b.x << "," << b.y << ")" << "(" << c.x << "," << c.y << ")" << endl << "Perimeter: " << getPerimeter() << endl << "Color: "<<getColorAsString()<<endl;



}


