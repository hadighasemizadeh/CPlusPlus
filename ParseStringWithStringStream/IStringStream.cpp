#include <iostream>
#include<string>
#include <sstream>

using namespace std;

int main()
{
	string str = "Hadi:22,Saeed:88,Navid:55";
	stringstream ss1(str);
	string extract1;

	while (getline(ss1,extract1,','))
	{
		stringstream ss2 (extract1);
		string extract2;

		while (getline(ss2,extract2, ':')) {
			cout << extract2 << endl;
		}
	}

	return 0;
}
