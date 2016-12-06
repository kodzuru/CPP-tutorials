
#include <iostream>
#include <fstream>
#include <conio.h>
#include <climits>
#include <random>
#include <time.h>
#include <stdlib.h>
//#include "model_list.h" //мой файлик с функциями
#include <string>

//#include "Book.h" //пример ООП
//#include "Stack1.h" //Стэк на массиве
//#include "Stack.h" // Стэк на списке
//#include "Queue1.h" // Очередь на массиве
//#include "Queue.h" // Очередь на двусвязанном списке
//#include "time.h" // пример с перегрузкой операций,операторов,дружественные функции
//#include "Vector.h" // вектор с перегрузкой операций, операторов, дружественные функции
//#include "Fraction.h" // рациональна дровь с перегрузкой операций, операторов, дружественные функции
//#include "Complex.h" //комплексные числе с перегрузкой операций, операторов, дружественные функции
#include "String.h" // строка + конструктор по умолчанию + конструктор + конструктор копирования 
int String::number_elem = 0;// инициализация статической переменной класса String
#include "inheritance.h" // пример НАСЛЕДОВАНИЯ + ПОЛИМОРФИЗМ
//#include "Figure.h" //пример НАСЛЕДОВАНИЯ класс фигура
//#include "inheritance_example.h" //пример НАСЛЕДОВАНИЯ private,public,protected наследования
//#include "polimorfism.h" //пример НАСЛЕДОВАНИЯ --- ПОЛИМОРФИЗМ virtual
//#include "virtual_destructors.h"//пример НАСЛЕДОВАНИЯ --- ПОЛИМОРФИЗМ virtual деструктор
//#include "abstract_class.h"
//#include "template_class.h" // пример шаблонного класса

using namespace std;
//using Programm::Account; для класса аккаунт

