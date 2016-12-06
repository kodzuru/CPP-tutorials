#pragma once
#include <iostream>
#include <math.h>
class A
{
public:
	virtual void show() {
		std::cout << "A" << std::endl;
	}

};

class B : public A // открытое наследование
{
public:
	virtual void show() {
		std::cout << "B" << std::endl;
	}
};
