#include <iostream>
#include <vector>

using namespace std;

class person
{

public:
	person(string name,int age):name(name),age(age){}

	string name;
	int age;

};

int main()
{
	#if 0
	vector<int> vec = {1,2,3,4,5,6,8};
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++) cout<<*it<<" "; #endif #if 0
	person p1("xiaozhu",10);
	person p2("xiaozhu2",10);
	person p3("xiaozhu3",10);

	vector<person *> vec;
	vec.push_back(&p1);
	vec.push_back(&p2);
	vec.push_back(&p3);
	for(auto a : vec)
		cout<<a->name<<" ";
	cout<<endl;
	#endif


	vector<vector<int>> vec = {
		{1,2,3,4},
		{2,3,4,5},
		{3,4,5,6},
		{4,5,6,7}
	};

	for(vector<vector<int>>::iterator it = vec.begin();it !=vec.end();it++)
	{
		for(vector<int>::iterator vit = (*it).begin();vit != (*it).end();vit++)
		{
			cout<<*vit<<" ";
		}
		cout<<endl;
	}


	#if 0
	//auto 是返回尖括号里面的类型
	for(auto a : vec)
	{
		for(auto b : a)
			cout<<b<<" ";
		cout<<endl;
	}
	#endif 


	return 0;
}
