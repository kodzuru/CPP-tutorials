#include "Fraction.h"
using namespace std;


Fraction::Fraction()
{
	f.m = 0;
	f.n = 1;
}
Fraction::Fraction(int M, int N)
{
	if ( N == 0) {
		cout << "Вы вводите НУЛЬ в знаменатель. НА НУЛЬ ДЕЛИТЬ НЕЛЬЗЯ!" << endl;
	}
	else {
		f.m = M;
		f.n = N;
		Fraction_reduction();
	}
}
void Fraction::Fraction_reduction()
{
	int b = f.m;
	int a = f.n;
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	int GCD = a; //НОД
	f.n /= GCD;
	f.m /= GCD;
}
Fraction::~Fraction()
{
}
Fraction Fraction::operator+(Fraction& f1) {
	if (f1.f.n == f.n) {
		return Fraction(f.m + f1.f.m, f.n);
	}
	else {
		return Fraction(f.m*f1.f.n + f1.f.m*f.n, f.n*f1.f.n);
	}
}
Fraction Fraction::operator-(Fraction& f1) {
	if (f1.f.n == f.n) {
		return Fraction(f.m - f1.f.m, f.n);
	}
	else {
		return Fraction(f.m*f1.f.n - f1.f.m*f.n, f.n*f1.f.n);
	}
}
Fraction Fraction::operator*(Fraction& f1) {
	return Fraction(f.m*f1.f.m, f.n*f1.f.n);
}
Fraction Fraction::operator/(Fraction& f1) {
	return Fraction(f.m*f1.f.n, f.n*f1.f.m);
}
ostream& operator<<(ostream& os, const Fraction& f1)
{
	os << "m/n = " << f1.f.m << " / " << f1.f.n << endl;
	return os;
}