#include "Timer.h"
using namespace std::chrono;
Timer::Timer()
{
	auto last = steady_clock::now();
}

float Timer::checkTime()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> timer = last - old;
	return timer.count();
}
