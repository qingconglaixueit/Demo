#include <iostream>

using namespace std;

class father
{
public:
	int a;
	virtual void f()
	{

	}
};

class child : public father
{
public:
	int b;
};

void func(father *ptr)
{
	child * cc = dynamic_cast<child *>(ptr);
	if(cc)
	{
		cout<<"success"<<endl;
		cout<<"a:"<<cc->a<<endl;
		cout<<"b:"<<cc->b<<endl;
	}else
	{

		cout<<"fail"<<endl;
		cout<<"a:"<<ptr->a<<endl;
	}
}

int main()
{
	
	father f;
	f.a = 1;
	
	child c;
	c.a = 10;
	c.b = 100;
	
	func(&f);
	func(&c);

	return 0;
}
