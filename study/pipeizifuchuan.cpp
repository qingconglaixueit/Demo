//youxu de shihou
#include <iostream>
#include <string>

using namespace std;


int main()
{

	string substr;
	string str;
	while(cin>>substr>>str)
	{
		if(substr.size()>str.size())
		{
			cout<<"false"<<endl;
			continue;
		}
		
		int i,j;
		for(i=0,j=0;i<str.size()&&substr.size();i++)
		{
			if(str[i] == substr[j])
			{
				j++;
			}
		}
		if(i<substr.size())
			cout<<"false"<<endl;
		else	
			cout<<"true"<<endl;
	}



	return 0;
}
