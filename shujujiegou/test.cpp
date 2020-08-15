#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class test
{
public:
	test()
	{
		cout<<"woshi test"<<endl;
	}
};

int main()
{
	char str[]="hello";
	char *p = str;
	int n = 10;
	void *ptr= malloc(100);
	cout<<sizeof(str)<<endl;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(n)<<endl;
	cout<<sizeof(ptr)<<endl;
	return 0;
}
