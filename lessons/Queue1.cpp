#include "Queue1.h"

using namespace std;

Queue1::Queue1(int n)
{
	reverse_index = 0;
	Max = 1000;
	index = 0;
	if (n <= Max) {
		arr = new int[n];
		Max = n;
	}
	else {
		cout << "Вы вышли за пределы возможностей очереди" << endl;
	}
}

Queue1::~Queue1()
{
	delete[] arr;
}

void Queue1::push(int x)
{
	if (index < Max) {
		arr[index] = x;
		index++;
	}
	else {
		cout << "Превышено количество возможных элементов" << endl;
	}	
}
int Queue1::pop()
{
	if (reverse_index > index) {
		cout << "Невозможно получить элемент, т.к. больше ничего не осталось" << endl;
		return 0;
	}
	else {
		Max--;
		return arr[reverse_index++];		
	}
}
bool Queue1::Is_empty()
{
	if (Max > 0) {
		return false;
	}
	else {
		return true;
	}
}
bool Queue1::Is_full()
{
	if (index == Max) {
		return true;
	}
	else {
		return false;
	}
}