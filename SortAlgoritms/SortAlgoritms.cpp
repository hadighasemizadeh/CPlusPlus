// SortAlgoritms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const int mSize = 1000;

// Selection sort algoritm
void SelectionSort(int arr[], int size) {
	int first, tmp;
	for (int i = size - 1; i > 0; --i) {
		first = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] > arr[first]) {
				first = j;
			}

			tmp = arr[first];
			arr[first] = arr[i];
			arr[i] = tmp;
		}
	}
}

// Insertion sort algoritm
void InsertionSort(int arr[], int size) {
	int j, tmp;
	for (int i = 0; i < size; ++i) {
		j = i;
		while (j>0 && arr[j-1] > arr[j]){
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			j--;
		}
	}
}

// Merge sort algoritm
void Merge(int arr[], int low, int middle,int high) {
	int tmp[mSize];
	for (int i = low; i <= high; ++i) {
		tmp[i] = arr[i];
	}

	int i = low;
	int j = middle + 1;
	int k = low;

	while (i <= middle && j <= high) {
		if (tmp[i] <= tmp[j]) {
			arr[k] = tmp[i];
			++i;
		} else {
			arr[k] = tmp[j];
			++j;
		}
		++k;
	}

	while (i <= middle) {
		arr[k] = tmp[i];
		++k;
		++i;
	}

}

// Merge sort algoritm
void MergeSort(int arr[], int low, int high) {
	if (low<high) {
		int middle = (low + high) / 2;
		MergeSort(arr, low, middle);
		MergeSort(arr, middle + 1, high);
		Merge(arr, low, middle, high);
	}
}

// Quick sort algoritm
void QuickSort(int arr[], int left, int right) {
	int i = left;
	int j = right;
	int pvt = arr[(i + j) / 2];

	int tmp;

	while (i<=j) {

		while (arr[i]<pvt) {
			i++;
		}

		while (arr[j]>pvt) {
			j--;
		}

		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
		}

		if (left < j)
			QuickSort(arr, left, j);

		if (i < right) 
			QuickSort(arr, i, right);		
	}
}

// Display my array size
void Display(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Greate N random number between 1 to 100
void GenerateRND(int arr[], int size) {

	// to have different random number at start
	srand(unsigned(time(0)));

	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100 + 1);
	}
}

// Time in miliseconds
double GetTime(time_t t1, time_t t2) {
	double ticks = t2 - t1;
	return (ticks * 10) / CLOCKS_PER_SEC;
}

int main(int argC, char **argV)
{
	int arr[mSize];

	// Generate 100 random number
	GenerateRND(arr, mSize);

	// Display array
	Display(arr, mSize);

	time_t beginTime = clock();
	// Sort with slection sort algoritm
	SelectionSort(arr, mSize);
	time_t endTime = clock();

	cout << " require time to sort: " << GetTime(beginTime, endTime)<<endl;


	//// Sort with insertion sort algoritm
	//InsertionSort(arr, mSize);

	//// Sort with merge sort algoritm
	//MergeSort(arr, 0, mSize -1);

	//// Sort with quick sort algoritm
	//QuickSort(arr, 0, mSize-1);

	// Display array
	Display(arr, mSize);

	// Wait for my order to quit
	getchar();
    return 0;
}