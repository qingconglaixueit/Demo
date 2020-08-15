#include <iostream>

using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{	
		int res = 0;
		while(num > 0)
		{
			cout<<"num == "<<num<<endl;
			if(num%2) res ++;
			num = num/2;	
		}
		cout<<res<<endl;
	}




	return 0;
}
