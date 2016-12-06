#include "virtual_destructors.h"
#include <iostream>
using namespace std;

A::A() {
	a = new int[10];
	cout << "Constructor A" << endl;
}
A::~A() {
	delete[] a;
	cout << "Destructor A" << endl;
}

B::B():A()
{
	a = new int[10];
	cout << "Constructor B" << endl;
}
B::~B() {
	delete[] a;
	cout << "Destructor B" << endl;
}