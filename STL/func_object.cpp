#include <iostream>

using namespace std;

class myadd
{
public:
	int count;
	myadd()
	{
		this->count = 0;
	}
	int operator()(int a,int b)
	{
		this->count++;
		return a+b;
	}
};

void printresult(myadd & my,int a,int b)
{
	cout<<"result == "<<my(a,b)<<endl;
}

int main()
{

	myadd my;
	cout<<my(1,2)<<"-- count == "<<my.count<<endl;
	cout<<my(1,2)<<"-- count == "<<my.count<<endl;
	cout<<my(1,2)<<"-- count == "<<my.count<<endl;
	
	printresult(my,1,3);

	return 0;
}