int main() {
	setlocale(0, "Russian");
	system("TITLE Неопознанный консольный объект");
	system("color 2");
	srand(time(NULL));
	//примеры работ
	{
		//тест emun
		/*
			enum Operation {
			plus = '+',
			minus = '-',
			mult = '*',
			del = '/',
			ostator = '%'
		};
		char x;
		cin >> x;

		switch (x) {
		case plus:
			cout << "плюс" << endl;
			break;
		case minus:
			cout << "minus" << endl;
			break;
		case mult:
			cout << "плюс" << endl;
			break;
		case del:
			cout << "del" << endl;
			break;
		case ostator:
			cout << "плюс" << endl;
			break;
		}

		/*
		List* begin = NULL;
		A a[5] = { 43,56,78,100,511 };
		A a1 = { 1 };
		A a2 = { -100 };
		A a3 = { 200 };
		A a4 = { 500 };
		A a5 = { 78 };
		A a6 = { 511 };
		Init(&begin, a);
		Print(begin);
		AddBegin(&begin, &a1);
		AddBegin(&begin, &a2);
		AddEnd(&begin, &a3);
		AddEnd(&begin, &a4);
		Insert(&begin, &a5);
		Print(begin);
		Delete(&begin, &a6);
		Print(begin);
		Free(&begin);
		Print(begin);
		*/
		//работа с файлами
		/*
			ifstream fin;
		fin.open("file.txt");

		if (!fin.is_open())
		{
			cout << "blabla" << endl;
			return -1;
		}

		int a[111];
		for (int i(0); i < 8; i++) {
			fin >> a[i];
			cout << a[i];
		}


		*/
		//смещение значений в массиве
		/*
		int N = 5;
		int M = 5;
		int** arr = INIT_ARRAY(N, M);
		ARRAY_PRINT(arr, N, M);
		int str = 1;
		int pos = 4;
		MOVE_POS(arr, str, pos, M);
		cout << endl << endl;
		ARRAY_PRINT(arr, N, M);
		*/
		//перегрузка функций и шаблоны
		/*
		int a = 10; int b = 20;
		cout << SUM(10, 20) << endl;
		cout << SUM(10.5, 10) << endl;

		cout << a << " " << b << endl;
		SWAP(a, b);
		cout << a << " " << b << endl;

		int N = 10;
		double *A = new double[N];
		for (int i(0); i < N; i++) {
			A[i] = rand()%10;
		}
		SORT(A, N);
		for (int i(0); i < N; i++) {
			cout << A[i] << " | ";
		}
		cout << endl;
		cout << mean(A, N);
		cout << endl;
		double x = 4;

		if (FIND(A, N, x)) {
			cout << "Позиция символа " << x << " в массиве " << *FIND(A, N, x)+1 << endl;
		}
		else {
			cout << "элемент не найден" << endl;
		}

		delete[] A;
		*/
		//рекурсия
		/*
		int level = 6;
		Rec(level);

		char str[66];
		str[65] = '\0';
		int min = 0, max = 64;
		str[min] = str[max] = '|';

		for (int i(1); i < 64; i++) {
			str[i] = ' ';
		}
		cout << str << endl;
		for (int i(1); i <= level; i++) {
			PRINT(str, min, max, i);
			cout << str << endl;

			for (int i(1); i < 64; i++) {
				str[i] = ' ';
			}
		}
		cout << endl << endl << endl;

		int n = 1000000;
		int *arr = new int[n];
		for (int i(0); i < n; i++) {
			arr[i] = rand();
		}

		double t1 = clock();
		QUICK_SORT(arr, 0, n-1);
		double t2 = clock() - t1;
		cout << t2/CLOCKS_PER_SEC << endl;


		double t3 = clock();
		SORT(arr, n);
		double t4 = clock() - t3;
		cout << t4 / CLOCKS_PER_SEC << endl;
		delete[] arr;
		*/
		//рекурсия
		/*
		//int a = 0;
		//cout << FACT(a);

		int n = 20;
		int *arr = new int[n];
		for (int i(0); i < n; i++) {
			arr[i] = rand()%10;
		}
		QUICK_SORT(arr, 0, n-1);
		for (int i(0); i < n; i++) {
			cout << arr[i] << "  ";
		}
		cout << endl;
		int b = 3;
		//auto p = FIND_QUICK(arr, b, 0, n);
		//cout << *p << endl;
		if (FIND_QUICK(arr, b, 0, n)) {
			cout << "Элемент найден!" << endl;
		}
		else {
			cout << "Элемент НЕ найден!";
		}

		if (FIND_ELEMENT(arr, n, b)) {
			cout << "Элемент найден в позиции: " << *FIND_ELEMENT(arr, n, b) << endl;
			cout << "Сам элемент равен: " << arr[*FIND_ELEMENT(arr, n, b)] << endl;
		}
		else {
			cout << "Элемент НЕ найден";
		}
		*/
		// ООП класс аккаунт
		/*
		Account a("asdasd","A", 500);
		Account b("asdasd", "B", 400);
		Account c();

		a.setBalance(123);
		a.setID("№43215");
		a.setName("Валера");

		cout << "Номер счёта: " << a.getID() << endl;
		cout << "Имя владельца счёта: " << a.getName() << endl;
		cout << "Баланс на счету: " << a.getBalance() << endl;

		if (a.addBalance(10000)) {
			cout << "успешно пополнили баланс" << endl;
		}
		else {
			cout << "НЕудачно пополнили баланс" << endl;
		}

		if (a.takeMoney(10000)) {
			cout << "успешно cнятие бабла" << endl;
		}
		else {
			cout << "НЕудачное cнятие бабла" << endl;
		}


		cout << a.getBalance() << endl;
		cout << b.getBalance() << endl;

		cout << (a.MAX(b)).getBalance() << endl;
		*/
		// ООП класс книга
		/*
		Book book1("Мёртвые души","Гоголь",10);
		Book book2("Война и мир", "Толстой", 15);
		book1.Print(cout);
		book2.Print(cout);
		(book1.whatPopular(book2)).Print(cout);
		*/
		// ООП класс СТЭК1 первый пришёл последний ушёл на динамическом массиве
		/*
		Stack1 st(5);
		for (int i(0); !st.Is_full(); i++) {
			st.Push(i);
		}
		for (int i(0); !st.Is_empty(); i++) {
			cout << st.Pop() << endl;
		}
		*/
		// ООП класс СТЭК первый пришёл последний ушёл на на односвязанном списке
		/*
		Stack st;
		A1 a;
		int b = 5;
		for (int i(0); i < b; i++) {
			a.key = i;
			st.push(a);
			cout << i << " ";
		}
		cout << endl;
		for (int i(0); i < b; i++) {
			cout << st.pop() << " ";
		}
		cout << endl;
		*/
		// ООП класс ОЧЕРЕДЬ1 первый пришёл первый ушёл на динамическом массиве
		/*
		Queue1 q1(25);
		for (int i(0); !q1.Is_full(); i++) {
			q1.push(i);
			cout << i << " ";
		}
		cout << endl;
		for (int i(0); !q1.Is_empty(); i++) {
			cout << q1.pop() << " ";
		}
		cout << endl;
		*/
		// ООП класс ОЧЕРЕДЬ первый пришёл первый ушёл на ДВУСВЯЗАННОМ списке
		/*
		Queue q;
		A2 a;
		int b = 5;
		for (int i(0); i < b; i++) {
			a.key = i;
			q.push(a);
			cout << i << " ";
		}
		cout << endl;
		for (int i(0); i < b; i++) {
			cout << q.pop() << " ";
		}
		cout << endl;
		*/
		// ООП класс время + пергрузка операций + перегрузка операторов + дружественные функции
		/*
		time t1(4500);
		time t2(2, 35, 21);
		time t3;
		t3 = t1 + t2;
		t3 << cout; // time.cpp line(39)
		cout << t3 << "asdfasdf";		
		*/
		// ООП класс вектор + пергрузка операций + перегрузка операторов + дружественные функции
		/*
		Vector v1(30, 50, Decart);
		Vector v2(6.56, 1.34, Polar);
		cout << v1 + v2 << endl;
		*/
		// ООП класс рациональная дробь + пергрузка операций + перегрузка операторов + дружественные функции
		/*
		Fraction f1(20, 30);
		Fraction f2(80, 50);
		Fraction f3;
		f3 = f1 + f2;
		cout << f3;
		f3 = f1 - f2;
		cout << f3;
		f3 = f1 * f2;
		cout << f3;
		f3 = f1 / f2;
		cout << f3;
		*/
		// ООП класс комплексные числа + пергрузка операций + перегрузка операторов + дружественные функции
		/*
		Complex c1(50, 10);
		Complex c2(50, 15);

		cout << c1 + c2;
		cout << c1 - c2;
		cout << c1 * c2;
		cout << c1 / c2;
		cout << c1.Module() << "   " << c2.Module();
		*/
		// ООП класс строка конструктор по умолчанию + конструктор + конструктор копирования + явное преобразования + static + explicit
		/*
		String s("MD");//0x1
		{
			String s1(s); //0x2
			s = s1 = "asdfasdf"; //0x3
		}
		//delete 0x2 при выходе из скобок
		//delete 0x3 при завершении программы
		// 0x1 НЕ УДАЛЯЕТСЯ (String.cpp line 43)
		String s("MD");
		String s1("asdasd");
		//s = s1 = "asdfasdf";
		char* s3 = s; // оператор явного преобразования типов
		cout <<  s3 << endl;
		*/
		// НАСЛЕДОВАНИЕ
		/*
		ExtraAccount ex("123123", "Валера", 17000);
		cout << ex << endl;
		ex.takeMoney(10000);
		cout << ex << endl;

		ex.takeMoney(10000);
		cout << ex << endl;
		ex.takeMoneyExtra(10000);
		cout << ex << endl;
		ex.addMoney(3460);
		cout << ex << endl;
		*/
		// НАСЛЕДОВАНИЕ пример класса фигура открытое наследование
		/*
		Figure f;
		cin >> f;
		Circle c1(f);
		cout << c1.Area();
		*/
		//НАСЛЕДОВАНИЕ примеры private,public,protected наследования
		/*
		B b;
		b.whowB();
		A a;
		C c;
		c.whowС();
		*/
		//НАСЛЕДОВАНИЕ ------ ПОЛИМОРФИЗМ - перегрузка методов
		/*		
		A a;
		B b;
		//в зависимости на какой объект ссылается указатель, такой объект и будет вызываться виртуальной функцией
		// в нашем случае указывает на класс B => вызываем метод класса B | указывает на класс А => вызываем метод класса А

		//A *pa = NULL; //указатель на базовый класс может ссылкться на объект производного класса
		//pa = &b; //передаём адресс на производный класс
		//pa->show(); // вызываем метод для производно класса result B

		A *pa = new A[2]; // создаём массив
		pa = &b; // в первый элемент присвиваем адрес на объект класса Б
		pa->show(); // B
		pa++; 
		pa = &a; // во второй элемент присвиваем адрес на объект класса А
		pa->show(); // А
		*/
		//НАСЛЕДОВАНИЕ ------ ПОЛИМОРФИЗМ - перегрузка методов класса Account
		/*
		Account a("321321", "Вася", 25000);
		ExtraAccount ex("123123", "Валера", 17000);
		Account* pex = new Account;

		pex = &ex;
		cout << pex << endl;
		pex->takeMoney(10000);
		cout << *pex << endl;

		pex->takeMoney(10000);
		cout << *pex << endl;
		pex->takeMoney(10000);
		cout << *pex << endl;
		pex->addBalance(3460);
		cout << *pex << endl;


		Account a("321321", "Вася", 1000);
		ExtraAccount ex("123123", "Валера", 1000);
		Account** pex = new Account*[2];

		pex[0] = &a;
		pex[1] = &ex;

		pex[0]->takeMoney(5000);
		pex[1]->takeMoney(5000);

		cout << a << endl;
		cout << ex << endl;


		*/
		//НАСЛЕДОВАНИЕ ------ ПОЛИМОРФИЗМ - виртуальный деструктор
		/*
		//B*b = new B;
		A* b = new B; // полиморфизм - деструктор класса B не вызывается

		delete b; // delete для класса всегда вызывает деструкторы
		*/
		// ШАБЛОННЫЕ КЛАССЫ -------- + разбиение класса на 2а файла
		/*
		Array<int> a(3);

		a.push(2);
		a.push(10);
		a.push(15);

		cout << a[0] << endl;
		cout << a[1] << endl;
		cout << a[2] << endl;
		*/
	}

	
	
	
	_getch();
	return 0;
}



