#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

string isPalindrome(string s){
	int t = 0,max = 0;
	int size = s.size();
	for(int i = 0;i<size;i++)
	{	
		//长度为偶数的回文字符串
		if(s[i] == s[i+1])
		{
			int tmplen = 1;
			while((i - tmplen >= 0) && ((i+tmplen+1<= size -1) && (s[i-tmplen] == s[i+tmplen+1]))) 
				tmplen++;
			if(2 * tmplen > max)
			{
				max = 2* tmplen;
				t = i - tmplen + 1;
			}
		}
	}	
	for(int i = 0;i<size-1;i++)
	{	
		//长度为奇数的回文字符串
		if(s[i] == s[i+2])
		{
			int tmplen = 1;
			while((i - tmplen >= 0) && ((i+tmplen+2<= size -1) && (s[i-tmplen] == s[i+tmplen+2])) ) 
				tmplen++;
			if(2 * tmplen + 1 > max)
			{
				max = 2* tmplen +1;
				t = i - tmplen + 1;
			}
		}
	}	
	
	if(max == 0)
		return s.substr(0,1);
	else
		return s.substr(t,max);

}

int main(int argc,char *argv[])
{
	
	string s ;
	cin>>s;
	cout<<isPalindrome(s)<<endl;
	
	return 0;
}
