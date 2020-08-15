#include <iostream>
#include <list>

using namespace std;

int main()
{
	 list<int> l;
	l.push_back(10);
	l.push_back(13);
	l.push_back(14);
	l.push_back(15);
	l.push_back(10);
	l.remove(10);
	for(auto a : l)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}
