
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include "StringNumber.h"
#include "Timer.h"

using namespace String_Number;
using namespace std;

// Test of Sum of two string from start to end
void TEST_SUM_STRINGNUMBER(int start, int end) {

	size_t number_of_tests = pow((end - start), 2);

	cout << "The process of testing " << number_of_tests << "'Sum' tests started!\n";

	if (start >= end)
	{
		cout << "Error: starting point cannot be bigger than end point." << endl;
		return;
	}

	string sum("");
	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			sum = StringNumber(to_string(i)) + StringNumber(to_string(j));
			if (sum.compare(to_string(i + j)) != 0)
			{
				cout << "ERORR:" << i << "+" << "(" << j << ")" << "!=" << sum << endl;
				return;
			}
		}
	}
	cout << " All " << number_of_tests << " 'Sum' cases tested successfully.\n";
}
// Test of subtract of two string start to end
void TEST_SUBTRACT_STRINGNUMBER(int start, int end) {

	size_t number_of_tests = pow((end - start), 2);

	cout << "The process of testing " << number_of_tests << "'Subtraction' tests started!\n";

	if (start >= end)
	{
		cout << "Error: starting point cannot be bigger than end point." << endl;
		return;
	}

	string subtract("");
	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			subtract = StringNumber(to_string(i)) - StringNumber(to_string(j));
			if (subtract.compare(to_string(i - j)) != 0)
			{
				cout << "ERORR:" << i << "-" << "(" << j << ")" << "!=" << subtract << endl;
				return;
			}
		}
	}

	cout << " All " << number_of_tests << " 'Subtract' cases tested successfully.\n";
}
// Test of Multiplication of two string from start to end
void TEST_Multiply_STRINGNUMBER(int start, int end) {

	size_t number_of_tests = pow((end - start), 2);

	cout << "The process of testing " << number_of_tests << "'MultiplyIn' tests started!\n";

	if (start >= end)
	{
		cout << "Error: starting point cannot be bigger than end point." << endl;
		return;
	}

	string multiply;
	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			multiply = StringNumber(to_string(i)) * StringNumber( to_string(j));
			if (multiply.compare(to_string(i*j)) != 0)
			{
				cout << "ERORR:" << i << "*" << "(" << j << ")" << "!=" << multiply << endl;
				return;
			}
		}
	}

	cout << " All " << number_of_tests << " 'MultiplyIn' cases tested successfully.\n";
}
// Test of Division of two string from start to end
void TEST_Division_STRINGNUMBER(int start, int end) {

	size_t number_of_tests = pow((end - start), 2);

	cout << "The process of testing " << number_of_tests << "'Division' tests started!\n";

	if (start >= end)
	{
		cout << "Error: starting point cannot be bigger than end point." << endl;
		return;
	}

	string divide;
	for (int i = start; i <= end; i++)
	{
		for (int j = start; j <= end; j++)
		{
			divide = StringNumber(to_string(i)) / StringNumber(to_string(j));
			string res = to_string((i*1.0 / j*1.0));
			int min_size = std::min(divide.size(), res.substr(0, divide.size()).size());
			if (divide.compare(res.substr(0,min_size)) != 0)
			{
				cout << "ERORR:" << i << "/" << "(" << j << ")" << "!=" << divide << endl;
				return;
			}
		}
	}

	cout << " All " << number_of_tests << " 'MultiplyIn' cases tested successfully.\n";
}

int main()
{
	#pragma region TEST_STRINGNUMBER_CLASS
	//{
	//	Timer t;
	//	TEST_SUM_STRINGNUMBER(-1500, 1500);
	//}

	//// Test Sum String Number
	//TEST_SUBTRACT_STRINGNUMBER(-200, 200);

	//// Test MultiPlyIn String Number
	//TEST_Multiply_STRINGNUMBER(-200, 200);

	// //Test MultiPlyIn String Number
	//TEST_Division_STRINGNUMBER (1, 200);

	#pragma endregion

	{
		Timer t;
		StringNumber str{ "2" };
		str.SetPrecision(100000);

		cout << "Sun of digits of give number is:" << str.SumOfDigitsIn(str.Sqrt()) << endl;
	}

	//cout << "Please enter a button to exit!\n";
	//getchar();

	return 0;
}
