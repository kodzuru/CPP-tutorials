#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include <stdlib.h>



#include <string>

using namespace std;


int** INIT_ARRAY(int N, int M) //инициализация массива
{
	int**arr = new int*[N]; //создание массива
	for (int i(0); i < N; i++) {
		arr[i] = new int[M];
	}
	for (int i(0); i < N; i++) {//заполнение массива
		for (int j(0); j < M; j++) {
			arr[i][j] = rand() % 10;
		}
	}
	return arr;
}
template <typename T1>
void MOVE_POS(T1** arr, int str, int pos, int M) {//смена позиций массива
	for (int i(0); i < pos%M; i++) {
		for (int j(0); j < M; j++) {
			swap(arr[str - 1][j], arr[str - 1][M - 1]);
		}
	}
}
template <typename T1>
void ARRAY_PRINT(T1** arr, int N, int M) {//вывод  массива в консоль
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





int main() {
	setlocale(0, "Russian");
	system("TITLE Неопознанный консольный объект");
	system("color 2");
	srand(time(NULL));
	
	
	int N = 5;
	int M = 5;	
	int** arr = INIT_ARRAY(N, M);
	ARRAY_PRINT(arr, N, M);
	int str = 1;
	int pos = 4;
	MOVE_POS(arr, str, pos, M);
	cout << endl << endl;
	ARRAY_PRINT(arr, N, M);
	
	_getch();
	return 0;
}