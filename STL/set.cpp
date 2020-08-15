#include <iostream>
#include <set>

using namespace std;

class mycp
{
public:
	bool operator()(int a,int b)
	{
		return a>b;
	}
};

int main()
{
	
	#if 0
	set<int> s;
	pair<set<int>::iterator,bool> res = s.insert(19);
	cout<<*res.first<<endl;
	if(res.second)	cout<<"res is true"<<endl;;
	pair<set<int>::iterator,bool> res2 = s.insert(19);
	cout<<*res2.first<<endl;
	if(!res2.second)	cout<<"res2 is false"<<endl;;
	#endif 

	set<int,mycp> s;
	s.insert(15);
	s.insert(35);
	s.insert(45);
	s.insert(25);
	s.insert(65);
	s.insert(12);
	s.insert(15);
	s.insert(11);
	s.insert(10);
	for(auto a : s)
		cout<<a<<" ";
	cout<<endl;

	return 0;
}
