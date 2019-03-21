#include "pch.h"

#include "../PrimeNumbers/Interval.cpp"

#include "../PrimeNumbers/XMLNode.cpp"
#include "../PrimeNumbers/XMLFile.cpp"
#include "../PrimeNumbers/XMLReader.cpp"

class IntervalTest : public ::testing::Test
{
protected:
	IntervalTest() {}
	~IntervalTest() {}
};

TEST_F(IntervalTest, Interval_Async_50_to_60_Test)
{
	std::set<int> number_list;
	std::mutex number_list_mutex;
	Interval interval(50, 60);
	interval.AsyncFindPrimeNumbers(&number_list, &number_list_mutex);
	interval.GetThread()->join();
	EXPECT_EQ(number_list.size(), 2);
}

TEST_F(IntervalTest, Interval_100_to_110_Test)
{
	std::set<int> number_list;
	std::mutex number_list_mutex;
	Interval interval(100, 110);
	interval.FindPrimeNumbers(&number_list, &number_list_mutex);
	EXPECT_EQ(number_list.size(), 4);
}

TEST_F(IntervalTest, Interval_150_to_130_Test)
{
	std::set<int> number_list;
	std::mutex number_list_mutex;
	Interval interval(150, 130);
	interval.FindPrimeNumbers(&number_list, &number_list_mutex);
	EXPECT_EQ(number_list.size(), 0);
}

TEST_F(IntervalTest, Interval_151_to_120_Test)
{
	std::set<int> number_list;
	std::mutex number_list_mutex;
	Interval interval(151, 120);
	interval.FindPrimeNumbers(&number_list, &number_list_mutex);
	EXPECT_EQ(number_list.size(), 1);
}

TEST_F(IntervalTest, Interval_minus5_to_10_Test)
{
	std::set<int> number_list;
	std::mutex number_list_mutex;
	Interval interval(-5, 10);
	interval.FindPrimeNumbers(&number_list, &number_list_mutex);
	EXPECT_EQ(number_list.size(), 4);
}

class XMLReaderTest : public ::testing::Test
{
protected:
	XMLReaderTest() {}
	~XMLReaderTest() {}
};

TEST_F(XMLReaderTest, XMLReader_Parse_and_GetIntervals_Test)
{
	std::list<Interval *> interval_list;

	std::fstream file;
	file.open("unit_test_file.xml", std::ios::out);
	file << "<root>\n\t<intervals>\n\t\t<interval>\n\t\t\t<low> 100 </low>"
		"\n\t\t\t<high> 200 </high>\n\t\t</interval>\n\t\t<interval>"
		"\n\t\t\t<low> 500 </low>\n\t\t\t<high> 888 </high>\n\t\t</interval>"
		"\n\t</intervals>\n</root>";
	file.close();

	XMLReader reader("unit_test_file.xml");
	reader.Open();
	reader.Parse();
	reader.GetIntervals(&interval_list);
	reader.Close();

	EXPECT_EQ(interval_list.size(), 2);

	while (interval_list.size() > 0)
	{
		Interval *inter = interval_list.front();
		delete inter;
		interval_list.pop_front();
	}
}