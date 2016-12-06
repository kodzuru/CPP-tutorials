#include "template_class.h"
#include <iostream>
using namespace std;

//http://www.cyberforum.ru/cpp-beginners/thread1798717.html#post9488987

template <typename T> Array<T>::Array(int size) {
	Max = size;
	current_index = 0;
	arr = new T[Max];
}
template <typename T> Array<T>::~Array()
{
	delete[] arr;
}
template <typename T> T Array<T>::operator[](int index) {
	if (index < 0 || index >(Max - 1)) {
		cout << "отрицательный индекс" << endl;
		_getch();
		abort();
	}
	else {
		return arr[index];
	}
}
template <typename T> void Array<T>::push(T n) {
	arr[current_index] = n;
	current_index++;
}
template Array<int>;