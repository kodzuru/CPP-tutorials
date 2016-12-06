#pragma once
#include <iostream>
#include <conio.h>
//можно задать по умолчанию вызов Array<> a(2);
template <typename T = int>
class Array
{
private:
	T* arr;
	int Max;
	int current_index;
public:
	Array(int);
	~Array();
	T operator[](int);
	void push(T);

};




