#include <iostream>

using namespace std;

typedef void (* func)();

void test(int i )
{
	cout<<"test -- "<<"2"<<endl;
}


int main()
{

	func f = reinterpret_cast<func>(test);
	f();

	volatile const int a = 1;
	int *b = const_cast<int *>(&a);
	*b = 3;
	cout<<"b == "<<*b<<endl;
	cout<<"a == "<<a<<endl;

	#if 0

	const int c = 10;
	int * p = &c; //is error
	*p = 3; 
	cout<<"*p == "<<*p<<endl;
	cout<<"c == "<<c<<endl;
	#endif
	

	return 0;
}

