#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool isPalindrome(int x){
    char str[256] = {0};
	int len = 0;
	char *tmp = NULL;
	int i = 0;

    if(x < 10 && x>=0)
        return 1;
    if(x %10 == 0 || x < 0 )
        return 0;
    sprintf(str,"%d",x);
	len  = strlen(str);
    tmp = (char *)malloc(sizeof(len));
	
	for(i = 0;i<len;i++)
	{
		tmp[i] = str[len -i -1];
	}
	for(i=0;i<len;i++)
	{
		if(str[i] != tmp[i])
			break;
	}
    printf(" i == %d\n",i);
    printf(" len == %d\n",len);
	if(i == len)
		return 1;
	else
		return 0;
}

int main(int argc,char *argv[])
{

	string str="123214";
	cout<<""+str[2]<<endl;
	
	return 0;
}
