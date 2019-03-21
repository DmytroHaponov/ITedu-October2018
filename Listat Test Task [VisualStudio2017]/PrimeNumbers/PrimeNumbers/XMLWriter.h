#pragma once

#include <set>
#include <mutex>

#include "XMLFile.h"

class XMLWriter :
	public XMLFile
{
public:
	XMLWriter(std::string filename);
	~XMLWriter();

	bool Open();
	void SavePrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex);
};