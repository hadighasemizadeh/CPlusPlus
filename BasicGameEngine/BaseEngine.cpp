#include "BaseEngine.h";
#include <iostream>;
#include <conio.h>
#include <Windows.h>
// For getting 30 fps
#define GAME_SPEED 33.3334
using namespace std;

bool BaseEngine::Run() {
	char key = ' ';

	frameCounter = 0;

	// In order to this part working on Windows go to Properties/Linker/AdditionalLibrary 
	// and add winmm.lib
	startTime = timeGetTime();

	while (key != 'q')
	{
		while (!GetInput(&key)) {
			TimerUpdate();
		}
		cout << "Preset button is: " << key << endl;
	}
	cout << frameCounter / ((timeGetTime() - startTime) / 1000) << " FPS" << endl;
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

void BaseEngine::TimerUpdate() {
	double currentTime = timeGetTime() - startTime;
	if (currentTime < GAME_SPEED)
		return;
	
	frameCounter++;
	lastTime = timeGetTime();
}