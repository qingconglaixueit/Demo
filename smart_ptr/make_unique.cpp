#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct person{

	~person()
	{
		cout<<"~person"<<endl;
	}

	string str;

};

int main()
{
//使用make_unique方法，可以快速的创建unique_ptr指针
	auto ptr = make_unique<person>();
	ptr->str = "hello world";
























	return 0;
}
