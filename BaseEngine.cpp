#include "BaseEngine.h";
#include <iostream>;
#include <conio.h>

using namespace std;

bool BaseEngine::Run() {
	char key = ' ';
	while (key != 'q')
	{
		while (!GetInput(&key)) {
		
		}
		cout << "Preset button is: " << key << endl;
	}
	cout << "Game ended!" << endl;
	return true;
}

bool BaseEngine::GetInput(char *c) {
	if (kbhit()) {
		*c = getchar();
		return true;
	}
	return false;	
}