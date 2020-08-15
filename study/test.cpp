#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> v;
	v.push_back({1,2});
	v.push_back({3,2});
	v.push_back({1,4});
	v.push_back({2,6});
	v.push_back({1,8});

	for(auto i:v)
		cout<<i[0]<<"--"<<i[1]<<endl;








	return 0;
}
