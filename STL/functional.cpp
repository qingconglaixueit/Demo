#include <iostream>
#include <functional>

using namespace std;

void mynot(bool a,bool b,logical_and<bool> l)
{
	cout<<l(a,b)<<endl;;
}

int main()
{
	int a = 10;
	cout<<negate<int>()(a)<<endl;

	mynot(true,false,logical_and<bool>());


	return 0;
}
