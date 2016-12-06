#pragma once
#include <iostream>
#include <conio.h>
#include <climits>
#include <random>
#include <time.h>
#include <math.h>
using namespace std;
struct A {
	int key;
};

struct List {
	A a;
	List* next;
};

void Print(List* begin) {

	while (begin) {
		cout << begin->a.key << " -> ";
		begin = begin->next;
	}
	cout << "NULL" << endl;

}
void Init(List** begin, const A* a) {

	*begin = new List;
	(*begin)->a.key = 20;
	(*begin)->next = NULL;

	List* end = (*begin);
	for (int i(0); i < 5; i++) {
		end->next = new List;
		end = end->next;
		end->a.key = a[i].key;
		end->next = NULL;
	}
}
void AddBegin(List** begin, const A* a) {
	List* new_begin = new List;
	//new_begin = *begin;
	//List* begin = new List;
	new_begin->a.key = a->key;
	new_begin->next = *begin;
	*begin = new_begin;
}
void AddEnd(List** begin, const A* a) {
	List* p = *begin;
	List* t = new List;
	t->a = *a;
	t->next = NULL;
	while (1)
	{
		if (p->next == NULL) {
			p->next = t;
			break;
		}
		p = p->next;
	}
}
void Insert(List** begin, const A* a) {
	List* ins = new List;
	ins->a = *a;
	if (*begin == NULL) {
		ins->next = NULL;
		*begin = ins;
		return;
	}
	List* t = *begin;
	if (t->a.key >= ins->a.key) {
		ins->next = t;
		*begin = ins;
		return;
	}
	List *t1 = t->next;
	while (t1) {
		if (t->a.key <= ins->a.key && ins->a.key <= t1->a.key) {
			t->next = ins;
			ins->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
	t->next = ins;
	ins->next = NULL;
}
void Delete(List ** begin, const A* a)
{
	if (*begin == NULL) {
		return;
	}
	List* t = *begin;
	if (t->a.key == (*a).key) {
		*begin = t->next;
		delete t;
		return;
	}
	List* t1 = t->next;
	while (t1) {
		if (t1->a.key == (*a).key) {
			t->next = t1->next;
			delete t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
}
void Free(List** begin) {
	if (*begin == NULL)
		return;
	List* p = *begin;
	List* t;
	while (p) {
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
}


//работа с файломи
/*
struct point{
	int x;
	int y;
};
struct square {
	point bottom_point;
	point top_point;
};
int square_s(square &p) {
	int s;
	s = (p.top_point.y - p.bottom_point.y)*(p.top_point.x - p.bottom_point.x);
	return s;
}
void Print_1(ostream &os) {
os << "Hello World" << endl;
}
char* file_name = "data.txt";
ifstream fin(file_name);

string line;
int lines_count = 0;
if (fin.is_open())
{
	while (fin.good()) {
		getline(fin, line);
		lines_count++;
	}
}
fin.close();
ifstream fin1(file_name);
cout << lines_count << endl;
square kvadrat;
for (int j(0); j < lines_count; j++) {
	for (int i(0); i < 4; i++) {
		switch (i)
		{
		case 0:
			fin1 >> kvadrat.bottom_point.x;
			break;
		case 1:
			fin1 >> kvadrat.bottom_point.y;
			break;
		case 2:
			fin1 >> kvadrat.top_point.x;
			break;
		case 3:
			fin1 >> kvadrat.top_point.y;
			break;
		}
	}
	cout << square_s(kvadrat) << endl;
}
*/

//ДЗ
/*
int** INIT_ARRAY(int N, int M)
{
int**arr = new int*[N];
for (int i(0); i < N; i++) {
arr[i] = new int[M];
}
for (int i(0); i < N; i++) {
for (int j(0); j < M; j++) {
arr[i][j] = rand() % 10;
}
}
return arr;
}
template <typename T1>
void MOVE_POS(T1** arr, int str, int pos, int M) {
for (int i(0); i < pos%M; i++) {
for (int j(0); j < M; j++) {
swap(arr[str - 1][j], arr[str - 1][M - 1]);
}
}
}
template <typename T1>
void ARRAY_PRINT(T1** arr, int N, int M) {
for (int i(0); i < N; i++) {
for (int j(0); j < M; j++) {
if (j == M - 1) {
cout << arr[i][j];
}
else {
cout << arr[i][j] << "  |  ";
}
}
cout << endl;
}
}

*/

//шаблоны
template<typename T1,typename T2>
auto SUM(T1 a, T2 b) -> decltype(a+b)
{
	auto c = a + b;
	return c;
}
template<typename T1, typename T2>
void SWAP(T1 &a, T2 &b) {
	swap(a, b);
}
template<typename T1>
void SORT(T1* A, int N) {
	for (int i(0); i < N; i++) {
		for (int j(0); j < N; j++) {
			if (A[i] <= A[j]) {
				swap(A[i], A[j]);
			}
		}
	}
}
template<typename T1>
auto mean(T1* arr, int N)// -> decltype( sum / N )
{
	auto sum = 0;
	for (int i(0); i < N; i++) {
		sum += arr[i];
	}
	cout << sum << endl;
	return (double)sum / (double)N;
}
template <typename T1, typename T2>
auto FIND(T1 arr, int N, T2 x) -> decltype(arr) {
	for (int i(0); i < N; i++) {
		if (arr[i] == x) {
			return (arr+i);
		}
	}
	return NULL;
}

//рекурсия
void Rec(int level) {
	if (level == 0) {
		return;
	}
	cout << "Вызываем рекурсивную функцию с аргументом: " << level << endl;
	Rec(level - 1);
	cout << "Поднимаемся вверх по рекурсии со значением: " << level << endl;
}
void PRINT(char* str, int l, int r, int level) {
	if (level == 0)
		return;
	int middle = (l + r) / 2;
	str[middle] = '|';
	PRINT(str, l, middle, level - 1);
	PRINT(str, middle, r, level - 1);
}
template <typename T1>
void QUICK_SORT(T1 arr, int l, int r) {
	int i = l, j = r;
	int middle = arr[(i + j) / 2];
	do {
		while (middle > arr[i])
			i++;
		while (middle < arr[j])
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (i < r) {
		QUICK_SORT(arr, i, r);
	}
	if (j > l) {
		QUICK_SORT(arr, l, j);
	}
}
int FACT(int n) {
	if (n == 0 || n == 1)
		return 1;
	return n*FACT(n - 1);
}
template <typename T1>
auto FIND_ELEMENT(T1 arr, int n, int element) -> decltype(n)
{
	if (!n) {
		return 0;
	}
	if (arr[n-1] == element) {
		return n;
	}	
	FIND_ELEMENT(arr, n - 1, element);
}
template <typename T1, typename T2>
auto FIND_QUICK(T1 arr, T2 element, int left, int right) -> decltype(arr) {
	int index = (left + right) / 2;
	T2 middle = arr[index];

	if (left == index) {
		if (arr[left + 1] == element) {
			return arr + (left + 1);
		}
		else if(arr[left] == element){
			return arr + (left);
		}
		else {
			return NULL;
		}
	}
	if (middle == element) {
		return arr + index;
	}
	else if (middle > element) {
		FIND_QUICK(arr, element, left, index);
	}
	else {
		FIND_QUICK(arr, element, index, right);
	}



}