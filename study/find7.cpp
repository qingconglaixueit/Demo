#include <iostream>

using namespace std;

int main()
{
	int n ;
	while(cin>>n)
	{
		int res = 0;
		while(n>6)
		{	
			if(n%7 == 0 || n%10 == 7 || (n%100)/10 == 7 || (n%1000)/100 == 7 || (n%10000)/1000==7 )
			res++;
			n--;
		}
		cout<<res<<endl;

	}



	return 0;
}
