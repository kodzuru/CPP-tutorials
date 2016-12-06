#pragma once
class A 
{
private:
	int *a;
public:
	A();
	virtual ~A(); // virtual для того чтобы деструкторы вызывались в правильном порядке
};

class B : public A
{
private:
	int *a;
public:
	B();
	virtual ~B();
};
