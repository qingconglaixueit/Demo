#include <iostream>
#include <string>

using namespace std;

template<class T1,class T2>
class person;

template<class T1,class T2>
void printinfo2(person<T1,T2> p)
{
	cout<<"name -== "<<p.name<<"-- age == " <<p.age<<endl;
}

template<class T1,class T2>
class person
{

friend void printinfo(person<T1,T2> p)
{
	cout<<"name -== "<<p.name<<"-- age == " <<p.age<<endl;
}
friend void printinfo2<>(person<T1,T2> p);

public:
	person(T1 name,T2 age)
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;

};

int main()
{
	person<string,int> p("xiaozhu",10);
	printinfo2(p);
	return 0;
}

