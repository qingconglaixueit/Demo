#include <iostream>

using namespace std;

void selectsort(int *a,int len)
{
	for(int i = 0;i<len-1;i++)
	{
		for(int j = i+1;j<len;j++)
		{
			if(a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return ;
}

int main()
{
	int a[]={4,2,5,7,8,3,8,0,4,6,8,2,1};
	int len = sizeof(a)/a[0];
	cout<<"befor selectsort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	selectsort(a,len);
	cout<<"after selectsort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
