#include "Point.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	std::cout << "(" << point.x << "," << point.y << ")\n";
	return os;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;
	//p3 = p1.operator+(p2);

	Point p4 = p1 - p2;
	p3.Print();
	p4.Print();
	p3 += p4;
	std::cout << p3;
	//p1.Print();
	//p2.Print();
	//p3.Print();
	//p4.Print();
}