// LowercaseUppercase.cpp : main project file.
#include <iostream>
#include <string>

using namespace std;
using namespace System;

int main()
{
	cout << "Please insert you fullname: " << endl;
	string fullname;
	getline(cin, fullname);

	for (size_t i = 0; i < fullname.length(); i++)
	{
		if (fullname[i] >= 'a' && fullname[i] <= 'z') {
			fullname[i] -= 32;
		}
	}

	cout << "\nNew fullname is: " << fullname;

	// Using range loop
	for (char &p: fullname)
	{
		if (p >= 'A' && p <= 'Z') {
			p += 32;
		}
	}

	cout << "\nNew fullname is: " << fullname;
	getchar();
    return 0;
}
