#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Заполняем массив
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Выводим массив в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}


//Задача 24.2. Изменение длинны динамического массива.
template <typename T>
void resize_arr(T*& arr, const int length, int newlength) {
	if (newlength <= 0)
		return;
	//увеличение длинны массива
	if (newlength > length) {
		T* tmp = new T[newlength]{};              //создаем массив из 0 нужной длинны
		for (int i = 0; i < length; i++)
			tmp[i] = arr[i];

		delete[] arr;
		arr = tmp;
	}
	//уменьшение длины массива
	if (newlength < length) {
		T* tmp = new T[newlength];               //создаем массив нужной длинны
		for (int i = 0; i < newlength; i++)
			tmp[i] = arr[i];

		delete[] arr;
		arr = tmp;
	}	
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	//Задача 24.1. Динамический массив C[n + m], который состоит из элементов массивов A и B
	/*
	int size1, size2;
	cout << "Ведите длину 1-го массива: ";
	cin >> size1;
	cout << "Ведите длину 2-го массива: ";
	cin >> size2;

	int* mass1 = new int[size1];
	int* mass2 = new int[size2];

	fill_arr(mass1, size1, 0, 10);
	cout << "Массив 1:\n";
	show_arr(mass1, size1);

	fill_arr(mass2, size2, 0, 9);
	cout << "\nМассив 2:\n";
	show_arr(mass2, size2);

	int* mass3 = new int[size1 + size2];

	for (int i = 0; i < size1; i++)
		mass3[i] = mass1[i];
	for (int i = size1; i < size1 + size2; i++)
		mass3[i] = mass2[i - size1];

	cout << "\nМассив 3 (из элементов 1-го и 2-го массивов):\n";
	show_arr(mass3, size1 + size2);
	delete[] mass1;
	delete[] mass2;

	cout << "\n\n";
	*/

	//Задача 24.2. Изменение длинны динамического массива.
	
	int size, newsize;
	cout << "Ведите длину динамического массива: ";
	cin >> size;
	int* mass = new int[size];
	fill_arr(mass, size, 0, 10);
	cout << "Изначальный массив:\n";
	show_arr(mass, size);

	cout << "Ведите новую длину динамического массива: ";
	cin >> newsize;

	resize_arr(mass, size, newsize);
	size = newsize;

	cout << "Итоговый динамический массив: ";
	show_arr(mass, size);
	
	cout << "\n\n";

	return 0;
}