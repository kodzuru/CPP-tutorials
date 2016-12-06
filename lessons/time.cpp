#include "time.h"
#include <iostream>


time::time()
{
	hours = minutes = seconds = 0;
}
time::time(ui s)
{
	hours = s / (60 * 60);
	minutes = s % (60 * 60) / 60;
	seconds = s % (60 * 60) % 60;
}
time::time(ui h, ui m, ui s)
{
	if (h > 24 || m > 60 || s > 60) {
		time::time();
		return;
	}
	hours = h;
	minutes = m;
	seconds = s;
}

time::~time()
{
}

time time::operator+(const time& t) const // пример реализации перегрузки операции сложения(+)
{
	time result;
	result.seconds = (seconds + t.seconds ) % 60;
	result.minutes = (minutes + t.minutes + (seconds + t.seconds)/60) % 60;
	result.hours = (hours + t.hours + (minutes + t.minutes) / 60);

	return result;
}
void time::operator<<(std::ostream& os) const // перегрузка оператора cout. вывод t3 << cout;
{
	os << hours << " : " << minutes << " : " << seconds << "\n";
}

std::ostream& operator<<(std::ostream& os, const time& t1) //пример реализации дружественной функции
{
	os << t1.hours << " : " << t1.minutes << " : " << t1.seconds << "\n";
	return os;
}