#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		int tmp[128] = {0};
		int res = 0;
		for(int i =0;i<str.size();i++)
		{
			if(tmp[str[i]] == 0)
			{
				tmp[str[i]] ++;
				res++;
			}
		}
		cout<<res<<endl;
	}




	return 0;
}
