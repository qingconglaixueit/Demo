#include <iostream>

using namespace std;

int getres(int a,int b)
{
	while(a%b)
	{
		cout<<"a%b=="<<a<<"%"<<b<<endl;
		int tmp = a;
		a = b;
		cout<<"tmp%b=="<<tmp<<"%"<<b<<endl;
		b = tmp%b;
	}
	return b;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{

		cout<<a*b/getres(a,b)<<endl;
	}



	return 0;
}
