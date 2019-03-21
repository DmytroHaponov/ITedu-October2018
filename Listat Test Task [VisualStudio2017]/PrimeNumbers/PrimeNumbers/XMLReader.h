#pragma once

#include <list>
#include <thread>
#include <mutex>

#include "XMLFile.h"
#include "Interval.h"

class XMLReader :
	public XMLFile
{
public:
	XMLReader(std::string filename);
	~XMLReader();

	bool Open();
	void Parse();
	void GetIntervals(std::list<Interval *>	*interval_list);
};