#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
		if(str1.size() % 8 != 0) str1 = str1 + "00000000";
		if(str2.size() % 8 != 0) str2 = str2 + "00000000";
		
		while(str1.size()>=8)
		{
			cout<<str1.substr(0,8)<<endl;
			str1 = str1.substr(8);
		}
		while(str2.size()>=8)
		{
			cout<<str2.substr(0,8)<<endl;
			str2 = str2.substr(8);
		}
	}








	return 0;
}
