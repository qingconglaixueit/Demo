#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> vec;
	vec.push_back(vector<int>());
	vec.back().push_back(1);
	cout<<vec[0][0]<<endl;

	vec.push_back(vector<int>());
	vec.back().push_back(1);
	cout<<vec[1][0]<<endl;

	return 0;
}
