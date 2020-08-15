#include <iostream>

using namespace std;

int main()
{
	float num;
	while(cin>>num)
	{
		if(num <= 0)
		{
			cout<<0<<endl;
			return 0;
		}
		
		cout<<int(num+0.5)<<endl;



	}

	return 0;
}
