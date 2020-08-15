#include <iostream>

using namespace std;

int main()
{

	int a[]={1,4,2,5,3,4};
	int len = sizeof(a)/a[0];
	for(int i = 0;i<len;i++)
	{
		while(a[i] != i)
		{
			if(a[a[i]] == a[i])	
			{
				cout<<"have chongfu --- chongfu zhi=="<<a[i]<<endl;
				return 0;
			}
			int tmp = a[a[i]];
			a[a[i]] = a[i];
			a[i] = tmp;
		}
	}
	cout<<"no chongfu "<<endl;



	return 0;
}
