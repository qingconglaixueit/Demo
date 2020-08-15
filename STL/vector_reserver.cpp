#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	vec.reserve(100000);
	int * p = NULL;
	int num = 0;
	for(int i= 0 ;i<100000;i++)
	{
		vec.push_back(i);
		if(p != &vec[0])
		{
			p = &vec[0];
			num++;
		}
	}
	cout<<"num == " << num<<endl;

	return 0;
}
