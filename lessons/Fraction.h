#pragma once
#include <iostream>
struct F {
	int m;
	int n;
};
class Fraction
{
private:
	F f;
	void Fraction_reduction();
public:
	Fraction();
	Fraction(int, int);
	~Fraction();
	Fraction operator+(Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator*(Fraction&);
	Fraction operator/(Fraction&);
	friend std::ostream& operator<<(std::ostream&, const Fraction&);
};

