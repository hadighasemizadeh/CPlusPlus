// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

class Timer {
private:
	chrono::time_point<chrono::high_resolution_clock> _start_time;

public:
	Timer() {
		_start_time = chrono::high_resolution_clock::now();
	}

	~Timer() {
		Stop();
	}

	void Stop() 
	{
		auto end_time = chrono::high_resolution_clock::now();

		auto start = chrono::time_point_cast<chrono::microseconds>(_start_time).time_since_epoch().count();
		auto stop = chrono::time_point_cast<chrono::microseconds>(end_time).time_since_epoch().count();

		auto us_duration = stop - start;
		auto ms_duration = us_duration * 0.001;

		cout << " "<< us_duration << " us" << " (" << ms_duration << ") ms.\n";
	}
};

int main()
{
	{
		Timer t;

		string s1 = "this is just a string";
		string s2(s1.size()+1, '.');
		transform(s1.begin(), s1.end(), s2.begin(), ::toupper);
		cout << s2;
	}
}
