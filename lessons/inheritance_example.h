#pragma once
#include <iostream>

class A
{
public: // публичное наследование
	A(int a) {};
	A() {};
	void whowA()
	{
		std::cout << "A" << std::endl;
	}
protected: //как private для класса А
	void Print() {
		std::cout << "Print" << std::endl;
	}
};

// публичное наследование public А. Все публичные методы наследуются
//закрытое наследование private A. Все публичные методы стали private методами производного класса
// Все protected стали private;

class B : protected A //и public и protected попадёт в производный класс в protected
{
public:
	void whowB()
	{
		//this->Print(); //демонстрация протектед наследования
		std::cout << "B" << std::endl;
		//this->whowA();// при закрытом наследовании могу обращаться к прайвет внутри класса		
	}
protected:
	//все члены базового класса попадают все protected;

};

class C : protected B // открытое наследование доступ к методу класса А получить нельзя если class B:private A
{
public:
	void whowС()
	{
		std::cout << "С" << std::endl;		
		//this->Print(); //метод протектед родительского класса доступен через множественное наследование
	}
};