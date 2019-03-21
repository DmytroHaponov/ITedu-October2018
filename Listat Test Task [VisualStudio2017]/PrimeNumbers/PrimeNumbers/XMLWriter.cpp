#include "XMLWriter.h"

XMLWriter::XMLWriter(std::string filename) :
	XMLFile(filename)
{
}

XMLWriter::~XMLWriter()
{
}

bool XMLWriter::Open()
{
	file.open(filename, std::ios::out);
	return file.is_open();
}

void XMLWriter::SavePrimeNumbers(std::set<int> *number_list, std::mutex *number_list_mutex)
{
	// Creating string with prime numbers
	std::string val;
	std::lock_guard<std::mutex> lck(*number_list_mutex);
	for (std::set<int>::iterator iter = (*number_list).begin(); iter != (*number_list).end(); iter++)
	{
		val += std::to_string(*iter) + " ";
	}

	//Save prime numbers into xml-file
	file << "<root>\n\t<primes> " << val << "</primes>\n</root>";
}