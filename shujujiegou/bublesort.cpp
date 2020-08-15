#include <iostream>

using namespace std;

void bublesort(int *a,int len)
{
	for(int i = 0;i<len-1;i++)
	{
		for(int j = 0;j<len-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	return ;
}

int main()
{
	int a[]={4,2,5,7,8,3,8,0,4,6,8,2,1};
	int len = sizeof(a)/a[0];
	cout<<"befor bublesort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	bublesort(a,len);
	cout<<"after bublesort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
