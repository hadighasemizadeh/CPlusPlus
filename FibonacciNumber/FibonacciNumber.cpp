// FibonacciNumber.cpp : main project file.

#include <iostream>

using namespace std;

int FibonacciRecursive(int n);
void FibonacciSimple(int n);

int main()
{
	int n;
	cout << "How many fibonacci number you want to produce? ";
	cin >> n;

	// Calculate it recursively
	cout << FibonacciRecursive(n);

	//// Calculate it with a simple loop
	//FibonacciSimple( n);

	return 0;
}

// Calculate it with a simple loop
void FibonacciSimple(int n) {

	for (int i = 0, t1 = -1, t2 = 1, sum = 0; i <= n; i++) {
		sum = t1 + t2;
		cout << sum << endl;
		t1 = t2;
		t2 = sum;
	}
}

// Calculate it recursively
int FibonacciRecursive(int n) {

	if (n == 0) {
		return 0;
	}if (n == 1) {
		return 1;
	}else{
		return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
	}
}
