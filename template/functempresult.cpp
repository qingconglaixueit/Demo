#include <iostream>
#include <string>

using namespace std;


void myprint(int a,int b)
{
	cout<<"normal func"<<endl;
}

template<typename T>
void myprint(T a,T b)
{
	cout<<"template func"<<endl;
}

template<typename T>
void myprint(T a,T b,T c)
{
	cout<<"chongzai template func"<<endl;
}


int main()
{
	myprint(10,20);
	myprint<>(10,20);
	myprint(10,20,30);
	myprint('a','b');

	return 0;
}

