#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct person
{
	~person()
	{
		cout<<"~person"<<endl;
	}
	
	string str;

};

unique_ptr<person> test()
{
	return unique_ptr<person> (new person);
}

int main()
{
	//独占指针的是自己管理内存的，指针存在于栈空间，开辟的内存在堆空间，这里的堆空间是和智能指针绑定的，智能指针随着函数结束被销毁之前，智能指针会先去把堆里面的内存销毁
	//unique_ptr is ownership 
/*
	unique_ptr<person> p = test();
	p->str = "hello world";
	
	unique_ptr<person> p2 = move(p);
	if(!p)
	{
		cout<<"p == null" <<endl;
	}

	if(p2)
	{
		cout<<"p2 have ownership"<<endl;
		cout<<p2->str<<endl;
	}

	
	p2.reset(new person);
	if(p2->str.empty())
	{
		cout<<"str is null"<<endl;
	}
*/

	unique_ptr<person> p = test();
	p->str = "hello world";
	unique_ptr<person> p2 = move(p);























	return 0;
}
