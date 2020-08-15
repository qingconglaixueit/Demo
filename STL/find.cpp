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
	vec.push_back(person("B",30));
	vec.push_back(person("C",40));
	vec.push_back(person("D",50));
	
	person p("C",40);

	vector<person>::iterator it = find(vec.begin(),vec.end(),p);
	if(it != vec.end())
		cout<<"you are find "<<it->name<<endl;
	else
		cout<<"not find"<<endl;

	return 0;
}
