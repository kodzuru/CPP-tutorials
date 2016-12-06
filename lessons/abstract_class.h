#pragma once


class Abstract
{
private:	
	double radius;
public:
	// любые методы
	Abstract();
	~Abstract();
	//для того чтобы сделать класс абстрактным надо:
	// объявить одну виртуальную функцию и присвоить ей значение 0
	virtual void draw() = 0; // делает класс абстрактным
private:

};

