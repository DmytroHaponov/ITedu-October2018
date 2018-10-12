#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <chrono>
#include <vector>
#include <functional>
//using namespace std;

int main()
{
const int m5000=5000;
//---------------------
//creating new txt file
//---------------------
	std::ofstream to_file("r_names.txt", std::ios_base::trunc);
//checking existance of pointer to .txt
if(!to_file)
	{ std::cout << "Error - file not available.\n"; return 1; }
//checking access to iostream
if(to_file.is_open ())
	{
	for(int i=0; i<m5000; ++i)
		{
		std::uniform_int_distribution<int> dist_1(4, 9);
		std::random_device rd;
		auto len=dist_1(rd);
//		std::cout<< len <<'\n';
		std::string s;
		std::mt19937_64 mt { std::random_device {} () };
		std::uniform_int_distribution<char> dist { 'A', 'Z' };
		std::generate_n(back_inserter(s), len, [&]() { return dist(mt); });
		if(to_file.fail ()) break;
		to_file<<s<<' ';
		}
//-----------------------------------------------------
//insert letter instead whitespace in the last position
//-----------------------------------------------------
	long pos=to_file.tellp ();
	to_file.seekp (pos-1);
	std::mt19937_64 mt { std::random_device {} () };
	std::uniform_int_distribution<char> dist { 'A', 'Z' };
	to_file.put (dist(mt));
	}
to_file.close ();




//for working with array of strings
std::vector<std::string> temp_v;
std::string str_tmp;
//-----------------------------------------------------
//reading random names to temporary array
//-----------------------------------------------------
std::ifstream from_file("r_names.txt");
if(!from_file)
	{ std::cout << "Error - file not available.\n"; return 1; }
//checking access to iostream
if(from_file.is_open ())
	{
		while (!from_file.eof ())
			{
				getline (from_file, str_tmp, ' ');
				temp_v.push_back (str_tmp);
			}
	}
from_file.close ();


std::vector<int> ww; //temporary array for count weight of words
int rez=0;	//total weight
//std::hash<std::string> str_hash;


//-----------------------------------------------------
//sort array and record sorted names to s_names.txt
//-----------------------------------------------------
std::sort(temp_v.begin (), temp_v.end ());

{
//creating new sorded txt file
	std::ofstream to_sfile("s_names.txt", std::ios_base::trunc);
//checking existance of pointer to .txt
if(!to_sfile)
	{ std::cout << "Error - file not available.\n"; return 1; }
//checking access to iostream
if(to_sfile.is_open ())
	{
for(auto j:temp_v)	{	to_sfile<<j<<' ';	}
	}
to_sfile.close ();
}

//count weight of each word
for(auto i:temp_v)
	{
		int ww1=0;
/*std::cout<<"len= "<<i.size ()<< " " <<i<<'\n';
		std::cout<<"hash= "<< str_hash(i)<<'\n';*/
		for(auto k:i)
			{
				ww1+=k-64;
				//std::cout<<(k-64)<< "->" << ww1<<' ';
			}
		//std::cout<<'\n';
ww.push_back (ww1);
	}

//count total weight
for(auto l:ww)
	{
		rez+=l;


	}
	std::cout<<rez<<'\n';

return 0;
}


