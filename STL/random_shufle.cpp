#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	vector<int> vec;
	for(int i = 0;i<10;i++)
		vec.push_back(i);
	
	random_shuffle(vec.begin()+2,vec.begin() +7);
	
	for(auto a : vec)
		cout<<a<<" "<<endl;
	cout<<endl;

	return 0;
}
