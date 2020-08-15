#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char s[50];
	while(scanf("%s",s))
	{
		char *p ;
		p = strtok(s,"~");
		printf("%s---%s\n",p,s);
		p = strtok(NULL,"~");
		printf("%s---%s\n",p,s);
		inet_pton();
	}
	



}
