#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class person
{

public:
	string name;
	int age;
	person(string name,int age):name(name),age(age){}

};

class mycp
{
public:
	bool operator()(const person & a,const person & b)
	{
		return a.age>b.age;
	}

};

int main()
{
	
	srand((unsigned int) time(NULL));
	
	#if 0
	vector<int> vec;
	vec.push_back(rand()%10 + 10);
	vec.push_back(rand()%10 + 10);
	vec.push_back(rand()%10 + 10);
	vec.push_back(rand()%10 + 10);
	vec.push_back(rand()%10 + 10);

	sort(vec.begin(),vec.end(),[](const int a,const int b){return a>b;});

	for(auto a : vec)
		cout<<a<<" ";
	cout<<endl;
	#endif

	vector<person> v2;
	v2.push_back(person("a",rand()%20+20));
	v2.push_back(person("m",rand()%20+20));
	v2.push_back(person("o",rand()%20+20));
	v2.push_back(person("p",rand()%20+20));
	v2.push_back(person("s",rand()%20+20));

	sort(v2.begin(),v2.end(),mycp());
	
	for(auto a : v2)
		cout<<a.name<<"--"<<a.age<<endl;

	return 0;
}
