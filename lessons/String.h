#pragma once
#include <iostream>
#include <cstring>

typedef unsigned int ui;
class String
{
private:
	char* str;
	ui length;
	static int number_elem; //статическая переменная создаётся 1 раз для всех объектов класса
public:
	String();//конструктор по умолчанию
	explicit String(char*); //явный конструктор explicit - конструктор не учавствует в преобразованиях типов
	String(const String&); //конструктор копирования
	~String();
	friend std::ostream& operator<<(std::ostream&, const String&);
	String& operator=(const String&);
	operator char*(); // оператор явного преобразования типов
	static int f() // статический метод может работать только с переменными static
	{
		return number_elem;
	}
};

