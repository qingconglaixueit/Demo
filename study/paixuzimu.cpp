#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{

	string str;
	vector<char> tmp;
	while(getline(cin,str))
	{	
		tmp.clear();
		int i,j;
		for(int i = 0;i<26;i<i++)
		{
			for(int j = 0;j<str.size();j++)
			{
				if(str[j] - 'a' == i || str[j] - 'A' == i )
				{
					tmp.push_back(str[j]);
				}
			}
		}
		for(i = 0, j = 0;i<str.size()&&j<tmp.size();i++)
		{
			if( (str[i] >='a' && str[i] <='z') || (str[i] >= 'A' && str[i] <='Z') )
			{
				cout<<tmp[j++];
			}
			else
			{
				cout<<str[i];
			}
		}
		while(i<str.size())
		{
			cout<<str[i++];
		}
		cout<<endl;
	}
	return 0;
}
