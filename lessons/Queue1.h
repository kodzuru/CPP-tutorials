#pragma once
#include <iostream>
class Queue1
{
private:
	int* arr;
	int Max;
	int index;
	int reverse_index;
public:
	Queue1(int);
	~Queue1();
	void push(int);
	int pop();
	bool Is_empty();
	bool Is_full();
};

