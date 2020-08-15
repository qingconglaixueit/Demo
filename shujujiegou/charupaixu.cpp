#include <iostream>

using namespace std;

void charusort(int *a,int len)
{
	for(int i = 1;i<len;i++)
	{
		int key = a[i];
		int j = i-1;
		while(j >= 0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	
	return ;
}

int main()
{
	int a[]={4,2,5,7,8,3,8,0,4,6,8,2,1};
	int len = sizeof(a)/a[0];
	cout<<"befor charupaixu()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	charusort(a,len);
	cout<<"after charupaixu()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
