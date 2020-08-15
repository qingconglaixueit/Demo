#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector<vector<int>> vec;
	//vec.push_back({1,2});
	vector<int> a = {1,2};
	vec.push_back(a);
	cout<<vec[0][0]<<"--"<<vec[0][1]<<endl;


	return 0;
}
