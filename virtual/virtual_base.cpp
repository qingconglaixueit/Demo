#include <iostream>

using namespace std;

class base
{
public:
	int a;
	void show()
	{
		cout<<a<<endl;
	}
};

class A:virtual public base
{
public:

};

class B:virtual public base
{
public:

};

class C:public A,public B
{
public:
};

int main()
{
	C c;
	c.a = 1;
	c.show();

	return 0;
}
