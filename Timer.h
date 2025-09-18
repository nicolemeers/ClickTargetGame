#include <chrono>
#include <cstdlib>
#pragma once
class Timer
{
public:
	void startTime();

	bool checkTime();
	void setAvailableTimeToClick();


	double getClickTime() const;
private:
	std::chrono::high_resolution_clock::time_point m_startTime;
	std::chrono::high_resolution_clock::time_point m_endTime;
	double m_availableTimeToClick;
	std::chrono::high_resolution_clock::time_point m_recordedClickTime;
};

