#include "Timer.h"

Timer::Timer()
{
	start_time_point = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	Stop();
}

void Timer::Stop() {

	auto stop_time_point = std::chrono::high_resolution_clock::now();

	auto start_time = std::chrono::time_point_cast<std::chrono::seconds>(start_time_point).time_since_epoch().count();
	auto end_time = std::chrono::time_point_cast<std::chrono::seconds>(stop_time_point).time_since_epoch().count();

	auto duration	= end_time - start_time;	// miliseconds

	std::cout << "It took "<< duration << " second(s) to calculate it.\n";
};

