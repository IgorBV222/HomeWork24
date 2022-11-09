#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//��������� ������
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//������� ������ � �������
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}


//������ 24.2. ��������� ������ ������������� �������.
template <typename T>
void resize_arr(T*& arr, const int length, int newlength) {
	if (newlength <= 0)
		return;
	//���������� ������ �������
	if (newlength > length) {
		T* tmp = new T[newlength]{};              //������� ������ �� 0 ������ ������
		for (int i = 0; i < length; i++)
			tmp[i] = arr[i];

		delete[] arr;
		arr = tmp;
	}
	//���������� ����� �������
	if (newlength < length) {
		T* tmp = new T[newlength];               //������� ������ ������ ������
		for (int i = 0; i < newlength; i++)
			tmp[i] = arr[i];

		delete[] arr;
		arr = tmp;
	}	
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	//������ 24.1. ������������ ������ C[n + m], ������� ������� �� ��������� �������� A � B
	/*
	int size1, size2;
	cout << "������ ����� 1-�� �������: ";
	cin >> size1;
	cout << "������ ����� 2-�� �������: ";
	cin >> size2;

	int* mass1 = new int[size1];
	int* mass2 = new int[size2];

	fill_arr(mass1, size1, 0, 10);
	cout << "������ 1:\n";
	show_arr(mass1, size1);

	fill_arr(mass2, size2, 0, 9);
	cout << "\n������ 2:\n";
	show_arr(mass2, size2);

	int* mass3 = new int[size1 + size2];

	for (int i = 0; i < size1; i++)
		mass3[i] = mass1[i];
	for (int i = size1; i < size1 + size2; i++)
		mass3[i] = mass2[i - size1];

	cout << "\n������ 3 (�� ��������� 1-�� � 2-�� ��������):\n";
	show_arr(mass3, size1 + size2);
	delete[] mass1;
	delete[] mass2;

	cout << "\n\n";
	*/

	//������ 24.2. ��������� ������ ������������� �������.
	
	int size, newsize;
	cout << "������ ����� ������������� �������: ";
	cin >> size;
	int* mass = new int[size];
	fill_arr(mass, size, 0, 10);
	cout << "����������� ������:\n";
	show_arr(mass, size);

	cout << "������ ����� ����� ������������� �������: ";
	cin >> newsize;

	resize_arr(mass, size, newsize);
	size = newsize;

	cout << "�������� ������������ ������: ";
	show_arr(mass, size);
	
	cout << "\n\n";

	return 0;
}