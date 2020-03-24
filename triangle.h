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

	/* Ucgen olup olmad���n� kontrol eder.
	 * Bu fonksiyonun t�m yap�c�lar ve setter fonksiyonlar i�inde do�rudan/dolayl� olarak �a�r�lmas� zorunludur.
	 * E�er verilen de�erler bir ��gen olu�turmuyorsa invalid_argument exception f�rlat�lmal� ve bu bu exception kontrol edilmelidir
	 * Program sonland�r�lmamal�d�r.
	 */
	bool isValid() const;

	double printInfo() const noexcept;
	// Ekrana �unu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/

	int k = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	int l = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
	int m = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));

private:
	array<Point, NUMBER_OF_CORNERS> pts;
	Color color;

};
