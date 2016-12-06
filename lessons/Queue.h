#pragma once
#include <iostream>
struct  A2 {
	int key;
};
struct queue {
	A2 a;
	queue* next;
	queue* back;
};
class Queue
{
private:
	queue* begin;
public:
	Queue();
	~Queue();
	void push(A2);
	int pop();
};

