#pragma once
#include <iostream>
struct  A1{
	int key;
};
struct List {
	A1 a;
	List* next;
};
class Stack
{
private:
	List* next;
public:
	Stack();
	~Stack();	
	void push(A1);
	int pop();

	
};

