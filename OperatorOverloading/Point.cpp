#include "Point.h"
#include <iostream>

Point::Point(int x, int y)
	:x(x), y(y)
{
}

Point Point::operator+(const Point& other) const
{
	return Point(x + other.x, y + other.y);
}



void Point::operator+=(const Point& other)
{
	x += other.x;
	y += other.y;
}


void Point::Print()
{
	std::cout << "(" << x << "," << y << ")\n";
}

Point operator-(const Point& left, const Point& right)
{
	return Point(left.x - right.x, left.y - right.y);
}
