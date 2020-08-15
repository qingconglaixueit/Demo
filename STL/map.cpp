#include <iostream>
#include <map>
#include <time.h>

using namespace std;

void printinfo(const map<int,int> m)
{

	for(auto a : m)
		cout<<"first -- "<<a.first<<"---second--"<<a.second<<endl;
}

int main()
{
	map<int,int> m;
	m.insert(pair<int,int>(10,20));
	m.insert(make_pair(14,20));
	m.insert(map<int,int>::value_type(12,20));
	
	printinfo(m);

	cout<<"erase begin()"<<endl;
	m.erase(10);
	printinfo(m);
	

	srand((unsigned int) time(NULL));
	cout<<rand()%10+10<<endl;

	return 0;
}
