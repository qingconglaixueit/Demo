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

void test1(person<string,int> & p)
{
	cout<<"test 1 -- name== "<<p.name<<endl;
}
template <class namet,class aget>
void test2(person<namet,aget> & p)
{
	cout<<"test 2 -- name== "<<p.name<<endl;

}

template <class T>
void test3(T & p)
{

	cout<<"test 3 -- name== "<<p.name<<endl;
}

int main()
{
	person<string,int> p("xiaozhu",10);
	test1(p);
	test2(p);
	test3(p);
	return 0;
}

