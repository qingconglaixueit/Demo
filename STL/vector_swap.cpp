#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);

	vector<int> vec2;
	vec2.push_back(2);
	vec2.push_back(2);
	vec2.push_back(2);
	vec2.push_back(2);
	
	vec.swap(vec2);
	for(auto a : vec)
		cout<<a<<" ";
	cout<<endl;
	
	vector<int> vec3;
	for(int i = 0;i<1000;i++)
		vec3.push_back(i);
	vec3.resize(3);
	cout<<"capa == "<<vec3.capacity()<<endl;
	cout<<"size == "<<vec3.size()<<endl;

	cout<<"shou suo dui xiang "<<endl;
	vector<int>(vec3).swap(vec3);
	cout<<"capa == "<<vec3.capacity()<<endl;
	cout<<"size == "<<vec3.size()<<endl;



	return 0;
}
