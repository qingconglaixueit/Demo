#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class person
{
public:
	person(string name,int age):name(name),age(age){}

	bool operator==(const person & other)
	{
		if(this->name == other.name && this->age == other.age)
			return true;
		return false;
	}

	string name;
	int age;
	

};

int main()
{
	vector<person> vec;
	vec.push_back(person("A",20));
	vec.push_back(person("B",20));
	vec.push_back(person("B",20));
	vec.push_back(person("D",50));

	vector<person>::iterator it = adjacent_find(vec.begin(),vec.end());
	if(it != vec.end())
		cout<<it->name<<endl;
	else
		cout<<"adjacent_find null"<<endl;

	return 0;
	
}
