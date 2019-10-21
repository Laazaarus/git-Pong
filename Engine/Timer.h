#pragma once
#include <chrono>
class Timer
{
public:
	Timer();
	float checkTime();
private:
	std::chrono::steady_clock::time_point last;
};