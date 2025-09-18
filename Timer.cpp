#include "Timer.h"

void Timer::startTime()
{
	m_startTime = std::chrono::high_resolution_clock::now();
}

bool Timer::checkTime()
{
	m_endTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> timePassed = m_endTime - m_startTime;

	if (timePassed.count() >= m_availableTimeToClick)
	{
		return true;
	}

	return false;
}

void Timer::setAvailableTimeToClick()
{
	m_availableTimeToClick = 1 + (rand() % ((6 - 1) + 1));
}

double Timer::getClickTime() const
{
	std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();
	return (curTime - m_startTime).count();
}
