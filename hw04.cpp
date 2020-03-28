#include <iostream>
#include <vector>
#include "triangle.h"
#include "Quadrilateral.h"
#include <random>
#include <time.h>

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle>& v, int numberOfItems = 100)
{
	for (int i = 0; i < numberOfItems; i++) {
		default_random_engine motor(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> randomInt(1, 100);
		int a = randomInt(motor);
		int b = randomInt(motor);
		int c = randomInt(motor);
		int d = randomInt(motor);
		int e = randomInt(motor);
		int f = randomInt(motor);

		default_random_engine mt(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> randomcolor(1, 5);
		int renk = randomcolor(mt);
		Triangle::Color  color;
		switch (renk)
		{
		case 1: color = Triangle::Color::RED;
		case 2: color = Triangle::Color::GREEN;
		case 3: color = Triangle::Color::BLUE;
		case 4: color = Triangle::Color::WHITE;
		case 5: color = Triangle::Color::BLACK;
		case 6: color = Triangle::Color::PINK;
		}

		v.push_back(Triangle{ Point(a, b),  Point(c, d),  Point(e, f),color });
	}
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktalarýn x ve y deðerleri [0, 100] arasýnda olabilir.
   Þeklin renk deðeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral>& v, int numberOfItems = 100)
{
	for (int i = 0; i < numberOfItems; i++) {
		default_random_engine motor(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> randomInt(1, 100);
		int a = randomInt(motor);
		int b = randomInt(motor);
		int c = randomInt(motor);
		int d = randomInt(motor);
		int e = randomInt(motor);
		int f = randomInt(motor);
		int g = randomInt(motor);
		int h = randomInt(motor);

		default_random_engine mt(static_cast<unsigned int>(time(0)));
		uniform_int_distribution<unsigned int> randomcolor(1, 5);
		int renk = randomcolor(mt);
		Quadrilateral::Color  color;
		switch (renk)
		{
		case 1: color = Quadrilateral::Color::RED;
		case 2: color = Quadrilateral::Color::GREEN;
		case 3: color = Quadrilateral::Color::BLUE;
		case 4: color = Quadrilateral::Color::WHITE;
		case 5: color = Quadrilateral::Color::BLACK;
		}

		v.push_back(Quadrilateral{ Point(a, b),  Point(c, d),  Point(e, f), Point(g, h),color});
	}

}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluðu ve renk deðeri eþleþen ilk elemanýn indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T>& v, const T& key){






	return 0;
}


template<class T>
int sortByPerimeter(vector<T>& v)
{





	return 0;
}

int main()
{

	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	// Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};

	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{4, 0},  Point{9, 0},  Point{14, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{4, 4},  Point{4, 4},  Point{4, 4} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{4, 0},  Point{4, 4},  Point{4, 14} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{14, 0}, Point{0, 0} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{4, 0},  Point{9, 0},  Point{3, 20}, Point{10, 20} };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}