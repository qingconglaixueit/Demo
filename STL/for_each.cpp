#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int printinfo(int x)
{
	return x+10;
}

class myp
{
public:
	int operator()(int x)
	{
		return x+1;
	}	
};

int main()
{
	
	vector<int> vec;
	for(int i = 0;i<10;i++)
		vec.push_back(i);
	
	auto p = [](const int &n){cout<<n<<" ";};
	for_each(vec.begin(),vec.end(),p);
	cout<<endl;

	vector<int> v2(vec.size(),0);
	transform(vec.begin(),vec.end(),v2.begin(),myp());
	for_each(v2.begin(),v2.end(),p);
	cout<<endl;


	return 0;
}

