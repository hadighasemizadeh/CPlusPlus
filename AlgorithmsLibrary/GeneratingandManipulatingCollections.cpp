// GeneratingandManipulatingCollections.cpp : main project file.

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
using namespace System;
void PrintOrdredItems(vector<int>&, int);
int main()
{
	vector <int> source{ 3, 6, -11, 12, 22, 4 };

	// Hard way to copy
	vector <int> vec0(source.size());
	copy(source.begin(), source.end(), vec0.begin());
	PrintOrdredItems(vec0, vec0.size());

	// Best way to copy
	auto vec1 = source;
	PrintOrdredItems(vec1, vec1.size());

	// Copy until reach to position
	vector <int> vec2(source.size());
	auto pos = find(source.begin(), source.end(), -11);
	copy(source.begin(), pos, vec2.begin());
	PrintOrdredItems(vec2, vec2.size());

	// Copy if condition is true
	vector <int> vec3(source.size());
	copy_if(source.begin(), source.end(), vec3.begin(), [](int element) {return element % 2 == 0; });
	PrintOrdredItems(vec3, vec3.size());

	// Copy only n element
	vector <int> vec4(source.size());
	copy_n(source.begin(), 4, vec4.begin());
	PrintOrdredItems(vec4, vec4.size());

	// in collection Copy
	copy(source.begin(), pos + 1, pos + 1);
	PrintOrdredItems(source, source.size());

	// Copy a collection to another from the end
	copy_backward(vec4.begin(), vec4.end(), source.end());
	PrintOrdredItems(source, source.size());

	// Shift collection one unit to right
	copy_backward(source.begin(), source.end() - 1, source.end());
	PrintOrdredItems(source, source.size());

	// Remove item from collection and at the end we actually shrink the collection size
	auto newEnd = remove(vec0.begin(), vec0.end(), 12);
	PrintOrdredItems(vec0, vec0.size());
	int newSize = vec0.size();
	cout << newSize << endl;
	vec0.erase(newEnd, vec0.end());
	PrintOrdredItems(vec0, vec0.size());

	vector<int> vec5(10);
	// Fill all collection with 1
	fill(vec5.begin(), vec5.end(), 1);
	PrintOrdredItems(vec5, vec5.size());

	// Fill n element of collection with x
	fill_n(vec5.begin(), 6, 5);
	PrintOrdredItems(vec5, vec5.size());

	// Fill collection with ordered number with first number x
	iota(vec5.begin(), vec5.end(), 1);
	PrintOrdredItems(vec5, vec5.size());

	int index = 10;
	generate(vec5.begin(), vec5.end(), [&index]() {return index--; });
	PrintOrdredItems(vec5, vec5.size());

	index = 1;
	generate_n(vec5.begin(), 6, [&index]() {return index *= 2; });
	PrintOrdredItems(vec5, vec5.size());

	// Repalce an element of the collection with another
	replace(vec5.begin(), vec5.end(), 2, 222);
	PrintOrdredItems(vec5, vec5.size());

	// Repalce an element of the collection with condition with another
	replace_if(vec5.begin(), vec5.end(), [](int element) {return element % 2 == 0; }, -1);
	PrintOrdredItems(vec5, vec5.size());

	// Transform
	transform(vec5.begin(), vec5.end(), vec5.begin(), [](int element) {return element *= 2; });
	PrintOrdredItems(vec5, vec5.size());

	vector<int> vec6(10);
	transform(vec5.begin(), vec5.end()-1, vec5.begin(), vec6.begin(),[](int element1, int element2) {return element1 - element2; });
	PrintOrdredItems(vec6, vec6.size());

	// Sum elements of two collection and put it in third collection
	iota(vec5.begin(), vec5.end(), 2);
	iota(vec6.begin(), vec6.end(), 1);
	vector<int> vec7(10);
	transform(vec5.begin(), vec5.end(), vec6.begin(), vec7.begin(), [](int element1, int element2) {return element1 + element2; });
	PrintOrdredItems(vec7, vec7.size());
	
	vector<int> vec8 = { 2,2,3,4,5,2,3,4 };
	// Delete repeated elelement
	unique(vec8.begin(), vec8.end());
	PrintOrdredItems(vec8, vec8.size());


	vec8.erase(unique(vec8.begin(), vec8.end()), vec8.end());
	PrintOrdredItems(vec8, vec8.size());

	string str001 = "Hello world!";

	// Reverse a collection
	reverse(str001.begin(), str001.end());
	cout << str001 << endl;

	// Swap two elements
	iter_swap(str001.begin(), str001.end()-1);
	cout << str001 << endl;

	string org = "            ";
	reverse_copy(str001.begin(), str001.end(), org.begin());
	cout << org << endl;

	return 0;
}

void PrintOrdredItems(vector<int>& s, int size) {
	for (vector<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
