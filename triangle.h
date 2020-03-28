#pragma once
#include <array>
#include <vector>
#include "point.h"

using namespace std;

class Triangle
{
public:
	constexpr static int NUMBER_OF_CORNERS{ 3 };
	enum class Color { PINK, RED, BLUE, WHITE, BLACK, GREEN };

	// Constructor
	Triangle(const Point &k = { 1, 0 }, const Point &l = { 0, 1 }, const Point &m = { 2, 1 }, const Color& color = Color::RED);
	Triangle(const vector<Point>& pts, const Color& color = Color::RED);
	Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color = Color::RED);

	const Point& a = pts[0];
	Point& b = pts[1];
	Point& c = pts[2];

	// Getter Functions
	Point getA() const noexcept;
	Point getB() const noexcept;
	Point getC() const noexcept;

	auto getColor() const noexcept;
	string getColorAsString() const noexcept;

	double getPerimeter() const noexcept;

	// Setter Functions
	bool setA(const Point& pt);
	bool setB(const Point& pt);
	bool setC(const Point& pt);

	/* Ucgen olup olmadýðýný kontrol eder.
	 * Bu fonksiyonun tüm yapýcýlar ve setter fonksiyonlar içinde doðrudan/dolaylý olarak çaðrýlmasý zorunludur.
	 * Eðer verilen deðerler bir üçgen oluþturmuyorsa invalid_argument exception fýrlatýlmalý ve bu bu exception kontrol edilmelidir
	 * Program sonlandýrýlmamalýdýr.
	 */
	bool isValid() const;

	double printInfo() const noexcept;
	// Ekrana þunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/

	double k = sqrt((a.coords[0] - b.coords[0]) * (a.coords[0] - b.coords[0]) + (a.coords[1] - b.coords[1]) * (a.coords[1] - b.coords[1]));
	double l = sqrt((b.coords[0] - c.coords[0]) * (b.coords[0] - c.coords[0]) + (b.coords[1] - c.coords[1]) * (b.coords[1] - c.coords[1]));
	double m = sqrt((a.coords[0] - c.coords[0]) * (a.coords[0] - c.coords[0]) + (a.coords[1] - c.coords[1]) * (a.coords[1] - c.coords[1]));

private:
	array<Point, NUMBER_OF_CORNERS> pts;
	Color color;

};
