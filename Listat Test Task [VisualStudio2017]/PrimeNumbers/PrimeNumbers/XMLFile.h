#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "XMLNode.h"

class XMLFile
{
protected:
	std::fstream file;
	std::string filename;
	XMLNode *root = nullptr;

	void DeleteTree(XMLNode *node);
public:
	XMLFile(std::string filename);
	~XMLFile();

	virtual bool Open() = 0;
	void Close();
};