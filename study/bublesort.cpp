#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string str;
	while(cin>>str)
	{
		int tmp[128] = {0};
		for(int i = 0;i<str.size();i++)
			tmp[str[i]] ++;
		for(int i =0;i<128;i++)
			for(int j = 0; j<tmp[i];j++)
				cout<<(char)i;
		cout<<endl;
	
	}


	return 0;
}
