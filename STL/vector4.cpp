#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	
	vec.insert(vec.begin(),1);
	vec.insert(vec.begin()+1,2);

	for(auto a : vec)
		cout<<a<<" ";
	cout<<endl;

	vec.erase(vec.begin()+1);
	for(auto a : vec)
		cout<<a<<" ";
	cout<<endl;
	
	return 0;
}
