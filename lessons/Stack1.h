#pragma once
#include <iostream>

class Stack1
{
private:
	int* arr;
	int Max;
	int index;
public:
	Stack1(int);
	~Stack1();
	bool Push(int);
	int Pop();
	bool Is_empty();
	bool Is_full();
};

