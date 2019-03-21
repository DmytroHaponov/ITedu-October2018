#include "Interval.h"

Interval::Interval(int begin, int end) :
	begin(begin),
	end(end)
{
	if (this->begin < 2)
	{
		this->begin = 2;
	}

	if (this->end < this->begin)
	{
		this->end = this->begin;
	}
}

Interval::~Interval()
{
	if (current_thread)
	{
		delete current_thread;
	}
}

int Interval::GetBeginInterval()
{
	return begin;
}

int Interval::GetEndInterval()
{
	return end;
}

std::thread* Interval::GetThread()
{
	return current_thread;
}

void Interval::FindPrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex)
{
	for (int cur_number = begin; cur_number <= end; cur_number++)
	{
		int sqrt_number = sqrt(cur_number);
		bool prime = true;
		for (int i = 2; i <= sqrt_number; i++)
		{
			if (cur_number % i == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			std::lock_guard<std::mutex> lck(*number_list_mutex);
			(*number_list).insert(cur_number);
		}
	}
}

void Interval::AsyncFindPrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex)
{
	// Create new thread for finding prime numbers
	current_thread = new std::thread(&Interval::FindPrimeNumbers, this, number_list, number_list_mutex);
}