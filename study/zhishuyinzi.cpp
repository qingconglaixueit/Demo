#include <iostream>
#include <cmath>

using namespace std;

bool iszhishu(long n)
{
	int flag = true;
	for(int i = 2;i<sqrt(n);i++)
	{
		if(n%i == 0)
		{
			flag = false;
		}
	}
	return flag;
}

int main()
{
	long n;
	while(cin>>n)
	{	
		while(n!=1)
		{
			if(iszhishu(n))
			{
				cout<<n<<" ";
				break;
			}
			for(int i = 2;i<=n;i++)
			{
				if(n%i == 0)
				{
					n = n/i;
					cout<<i<<" ";
					break;
				}
			}
		}
		cout<<endl;
	}



	return 0;
}
