#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int> vec2;
	for(int i=0;i<10;i++)
	{
		vec.push_back(i);
		vec2.push_back(i+10);
	}

	vector<int> target;
	target.resize(10);
	vector<int>::iterator iend = set_intersection(vec.begin(),vec.end(),vec2.begin(),vec2.end(),target.begin());

	
	for(vector<int>::iterator it = target.begin();it!=iend;it++)
		cout<<*it<<" ";
	cout<<endl;


	return 0;
}
