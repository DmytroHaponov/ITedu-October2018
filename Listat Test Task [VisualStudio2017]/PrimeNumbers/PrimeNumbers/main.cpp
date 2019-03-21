#include "XMLReader.h"
#include "XMLWriter.h"

int main()
{
	std::set<int>			number_list;
	std::mutex				number_list_mutex;

	std::list<Interval *>	interval_list;

	// Create and open Reader
	// If you want run program from Visual Studio you should set absolute path like
	//			"C:\\Users\\User\\Desktop\\PrimeNumbers\\Debug\\source.xml"
	// Now program will working if you run exe file(not from Visual Studio)
	XMLReader reader("source.xml");
	if (!(reader.Open()))
	{
		std::cout << "No file source.xml! Maybe you run program from Visual Studio without set absolute path! Please read comments!" << std::endl;
		system("pause");
		return 0;
	}

	// Read and parse file to xml-tree
	reader.Parse();

	// Get intervals from xml-tree and save to interval_list
	reader.GetIntervals(&interval_list);

	// Async start finding prime numbers
	for (std::list<Interval*>::iterator iter = interval_list.begin(); iter != interval_list.end(); iter++)
	{
		(*iter)->AsyncFindPrimeNumbers(&number_list, &number_list_mutex);
	}

	// Wait ends all secondary threads
	for (std::list<Interval*>::iterator iter = interval_list.begin(); iter != interval_list.end(); iter++)
	{
		(*iter)->GetThread()->join();
	}

	// Write to file
	XMLWriter writer("destination.xml");
	writer.Open();

	writer.SavePrimeNumbers(&number_list, &number_list_mutex);

	// Close input and output streams
	reader.Close();
	writer.Close();

	// Clean memory
	while (interval_list.size() > 0)
	{
		Interval *inter = interval_list.front();
		delete inter;
		interval_list.pop_front();
	}

	return 0;
}