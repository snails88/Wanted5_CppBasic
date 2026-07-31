#pragma once
#include <iostream>
class Point
{
public:
	Point(int x = 0, int y = 0);

	Point operator+(const Point& other) const;
	friend Point operator-(const Point& left, const Point& right);
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	
	void operator+=(const Point& other);

	void Print();

private:
	int x = 0;
	int y = 0;
};