// DeepCopy.cpp : main project file.

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

int* CopyArray(int *arr, int n);
int* GetArray(int n);
void PrintArray(int *arr, int n);

int main()
{
	int n;
	cout << "How many random number you want to have in the array? ";
	cin >> n;

	int* arr = GetArray(n);
	PrintArray(arr, n);
	int* arrCpy = CopyArray(arr, n);
	delete[] arr;

	cout << endl << string(15, '*') << endl;

	PrintArray(arrCpy, n);
	delete[] arrCpy;

	getchar();
	getchar();
	return 0;
}

int* GetArray(int n) {
	int *newArr = new int[n];
	srand(time(NULL));

	for (size_t i = 0; i < n; i++)
	{
		*(newArr + i) = rand() % 100;
	}
	return newArr;
}

int* CopyArray(int *arr, int n) {
	int *newArr = new int[n];
	srand(time(NULL));

	for (size_t i = 0; i < n; i++)
	{
		*(newArr + i) = rand()%100;
	}
	return newArr;
}

void PrintArray(int *arr, int n) {

	for (size_t i = 0; i < n; i++)
	{
		cout << *(arr + i) << ' ';
	}
}
