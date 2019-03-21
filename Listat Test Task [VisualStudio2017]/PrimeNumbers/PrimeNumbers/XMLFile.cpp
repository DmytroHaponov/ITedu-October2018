#include "XMLFile.h"

XMLFile::XMLFile(std::string filename) :
	filename(filename)
{
}

XMLFile::~XMLFile()
{
	if (root)
	{
		delete(root);
	}
}

void XMLFile::Close()
{
	if (file.is_open())
	{
		file.close();
	}
}