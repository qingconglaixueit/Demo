#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		map<int ,int> m;
		while(n--)
		{
			int key,value;
			cin>>key>>value;
			if(!m[key])//
			{
				m[key] = value;
			}
			else
			{
				m[key]+=value;
			}
		}
		
		for(map<int,int>::iterator it=m.begin();it != m.end();it++)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
	}




	return 0;
}
