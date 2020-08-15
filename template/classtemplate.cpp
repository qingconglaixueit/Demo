#include <iostream>
#include <string>

using namespace std;

template <class namet,class aget>
class person
{
public:
	person(namet name,aget age):name(name),age(age){}

	namet name;
	aget age;
};

int main()
{
	person<string,int>("xiaozhu",20);
	return 0;
}

