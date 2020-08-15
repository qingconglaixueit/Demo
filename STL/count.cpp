#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);

	cout<<count(vec.begin(),vec.end(),1)<<endl;
	return 0;
}
