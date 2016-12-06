#include "Figure.h"


// Главный класс фигура
Figure::Figure()
{
	Coordinates = NULL;
	n = 0;
}
Figure::Figure(Point* xy, int size)
{
	Coordinates = new Point[size];
	n = size;
	for (int i(0); i < size; i++) {
		Coordinates[i] = xy[i];
	}
}
Figure::Figure(Figure& f)
{
	Coordinates = new Point[f.n];
	n = f.n;
	for (int i(0); i < f.n; i++) {
		Coordinates[i] = f.Coordinates[i];
	}
}
Figure::~Figure()
{
	delete[] Coordinates;
}
std::ostream& operator<<(std::ostream& os, const Figure& f)
{
	for (int i(0); i < f.n; i++) {
		os << f.Coordinates[i].x << "   " << f.Coordinates[i].y << std::endl;
	}
	return os;
}
std::istream& operator>>(std::istream& is, Figure& f) {
	std::cout << "Введите кол-во точек в фигуре: ";
	is >> f.n;
	f.Coordinates = new Point[f.n];
		for (int i(0); i < f.n; i++) {
			std::cout << "Введите " << i + 1 << " point:\n";
			std::cout << "x:";
			is >> f.Coordinates[i].x;
			std::cout << "y:";
			is >> f.Coordinates[i].y;
		}
	return is;
}
double Figure::distance(int i1, int i2) {
	double x1, x2, y1, y2;
	x1 = Coordinates[i1].x;
	y1 = Coordinates[i1].y;
	x2 = Coordinates[i2].x;
	y2 = Coordinates[i2].y;
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
Point& Figure::operator[](int i) {
	return Coordinates[i];
}
// дочерний класс круг

Circle::Circle():Figure(), radius(0)
{
}
Circle::Circle(Point* xy, double r) : Figure(xy,1), radius(r)
{
}
Circle::Circle(Figure& f):Figure(f)
{
	radius = f.distance(0, 1);
}
Circle::~Circle()
{
}
double Circle::Area() {
	return radius*radius*3.14159265358979323846;
}
double Circle::Radius() {
	return radius;
}

//дочерний класс квадрат
Rectangle::Rectangle() : Figure(), a(0), b(0)
{
}
Rectangle::Rectangle(Figure& f) : Figure(f)
{
	a = f.distance(0, 1);
	b = f.distance(1, 2);
}
double Rectangle::Area()
{
	return a*b;
}
Rectangle::~Rectangle() {

}