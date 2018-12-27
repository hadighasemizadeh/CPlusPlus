// Sorting.cpp : main project file.

#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <iostream>
#include <iterator>
#include <sstream>
using namespace std;
using namespace System;

void PrintOrdredItems(vector<int>&, int);

class Employee {
private:
	string firstName;
	string lastName;
	int salary;

public:
	Employee(string fName, string lName, int sal) :firstName(fName), lastName(lName), salary(sal) {}
	string getFullName() const{ return firstName + ' ' + lastName; }
	int getSalary() const { return salary; }
};

ostream& operator<< (ostream& sout, const Employee& e) {
	sout << e.getFullName() << " salary is " << e.getSalary();
	return sout;
}

void PrintOrdredEmployee(vector<Employee>&, int);

int main()
{
	vector<int> vec{-1, 5, 55, 11, -22, 7, 4, 32, -41,2};

	// create a copy of the vector to keep original one
	vector<int> vec01 = vec;

	// Find Max & Min
	int max = *(max_element(vec01.begin(), vec01.end()));
	int min = *(min_element(vec01.begin(), vec01.end()));
	cout << " Max is " << max << " and Min is " << min << endl;

	// Without sorting
	PrintOrdredItems(vec, vec.size());

	// Ascending sort
	sort(vec01.begin(), vec01.end());
	PrintOrdredItems(vec01, vec01.size());
	
	// Get max & min after sorting
	min = *(vec01.begin());
	max = *(vec01.end() - 1);
	cout << " Max is " << max << " and Min is " << min << endl;

	// Shuffle a collection
	random_device rndDevice;
	mt19937 generator(rndDevice());
	shuffle(vec01.begin(), vec01.end(), generator);
	cout << "Shuffled > ";
	PrintOrdredItems(vec01, vec01.size());

	// Get a collection and sort it ascending until the first occurance of 7
	partial_sort(vec01.begin(), find(vec01.begin(), vec01.end(), 7), vec01.end());
	cout << "Sort until first occurance of 7 > ";
	PrintOrdredItems(vec01, vec01.size());

	// Partial sort copy of a collection
	vector<int> v02(4);
	partial_sort_copy(vec01.begin(), vec01.end(), v02.begin(), v02.end());
	cout << "Display partially copied vector> ";
	PrintOrdredItems(v02, v02.size());

	// Find the first bigger than x in collection
	int firstBiggerthan = *upper_bound(vec01.begin(), vec01.end(), 0);
	int firstLessthan = *lower_bound(vec01.begin(), vec01.end(), 0);
	cout << " First bigger than 0 is " << firstBiggerthan << " and first less than 0 " << firstLessthan << endl;

	// Find nth element in a collection if you sort the collection completely (it does not sort whole collection)
	nth_element(vec01.begin(), vec01.begin() + 5, vec01.end());
	int element = *(vec01.begin() + 5);
	cout << "nth element will be " << element <<endl;


	// Descending sort
	sort(vec01.begin(), vec01.end(), [](int element1, int element2) {return element1 > element2; });
	PrintOrdredItems(vec01, vec01.size());

	// Descending sort based on absolute value
	sort(vec01.begin(), vec01.end(), [](int element1, int element2) {return abs(element1) > abs(element2); });
	PrintOrdredItems(vec01, vec01.size());

	// Ascending sort based on absolute value
	sort(vec01.begin(), vec01.end(), [](int element1, int element2) {return abs(element1) < abs(element2); });
	PrintOrdredItems(vec01, vec01.size());

	vector <Employee> staff{
		{ "Hadi", "Ghasemi Zadeh",2000 },
		{ "Jose", "Dias",2000 },
		{ "Nuno", "Soares",1900 },
		{ "Rui", "Martins",1900 },
		{ "Miguel", "Antunes",1500 },
		{ "Paulo", "Matiu",1800 },
	};

	// Sort Employees based on their salary - Descending
	sort(staff.begin(), staff.end(), [](Employee e1, Employee e2) {return e1.getSalary() > e2.getSalary(); });
	PrintOrdredEmployee(staff, staff.size());

	// Sort Employees based on their salary - Ascending
	sort(staff.begin(), staff.end(), [](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
	PrintOrdredEmployee(staff, staff.size());

	// Sort Employees based on their salary - Descending alphabetically
	sort(staff.begin(), staff.end(), [](Employee e1, Employee e2) {return e1.getFullName() < e2.getFullName(); });
	PrintOrdredEmployee(staff, staff.size());

	// Check if the collection is sorted(based on opted lambda) or not
	bool isSorted = is_sorted(vec01.begin(), vec01.end(), [](int element1, int element2) {return element1 > element2; });
	cout << "The collect sort stat is " << isSorted << endl;

	// Sort Employees based on their salary - Ascending salay and alphabetical order
	stable_sort(staff.begin(), staff.end(), [](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
	PrintOrdredEmployee(staff, staff.size());

    return 0;
}
void PrintOrdredItems(vector<int>& s, int size) {
	for (vector<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

void PrintOrdredEmployee(vector<Employee>& s, int size) {
	for (vector<Employee>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
}
