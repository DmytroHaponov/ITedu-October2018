#include <iostream>
#include <forward_list>

using namespace std;

int main()
	{
forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};

for (int &a:flst)
	{
		cout<<a<< " ";
	}
		cout<<endl;

flst.reverse ();

for (int &r:flst)
	{
		cout<<r<< " ";
	}
		cout<<endl;

		return 0;
	}
