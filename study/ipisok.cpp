#include <iostream>
#include <string>

using namespace std;

int main()
{
	char dot[3];
	int ip[4];
	while(cin>>ip[0]>>dot[0]>>ip[1]>>dot[1]>>ip[2]>>dot[2]>>ip[3])
	{
		if(dot[0]!= '.' || dot[1]!= '.'  || dot[2]!= '.'  )
		{
			cout<<"NO"<<endl;
			continue;
		}
		if( (ip[0]<0 || ip[0]>255) || (ip[1]<0 || ip[1]>255) || (ip[2]<0 || ip[2]>255) || (ip[3]<0 || ip[3]>255) )
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}



	

	}

	return 0;
}
