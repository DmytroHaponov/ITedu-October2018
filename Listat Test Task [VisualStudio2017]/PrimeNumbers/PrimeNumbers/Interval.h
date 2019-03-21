#pragma once

#include <list>
#include <set>

#include <thread>
#include <mutex>

#include <cmath>

class Interval
{
private:
	int begin;
	int end;
	std::thread *current_thread = nullptr;
public:
	Interval(int begin, int end);
	~Interval();

	int GetBeginInterval();
	int GetEndInterval();
	std::thread *GetThread();

	void FindPrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex);
	void AsyncFindPrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex);
};