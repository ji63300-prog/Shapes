#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Shape {
protected: 
	int width;
	int height;
	int radius;
public: 
	Shape(int w = 0, int h = 0, int r = 0):
		width(w), height(h), radius(r) {
	}

	double getArea() {
		return width * height;
	}

	double getPerimiter() {
		return 2 * (width + height);
	}

	//double getCircumference() {
	//	return 2 * radius * 3.14;
	//}
};

class Circle : public Shape {
protected:
public:
	Circle(int r):
		Shape(0, 0, r) {
	}

	double getPerimiter() {
		return 2 * radius * 3.14;
	}

	double getArea() {
		return 3.14 * radius * radius;
	}
};

class Rectangle : public Shape {
protected:
public:
	Rectangle(int w, int h) :
		Shape(w, h, 0) {
	}

	double getPerimiter() {
		return 2 * (width + height);
	}

	double getArea() {
		return width * height;
	}
};

class Square : public Rectangle {
public:
	Square(int s) :
		Rectangle(s, s) {
	}

};


class RightTri : public Shape {
protected:
public:
	RightTri(int w, int h) :
		Shape(w, h, 0) {
	}

	double getPerimiter() {
		return width + height + sqrt((width * width) + (height * height));
	}

	double getArea() {
		return (width * height)/2;
	}
};

class IsoRightTri : public RightTri {
protected:
public:
	IsoRightTri(int w) :
		RightTri(w, w) {
	}

	double getPerimiter() {
		return width * (2 + sqrt(2));
	}

	double getArea() {
		return (width * width) / 2;
	}
};

int main()
{
	Circle circleTest(5);
	assert(circleTest.getArea() > 78.4 && circleTest.getArea() < 78.6);
	assert(circleTest.getPerimiter() > 31.3 && circleTest.getPerimiter() < 31.5);

	Rectangle rectTest(8, 3);
	assert(rectTest.getArea() == 24);
	assert(rectTest.getPerimiter() == 22);

	RightTri triTest(5, 12);
	assert(triTest.getArea() == 30);
	assert(triTest.getPerimiter() == 30); 

	Square squareTest(7);
	assert(squareTest.getArea() == 49);
	assert(squareTest.getPerimiter() == 28);

	IsoRightTri isoTest(4);
	assert(isoTest.getArea() == 8);
	assert(isoTest.getPerimiter() > 13.65 && isoTest.getPerimiter() < 13.66);

	cout << "All assert tests passed!" << endl << endl;



	Circle c1 = Circle(3);
	cout << "Circle radius is 3" << endl;
	cout << "Circle perimeter is " << c1.getPerimiter() << endl;
	cout << "Circle area is  " << c1.getArea() << endl;
	cout << endl;

	Rectangle r1 = Rectangle(4, 5);
	cout << "Rectangle has a width of 4 and a height of 5" << endl;
	cout << "Rectangle has a perimeter of " << r1.getPerimiter() << endl;
	cout << "Rectangle has an area of " << r1.getArea() << endl;
	cout << endl;

	RightTri t1 = RightTri(3, 4);
	cout << "Right Triangle has a base of 3 and a height of 4" << endl;
	cout << "Right triangle has a perimeter of " << t1.getPerimiter() << endl;
	cout << "Right Triangle has an area of " << t1.getArea() << endl;
	cout << endl;

	Square s1 = Square(2);
	cout << "Square has a side length of 2" << endl;
	cout << "Square has a perimeter of " << s1.getPerimiter() << endl;
	cout << "Square has an area of " << s1.getArea() << endl;
	cout << endl;

	IsoRightTri rt1 = IsoRightTri(6);
	cout << "Isosceles Right Triangle has a leg of 6" << endl;
	cout << "Isosceles Right Triangle has a perimeter of " << rt1.getPerimiter() << endl;
	cout << "Isosceles Right Triangle has an area of " << rt1.getArea() << endl;
	cout << endl;


}

