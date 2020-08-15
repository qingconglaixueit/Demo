#include <iostream>
#include "myArray.hpp"
#include <string>

using namespace std;


class person
{
public:
	string name;
	int age;
public:
	person(){}
	person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
};
void printinfo(myArray<person> &arr)
{
	for(int i = 0;i<arr.getSize();i++)
		cout<<arr[i].name<<" "<<arr[i].age<<endl;
}

int main()
{
	{

		myArray<person> arr(5);
		person p1("xiazhu",1);
		person p2("xiazhu2",2);
		person p3("xiazhu3",3);
		person p4("xiazhu4",4);
		person p5("xiazhu5",5);
		arr.Mypush(p1);
		arr.Mypush(p2);
		arr.Mypush(p3);
		arr.Mypush(p4);
		arr.Mypush(p5);

		myArray<person> arr2 = arr;

		printinfo(arr2);
		cout<<"size == "<<arr.getSize()<<endl;
		cout<<"cap == "<<arr.getCap()<<endl;
		arr.mypop();
		cout<<"size == "<<arr.getSize()<<endl;
		
	}
	
	return 0;
}
