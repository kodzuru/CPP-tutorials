#pragma once
#include <iostream>
typedef unsigned int ui;
class time
{
private:
	ui seconds;
	ui minutes;
	ui hours;
public:
	time();
	time(ui);
	time(ui, ui, ui);
	~time();
	time operator+(const time&) const; // перегрузка операции сложения(+)
	void operator<<(std::ostream&) const; // перегрузка оператора cout
	//дружественная функция(ей видны приват переменные класса) типа друг класса
	//в описании указывается без time::
	//нужна чтобы работало и слева и справа t3+5 || 5+t3
	// для того чтобы работало справа нужно ретёрнить std::ostream&
	friend std::ostream& operator<<(std::ostream&,const time&); 
};

