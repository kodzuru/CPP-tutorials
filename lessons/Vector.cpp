#include "Vector.h"
#define _USE_MATH_DEFINES
#include <math.h>


Vector::Vector()
{
	mode = Decart;
	x = 0;
	y = 0;
	Dec_to_polar();
}
Vector::Vector(double a, double b, vec M)
{
	switch (M)
	{
		case Decart:
			mode = M;
			x = a;
			y = b;
			Dec_to_polar();
			break;
		case Polar:
			mode = M;
			module = a;
			angle = b;
			Polar_to_decart();
			break;
	}
}
Vector::~Vector()
{
}
void Vector::Dec_to_polar()
{
	module = sqrt(x*x + y*y);
	angle = atan2(x, y);
}
void Vector::Polar_to_decart()
{
	x = module*cos(angle);
	y = module*sin(angle);
}
double Vector::operator+()
{
	return module;
}
Vector Vector::operator+(const Vector& v)
{
	Vector result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.Dec_to_polar();
	return result;

}
Vector Vector::operator-()const
{
	return Vector(-x, -y, Decart);
}
Vector Vector::operator-(const Vector& v)const
{
	Vector result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.Dec_to_polar();
	return result;

}
Vector Vector::operator*(double A)const
{
	return Vector(x*A, y*A, Decart);
}
Vector operator*(double A, const Vector& v1)  //friend
{
	return v1*A;
}
std::ostream& operator<<(std::ostream& os, const Vector& v1) //friend
{
	switch (v1.mode)
	{
	case Decart:
		os << "x: " << v1.x << " y: " << v1.y << std::endl;
		break;
	case Polar:
		os << "module: " << v1.module << " angle: " << v1.angle*(180/M_PI) << "°" << std::endl;
		break;
	}
	return os;
}
void Vector::ChangeMode(vec M) {
	mode = M;
}