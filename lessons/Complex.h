#pragma once
#include <iostream>
struct dot {
	double Im;
	double Re;
};
class Complex
{
private:
	dot C;
public:
	Complex();
	Complex(double, double);
	~Complex();
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);
	friend std::ostream& operator<<(std::ostream&, const Complex&);

	double Module();
};

