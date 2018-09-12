#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace System;

double Average(string lineOfNumbers);
char GradeLabel(double average);

int main()
{
	ifstream file;
	ofstream ofile;
	file.open("file.txt");
	ofile.open("outfile.txt");

	if (file.fail()) {

		cout << "Loading the file failed." << endl;
		exit(1);
	}

	if (ofile.fail()) {
		cout << "Loading the out put file failed." << endl;
		exit(1);
	}
	string line;

	ofile << left << setw(15) << "Name" << setw(15) << "Average" << setw(15) << "Grade" << endl;
	cout << left << setw(15) << "Name" << setw(15) << "Average" << setw(15) << "Grade" << endl;

	ofile << string(40, '-') << endl;
	cout << string(40, '-') << endl;

	while (!file.eof())
	{
		getline(file, line);
		istringstream iss(line);
		string name;
		string res;
		getline(iss, name, ':');

		getline(iss, res, ':');
		double avg = Average(res);
		ofile << left << setw(15) << name << setw(15) << avg << setw(15) << GradeLabel(avg) << endl;
		cout << left << setw(15) << name << setw(15) << avg << setw(15) << GradeLabel(avg) << endl;

	}

	file.close();
	ofile.close();

	getchar();
	return 0;
}

double Average(string lineOfNumbers) {
	istringstream iss2(lineOfNumbers);
	string eRes;
	int total = 0;
	size_t count = 0;
	while (!iss2.eof()) {
		getline(iss2, eRes, ',');
		total +=  atoi(eRes.c_str());
		count++;
	}

	return (double)total / count;
}

char GradeLabel(double average) {

	if (average > 19)
		return 'A';
	else if (average>17 && average <= 19)
		return 'B';
	else if (average>14 && average <= 17)
		return 'C';
	else if (average>=10 && average <= 14)
		return 'D';	
	else if (average < 10)
		return 'E';
}