#include "Complex.h"

using namespace std;

Complex::Complex()
{
	C.Im = 0;
	C.Re = 0;
}
Complex::Complex(double re, double im)
{
	C.Im = im;
	C.Re = re;
}
Complex::~Complex()
{
}
Complex Complex::operator+(const Complex& c1)
{
	return Complex(C.Re+c1.C.Re, C.Im + c1.C.Im);
}
Complex Complex::operator-(const Complex& c1)
{
	return Complex(C.Re - c1.C.Re, C.Im - c1.C.Im);
}
Complex Complex::operator*(const Complex& c1)
{
	return Complex(C.Re*c1.C.Re - C.Im*c1.C.Im, C.Im*c1.C.Re + C.Re*c1.C.Im);
}
Complex Complex::operator/(const Complex& c1)
{
	return Complex((C.Re*c1.C.Re + C.Im*c1.C.Im)/(pow(c1.C.Re, 2) + pow(c1.C.Im, 2)), 
		(C.Im*c1.C.Re - C.Re*c1.C.Im)/(pow(c1.C.Re, 2) + pow(c1.C.Im, 2)));
}
std::ostream& operator<<(std::ostream& os, const Complex& c1)
{
	os << "Complex number is:  " << c1.C.Re << " + i" << c1.C.Im << endl;
	return os;
}
double Complex::Module()
{
	return sqrt(C.Re*C.Re + C.Im*C.Im);
}