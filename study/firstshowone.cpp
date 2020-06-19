#include <iostream>
#include <string>

using namespace std;

int main(int agrc,char * argv[])
{
	string str;
	int i = 0;
	while(getline(cin,str))
	{
		int num[128] = {0};
		for(i=0;i<str.size();i++)
			num[str[i]] ++;
		for(i=0;i<str.size();i++)
		{
			if(num[str[i]] == 1)
			{
				break;
			}
		}
		if(i==str.size())
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<str[i]<<endl;
		}
	}




	return 0;

}
