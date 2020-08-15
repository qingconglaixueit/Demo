#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> dns(4,0);
	char ch;
    while(cin>>dns[0]>>ch>>dns[1]>>ch>>dns[2]>>ch>>dns[3])
	{
		cout<<dns[0]<<"."<<dns[1]<<"."<<dns[2]<<"."<<dns[0]<<endl;
		
		vector<int> ip1(4,0);
		vector<int> result1(4,0);
		vector<int> ip2(4,0);
		vector<int> result2(4,0);

		cin>>ip1[0]>>ch>>ip1[1]>>ch>>ip1[2]>>ch>>ip1[3];
		cin>>ip2[0]>>ch>>ip2[1]>>ch>>ip2[2]>>ch>>ip2[3];
		
		for(int i=0;i<4;i++)
			result1[i] = ip1[i] & dns[i];

		for(int i=0;i<4;i++)
			result2[i] = ip2[i] & dns[i];
		
		int flag = 1;
		for(int i=0;i<4;i++)
		{
			if(result1[i] != result2[i])
			{
				flag = 0;
				break;
			}
		}
		
		if(flag)	cout<<"1"<<endl;
		else		cout<<"0"<<endl;

		
		

		dns.clear();
	}
    
    
    
    
    
    
    return 0;
}
