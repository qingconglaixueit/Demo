#include <iostream>
#include <string>

using namespace std;


bool isMatch(const char * pattern,const char * str)
{
	//若pattern 和 str 都到达来结尾，则比较完毕，返回true
	if( (*pattern == '\0' && *str == '\0') || (*pattern == '*' && *(pattern+1) == '\0' && *str == '\0') )
		return true;
	//若结尾的位置，一个已结束，另外一个
	if( *pattern == '\0' || *str == '\0')
		return false;

	if(*pattern == '?')
	{
		return isMatch(pattern+1,str+1);
	}
	else if(*pattern == '*')
	{
		return isMatch(pattern+1,str) || isMatch(pattern+ 1,str+1) || isMatch(pattern,str+1);
	}
	else
	{
		if(*pattern == *str)
			return isMatch(pattern+1,str+1);
	}

	return false;
}


int main(int argc,char * agrv[])
{	
	string pattern,str;

	while(cin>>pattern>>str)
	{
		//cout<<pattern<<"--"<<str<<endl;
		bool ret = isMatch(pattern.c_str(),str.c_str());
		if(ret)	
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	}
	return 0;
}
