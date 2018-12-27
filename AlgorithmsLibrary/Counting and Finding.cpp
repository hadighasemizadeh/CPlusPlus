// Counting and Finding.cpp : main project file.
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
using namespace System;

int main()
{
	vector<int> vec = {1, 6, 6, 2, -3, 4, 5, 3, 2, 6, -2, 6, -2};
	int const target = 2;

	// Counting number of x in a collection
	int cnt01 = count(vec.begin(), vec.end(), target);
	cout << " number of 2 in a collection is " << cnt01 << endl;

	// How many odd number are in our vector
	int cntOdd = count_if(vec.begin(), vec.end(), [](auto element) {return element % 2 != 0; });
	cout << " number of odd numbers in a collection is: " << cntOdd << endl;

	// All, None, Some of items in vec are x -> I use all_of, none_of, any_of to find it
	bool allof, nonof, anyof;
	allof = (cntOdd == vec.size());
	nonof = (cntOdd == 0);
	anyof = (cntOdd > 0);
	cout << "allof " << allof << " nonof " <<nonof << " anyof " <<anyof << endl;

	// All, None, Some of items in vec are x -> I use count_if to find it
	allof = all_of (vec.begin(), vec.end(), [](auto element) {return element % 2 == 0; });
	nonof = none_of(vec.begin(), vec.end(), [](auto element) {return element % 2 == 0; });
	anyof = any_of (vec.begin(), vec.end(), [](auto element) {return element % 2 == 0; });
	cout << "allof " << allof << " nonof " << nonof << " anyof " << anyof << endl;

	// Count number of months with the length of 31 ith count_if
	map<int, int> monthLength{{ 1,31 },{ 2,28 },{ 3,31 },{ 4,30 },{ 5,31 },{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 }};
	int cntMounths = count_if(monthLength.begin(), monthLength.end(), [](auto element) { return element.second == 31;});
	cout << " Number of months with 31 days in a year!! " << cntMounths << endl;
	
	// Find an element in a collection
	auto res001 = find(vec.begin(), vec.end(), 6);
	res001 != vec.end() ? cout << "Element found " << *res001 << endl : cout << "Element not found! " << endl;
	
	// Find an element in a collection not from another find method
	auto res002 = find(res001, vec.end(), 6);
	res002 != vec.end() ? cout << "Element found " << *res002 << endl : cout << "Element not found! " << endl;

	// Find first occurance if the condition is true
	auto res003 = find_if(vec.begin(), vec.end(), [](auto element) {return element % 2 == 0; });
	res003 != vec.end() ? cout << "Element found " << *res003 << endl : cout << "Element not found! " << endl;

	// Find first occurance if the condition is wrong
	auto res004 = find_if_not(vec.begin(), vec.end(), [](auto element) {return element % 2 == 0; });
	res004 != vec.end() ? cout << "Element found " << *res004 << endl : cout << "Element not found! " << endl;

	// Find first occurance of an element from one collection in another collection
	vector<int> primeNumbers = {1,2,3,5,7,11,13,17};
	auto fInCollection001 = find_first_of(vec.begin(), vec.end(), primeNumbers.begin(), primeNumbers.end());
	fInCollection001 != vec.end() ? cout << "In collection found a prime number-> " << *fInCollection001 << endl : cout << "No prime was found! " << endl;

	// Search to find a sequence in a collection and display first element of the sequence
	vector<int> sequence = {6, -2 };
	auto fInCollection02 = search(vec.begin(), vec.end(), sequence.begin(), sequence.end());
	fInCollection02 != vec.end() ? cout << "In collection found asked sequence of -> " << *fInCollection02 << endl : cout << "Asked sequence was not found! " << endl;

	//  Search to find the last occurance of a sequence in a collection and display first element of the sequence
	auto fInCollection03 = find_end(vec.begin(), vec.end(), sequence.begin(), sequence.end());
	fInCollection03 != vec.end() ? cout << "Last occurance in collection found asked sequence of -> " << *fInCollection03 << endl : cout << "Asked sequence was not found! " << endl;

	// Search to find item x which repeated n time consequitively and display first item
	auto fNTimesRepeated01 = search_n(vec.begin(), vec.end(), 2, 6);
	fNTimesRepeated01 != vec.end() ? cout << "first time that the number repeated n times is -> " << *fNTimesRepeated01 << endl : cout << "repeated number was not found! " << endl;

	// Find a charactere from a string
	string str001 = "I am here and waiting for you!";
	auto resStr = find(str001.begin(), str001.end(), 'a');
	resStr != str001.end() ? cout << "Character found. " << *resStr << endl : cout << "Character not found! " << endl;

	return 0;
}
