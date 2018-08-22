// IsPrime.cpp : main project file.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int x);

int main()
{
	int x;

	cout << "Enter a number to be check wether it is prime or not: ";
	cin >> x;

	string result = (isPrime(x) == 0) ? "No" : "Yes";
	cout << "It is prime? " << result;

	return 0;
}

bool isPrime(int x) {

	for (int i = 2; i <= sqrt(x); i++) {

		if (x%i == 0) {
			return false;
		}
	}

	return true;
}