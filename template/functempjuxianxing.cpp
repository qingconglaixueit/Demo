#include <iostream>
#include <string>

using namespace std;

class person
{

public:
	person(string name,int age):name(name),age(age){}

	string name;
	int age;
	#if 0
	bool operator==(person &other)
	{
		if(name == other.name && age == other.age)
			return true;
		return false;
	}
	#endif

};

template <typename T>
bool test(T & p1,T& p2)
{
	if(p1 == p2)	
		return true;
	return false;
	
}

template<> bool test(person & p1,person & p2)
{
	if(p1.name == p2.name && p1.age == p2.age)	
		return true;
	return false;
	
}

int main()
{

	person p1("xiaozhu",10);
	person p2("xiaozhu",10);
	bool ret = test(p1,p2);
	if(ret) cout<<"p1 == p2"<<endl;
	else 	cout<<"p1 != p2"<<endl;



	return 0;
}

