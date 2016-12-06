#pragma once
#include <iostream>
#include <math.h>
struct Point {
	int x;
	int y;
};
class Figure
{
private:
	Point* Coordinates;
	int n;
public:
	Figure();
	Figure(Point* xy, int);
	Figure(Figure&);
	~Figure();
	friend std::ostream& operator<<(std::ostream&, const Figure&);
	friend std::istream& operator >> (std::istream&, Figure&);
	double distance(int, int);
	Point& operator[](int);

};
class Circle : public Figure
{
private:
	double radius;
public:
	Circle();
	Circle(Point*,double);
	Circle(Figure&);
	~Circle();
	double Area();
	double Radius();
};
class Rectangle : public Figure
{
private:
	double a;
	double b;
public:
	Rectangle();
	Rectangle(Figure&);
	~Rectangle();
	double Area();

};


