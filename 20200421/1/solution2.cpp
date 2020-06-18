#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int lengthofLongsubstring(string s)
	{
		int result = 0,start = 0,end = 0,length = 0;
		int size = s.size();
		while(end < size)
		{
			char tmpchar = s[end];
			for(int i = start;i<end;i++)
			{
				if(tmpchar == s[i])
				{
					start = i +1;
					length = end - start;
					break;
				}
			}
			end++;
			length++;
			result = max(result,length);
		}
		return result;
	}
};

int main(int argc,char *argv[])
{

	string s = "abcbdcafd";
	Solution ll;
	cout<<ll.lengthofLongsubstring(s)<<endl;

	
	return 0;
}
