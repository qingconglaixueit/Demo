
#include<iostream>
using namespace std;
int main()
{	
	int n ;
	while(cin>>n)
	{
		int a[10] = {0};
		int res = 0;
		if(n == 0)	res = 0;
		else
		{
			while(n)
			{
				if(a[n%10] == 0)
				{
					a[n%10] ++;
					res = res*10 + n%10;
				}
				n/=10;
			}
		}
		cout<<res<<endl;

	}

	return 0;
}
