#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	for(int i = 0;i<3;i++)
		vec.push_back(i);
	vec.resize(2);
	cout<<"capacity == "<<vec.capacity()<<endl;
	cout<<"size == "<<vec.size()<<endl;

	for(int i = 0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;

	return 0;
}
