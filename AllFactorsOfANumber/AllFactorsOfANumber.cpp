// AllFactorsOfANumber.cpp : main project file.

#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int n,NOF;

	cout << "Please enter the number that you want to see its factors: ";
	cin >> n;

	for(int i = 1; i <= sqrt(n); i++) {
	
		if (n%i == 0) {
			cout << i << ' ';
			NOF++;
			int quotient = n / i;
			if (i != quotient) {
				cout << quotient << ' ';
				NOF++;
			}
		}
	}

	cout << "\nIt has " << NOF<<" factors.";

	return 0;
}
