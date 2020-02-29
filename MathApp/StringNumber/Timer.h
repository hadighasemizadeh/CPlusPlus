#ifndef _TIMER
#define _TIMER

#include <iostream>
#include <chrono>

class Timer
{
public:
	Timer();
	~Timer();
	void Stop();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time_point;
};

#endif // !_TIMER



