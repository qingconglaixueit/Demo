#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> vec2;
	vec2.push_back(3);
	vec2.push_back(3);
	vec2.push_back(4);

	vector<int> vec;
	vec.resize(vec2.size());
	
	copy(vec2.begin(),vec2.end(),vec.begin();
	
	for(auto a : vec)
		cout<<a<<" ";
	cout<<endl;
	
	return 0;
}
