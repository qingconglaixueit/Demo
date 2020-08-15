#include <stdio.h>
#include <stdlib.h>

void mergecarry(int *a,int m,int *b,int n,int *c)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while(i!=m && j!=n)
	{
		if(a[i] > b[j])
			c[k++] = b[j++];
		else
			c[k++] = a[i++];
	}
	
	if(i == m)
	{
		while(j != n)
			c[k++] = b[j++];
	}
	else
	{
		while(i != m)
			c[k++] = a[i++];
	}
}

int main()
{
	int a[6] = {1,4,5,6,8,9};
	int b[7] = {1,2,4,5,6,7,8};
	int c[13] ={0};
	int i = 0;	
	mergecarry(a,6,b,7,c);

	for(i = 0;i<13;i++)
		printf("%d ",c[i]);
	printf("\n");
	return 0;
}
