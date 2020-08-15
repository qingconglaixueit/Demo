#include <iostream>

using namespace std;

int main()
{
	string str;
	int len;
	while(cin>>str>>len)
	{
		int index = 0;
		int max = 0;
		for(int i = 0;i<str.size()-len;i++)
		{
			int count = 0;
			for(int j = i;j<i+len;j++)
			{
				if(str[j] == 'C' || str[j] == 'G')
				{
					count++;
				}
			}
			if(count > max)
			{
				max = count;
				index = i;
			}
		}
		cout<<str.substr(index,len);

	}



	return 0;
}
