// ArmstrongNumber.cpp : main project file.

#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int nDigit(int x);
bool isArmstrongNumber(int x);

int main()
{
	cout << "Display all Armstrong Numbers 1 to 1000000" << endl;
	for (size_t i = 1; i <= 1000000; i++)
	{
		if (isArmstrongNumber(i)) {
			cout << i << ' ';
		}
	}

	fgetchar();
    return 0;
}

// Number of x digits
int nDigit(int x) {

	int count = 0;

	while (x != 0) {
		x /= 10;
		count++;
	}

	return count;
}

bool isArmstrongNumber(int x) {
	int sum = 0;
	int count = nDigit(x);
	int temp = x;

	while (x>0) {
		int rem = x % 10;
		x /= 10;
		sum += pow(rem, count);
	}

	return sum == temp;
}
