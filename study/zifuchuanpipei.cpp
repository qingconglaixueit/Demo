#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	string substr,str;
	while(cin>>substr>>str)
	{
		if(substr.size()>str.size()) {cout<<"false"<<endl;continue;}
		
		vector<bool> helper(26,false);
		bool flag = true;
		for(auto i : str)
		{
			helper[i - 'a'] = true;
		}
		for(auto i : substr)
		{
			if(!helper[i - 'a'])
			{
				flag = false;
				break;
			}
		}
		if(flag)	cout<<"true"<<endl;
		else 		cout<<"false"<<endl;
	}




	return 0;
}
