// Comparing and Accumulating.cpp : main project file.
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using namespace System;

int main()
{
	vector < int> a{ 1, 3, 5, 6, 99 };
	vector < int> b{ 1 ,4, 5, 6, 44 };

	// Check are two collections are equal or not
	int areEqual = equal(a.begin(), a.end(), b.begin(), b.end());
	cout << "Are they the same? " << areEqual << endl;

	// Find first miss match between two collection
	auto firstMissMatch = mismatch(a.begin(), a.end(), b.begin());
	int aMissMatch = *(firstMissMatch.first);
	int bMissMatch = *(firstMissMatch.second);

	cout << " element  " << aMissMatch << " was different from " << bMissMatch << endl;

	// Until what index they were matched
	int distance = firstMissMatch.first - a.begin();
	cout << "for how long they were matched -> " << distance << endl;

	// Calculate total of a collection
	int total = 0;

	total = accumulate(a.begin(), a.end(), 0);
	cout << "Accumulation is -> " << total << endl;

	total = accumulate(a.begin(), a.end(), 0, [](int total, int i) {if (i % 2 == 0)return total + i; return total; });
	cout << "Accumulation is -> " << total << endl;

	total = accumulate(a.begin(), a.end(), 1, [](int total, int i) {return total * i; });
	cout << "Accumulation is -> " << total << endl;

	vector<string> str{ "One", "Two", "Three" };
	auto allwords = accumulate(str.begin(), str.end(), string{});
	int length = allwords.size();
	cout << "allwords is -> " << allwords << endl;

	allwords = accumulate(str.begin(), str.end(), string{ "words:" }, [](const string& total, string& s) {return total + " " + s; });
	length = allwords.size();
	cout << "s is -> " << allwords << endl;

	string s = accumulate(a.begin(), a.end(), string{ "The numbers are :" }, [](const string& total, int i) {return total + " " + to_string(i); });
	cout << "www is -> " << s << endl;

	// Different types of loops
	for (auto it = a.begin(); it != a.end(); it++) {
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;

	for (auto& var : a)
	{
		var *= 2;
		cout << var << " ";
	}
	cout << endl;

	for_each(a.begin(), a.end(), [](int& elm) { elm = 2; cout << elm << " ";});
	cout << endl;

	return 0;
}
