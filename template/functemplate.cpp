#include <iostream>
#include <string>
#include <string.h>

using namespace std;

template<typename T>
void myswap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


template<typename T>
void selectsort(T & a,int len)
{
	for(int i = 0;i<len;i++)
	{
		int max = i;
		for(int j = i+1;j<len;j++)
		{
			if(a[max] > a[j])
				max = j;
		}
		if(max != i)
			myswap(a[max],a[i]);
	}
}


int myadd(int a,int b)
{
	return a+b;
}

template<typename T>
T myadd2(T a,T b)
{
	return a+b;
}

int main()
{
	int a[5]={1,4,2,5,3};
	selectsort(a,5);
	for(int i = 0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	char b[]="ajksd";
	selectsort(b,strlen(b));
	cout<<b<<endl;

	cout<<myadd(10,'c')<<endl;
	cout<<myadd2<int>(10,'c')<<endl;

	return 0;
}

