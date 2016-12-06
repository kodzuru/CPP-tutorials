#pragma once
#include <iostream>
enum vec {
	Decart, Polar
};
class Vector
{
private:
	double x;
	double y;
	double angle;
	double module;
	void Dec_to_polar();
	void Polar_to_decart();
	vec mode;
public:
	Vector();
	Vector(double, double, vec M = Decart);
	~Vector();

	double operator+();
	Vector operator+(const Vector&);
	Vector operator-() const;
	Vector operator-(const Vector&) const;
	Vector operator*(double) const;
	friend Vector operator*(double, const Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	void ChangeMode(vec);
};

