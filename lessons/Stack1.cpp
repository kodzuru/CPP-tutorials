#include "Stack1.h"

using namespace std;

Stack1::Stack1(int number)
{
	index = 0;
	Max = 1000;
	if (number <= Max) {
		arr = new int[number];
		Max = number;
	}
	else {
		cout << "Переполнение стека" << endl;
	}

}
Stack1::~Stack1()
{
	delete[] arr;
}
bool Stack1::Push(int n)
{
	if (index == Max) {
		cout << "Невозможно положить в стек, т.к. стек переполнен" << endl;
		return false;
	}
	else {
		arr[index] = n;
		index++;
		return true;
	}
}
int Stack1::Pop()
{
	if (index < 0) {
		cout << "Невозможно получить элемент, т.к. больше ничего не осталось" << endl;
		return 0;
	}
	else {
		return arr[--index];
	}
}
bool Stack1::Is_empty() {
	if (index <= 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Stack1::Is_full() {
	if (index == Max) {
		return true;
	}
	else {
		return false;
	}
}